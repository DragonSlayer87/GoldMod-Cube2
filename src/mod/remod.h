#ifndef __REMOD_H__
#define __REMOD_H__

#include "game.h"
#include "varbox.h"


// worlio.cpp
extern void cutogz(char *s);

//command.cpp
extern void at(tagval *args, int numargs);
extern void concat(tagval *v, int n);
extern int unescapestring(char *dst, const char *src, const char *end);

// remod.cpp
typedef vector<char *> extensionslist;
extern bool addextension(const char *name);
char *conc(char **w, int n, bool space);
extern const extensionslist* getextensionslist();
extern char *authfile;

void reloadauth();

#define EXTENSION(name) bool __dummyext_##name = addextension(#name)

namespace server
{
    struct clientinfo;

    void filtercstext(char *str);
    bool checkpban(uint ip);
    bool checkaskidban(uint ip);
    void addban(int cn, char* actorname, int expire);
    void addpban(char *name, const char *reason);
    void addaskidban(char *name);
    void sendservmsgf(const char *fmt, ...);
}

namespace remod
{

    // mutemode
    enum  { MUTEMODE_NONE = 0, MUTEMODE_SPECS, MUTEMODE_PLAYERS, MUTEMODE_MASTERS, NUMMUTEMODE };
    typedef server::clientinfo clientinfo;

    // flood control
    enum { FLOOD_OTHER = 0, FLOOD_TEXT, FLOOD_SWITCHNAME, FLOOD_SWITCHMODEL, FLOOD_SWITCHTEAM, FLOOD_EDITVAR, NUMFLOOD };
    struct floodstate
    {
        int lastevent; // time of last flood event
        size_t strikes; // number of flood limit hits
        int lastwarning; // when last cubescript event was triggereg
        int floodlimit; // when event ignore will excedd
    };

    struct extstate
    {
        int suicides;
        bool muted;
        bool ghost;

        int lastmutetrigger;
        int lastghosttrigger;

        struct
        {
            int shotdamage;
            int damage;
        } guninfo[NUMGUNS];

        floodstate flood[NUMFLOOD];

        void reset();
        extstate() : suicides(0), muted(false), ghost(false), lastmutetrigger(0), lastghosttrigger(0) {}
    };

    struct extinfo
    {
        varbox vars;
    };

    extern char *mapdir;

    clientinfo* findbest(vector<clientinfo *> &a);
    bool playerexists(int *pcn);
    int parseplayer(const char *arg);
    bool ismaster(int *cn);
    bool isadmin(int *cn);
    bool isMaster(int *cn);
    bool isAdmin(int *cn);
    bool isspectator(int *cn);
    bool isediting(int *cn);
    void concatpstring(char** str, const char *piece);
    void concatpstring(char** str, int count,  ...);
    void loadbans();
    void loadaskidbans();
    void writebans();
    void writeaskidbans();
    bool loadents(const char *fname, vector<entity> &ents, uint *crc);
    bool writeents(const char *mapname, vector<entity> &ents, uint mapcrc);
    void setmaster(clientinfo *ci, int priv);
    void userauth(clientinfo *ci, int priv);
    int getwepaccuracy(int cn, int gun);
    bool checkmutemode(clientinfo *ci);
    void pausegame(bool val, clientinfo *ci = NULL);
    void checkresume();
    int getteamscore(const char *team);
    bool isteamsequalscore();
    void rename(int cn, const char* name);
    void sendmapto(int cn);
    bool iseditcommand(int type);
    void ghost(int cn, bool v);
    bool filterstring(char *dst, const char *src, bool newline, bool colour, bool whitespace, bool wsstrip, size_t len);
    template<size_t N> static inline bool filterstring(char (&dst)[N], const char *src, bool newline = true, bool colour = true, bool whitespace = true, bool wsstrip = false) { return filterstring(dst, src, newline, colour, whitespace, wsstrip, N-1); }
    size_t old_encodeutf8(uchar *dstbuf, size_t dstlen, const uchar *srcbuf, size_t srclen, size_t *carry);
    bool checkflood(clientinfo *ci, int type);
    void debugFlood();
    void addSuicide(clientinfo *ci); // count suicides
    
    // remodex functions imported to goldmod
    enum { GUN_FIST = 0, GUN_SG, GUN_CG, GUN_RL, GUN_RIFLE, GUN_GL, GUN_PISTOL, GUN_FIREBALL, GUN_ICEBALL, GUN_SLIMEBALL, GUN_BITE, GUN_BARREL, NUMGUNS };
    enum { A_BLUE, A_GREEN, A_YELLOW };
    int getammo(int wep);
    int getarmour();
    int getarmourtype();
    int gethealth();
    int getgunselect();
    int getdamagescale(int wep);
    
}
#endif
