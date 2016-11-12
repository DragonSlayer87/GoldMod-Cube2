#ifndef __GEOIPMOD_H__
#define __GEOIPMOD_H__

#include "fpsgame.h"
#include "GeoIP.h"
#include "GeoIPCity.h"

namespace remod
{
    namespace geoip {
    class GeoIPtool
    {
        private:
        GeoIP *gi;

        public:
        GeoIPtool()
        {
            gi = NULL;
        }

        ~GeoIPtool()
        {
            GeoIP_delete(gi);
        }

        bool loaddb(const char *dbname)
        {
            gi = GeoIP_open(dbname, GEOIP_STANDARD | GEOIP_MEMORY_CACHE);
            if(gi == NULL) return false;
                else return true;
        }

        bool loaded()
        {
            if(gi == NULL) return false; else return true;
        }

        const char *getcountry(char *host)
        {
            if(loaded())
            {
                const char *name;
                name = GeoIP_country_name_by_addr(gi, host);
                return (char*)name;
            } else
            {
                return NULL;
            }
        }
        
    };
        const char *getcity(const char *addr);
}}
#endif
