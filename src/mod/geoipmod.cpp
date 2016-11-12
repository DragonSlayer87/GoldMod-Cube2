/*
* remod:    geoip.cpp
* date:     2007/2016
* author:   degrave/BudSpencer/Terence
*
* GEOIP staff
*/



#ifdef GEOIP

#include "geoipmod.h"
#include "GeoIP.h"
#include "GeoIPCity.h"
#include "remod.h"

EXTENSION(GEOIP);

namespace remod
{
namespace geoip {
    static GeoIP *geoip = NULL;
    static GeoIP *geocity = NULL;
    
GeoIPtool *GIt = new GeoIPtool();

void loadgeoipcountry(char *dbname)
{
    const char *fname = findfile(dbname, "r"); // full path

    if(GIt->loaddb(fname))
    {
        conoutf(CON_ERROR, "Geoip: geocountry loaded (db: \"%s\")", fname);
    }
    else
    {
        conoutf(CON_ERROR, "Geoip: geocountry can not load (db: \"%s\")", fname);
    }
}


void loadgeoipcity(const char *path, bool isgeocity)
{
        GeoIP *gi;
        string dbtype;
        memset(dbtype, 0,sizeof(dbtype));
        const char *fname = findfile(path, "r"); // full path
        gi = GeoIP_open(fname, GEOIP_STANDARD | GEOIP_MEMORY_CACHE);
        GeoIP_set_charset(gi, GEOIP_CHARSET_UTF8); //utf8 names for utf8 -> cubescript
        
        if(isgeocity)
            strcpy(dbtype, "geocity");
        else
            strcpy(dbtype, "geoip");
        if(gi)
        {
            if(isgeocity)
                geocity = gi;
            else
                geoip = gi;
            conoutf(CON_ERROR, "Geoip: %s loaded (db: \"%s\")", dbtype, fname);
        }
        else
        {
            conoutf(CON_ERROR, "Geoip: can not load %s (db: \"%s\")", dbtype, fname);
        }
}
    
void getcountry(char *ip)
{
    const char *country = NULL;
    country = GIt->getcountry(ip);
    if(!country) country = ip;
    result(country);
}

const char *getcity( const char *addr )
{
    const char *city_name = NULL;

        GeoIPRecord *gir = GeoIP_record_by_addr( geocity, addr );
            if( gir != NULL ) 
        {
            char decoded_city[ MAXSTRLEN ];
            if ( gir->city ) 
            {
                decodeutf8( ( uchar* )decoded_city, MAXSTRLEN, ( uchar* )( gir->city ), MAXSTRLEN );
                city_name = newstring( decoded_city );
            }
    }

    return city_name;
}

/**
 * Return country for specified ip
 * @group server
 * @arg1 ip
 * @return country
 */
COMMAND(getcountry,"s");

// return city of specified ip
ICOMMAND(getcity, "s", (const char *addr),
        {
                const char *city = getcity(addr);
                result(city != NULL ? city : "Unknown City");
        });

// load city db
ICOMMAND(geocitydb, "s", (const char *path),
             {
                 loadgeoipcity(path, true);
             });

/**
 * Load geoip database from specified path
 * @group server
 * @arg1 /path/to/geoip.db
 */
COMMANDN(geodb, loadgeoipcountry, "s");


/**
 * Check if geoip is ready to use
 * @group server
 * @return 1 if is ready, otherwise 0
 */
ICOMMAND(isgeoip, "", (), intret(GIt->loaded()));

}
}
#endif
