# GoldMod-Cube2
Sauerbraten Server Modification


-------------------------------------------------------------------------------------------------------------

**General Information:**

Goldmod is an advanced server modification based on remod.

-------------------------------------------------------------------------------------------------------------

** Features:**

- irc-bot
- cubescript
- geoip country, geoip city, (geoip region is in work)
- about 80 commands
- anticheat (experimental)
- many useful scripts for server 
- scoreboard (sqlite3 + mysql)
- remote control
- user system (ip + password)
- cross platform (windows, linux, mac, bsd, arch, ...) 
- duel mode
- possibility to rename bots (ainame in server-init)

and very much more ...

-------------------------------------------------------------------------------------------------------------

**Command Reference:**

    Some useful Commands:
    _____________________

    #help - show server command list
    #setpriv - set privilege of specified player
    #stats <cn> (<TOTAL>) - show stats of specified player. You can also look at the total stats from the local database.
    #mastermode - change mastermode
    #votekick - vote to kick player (50+% required)
    #mapsucks - vote for intermission (50+% required)
    #adduser - adds new user to user system
    #deluser - delete a specified user from user system
    #setpriv - set players privilege to anything you want
    #comp - execute cubescript code in server
    
    ... and much more ... :D

-------------------------------------------------------------------------------------------------------------

**Work in Process:**

    enable-disable-commands-system ( currently not in work )
    MixModule ( currently not in work )
    Clantag Detection ( in work )

-------------------------------------------------------------------------------------------------------------

**Installation:**

    0. First you need to make sure, you've the following packages installed:
    
        - gcc (install all)
        - mingw-w64-zlib (for cross-compile)
        - mingw-w64-sqlite (for cross-compile)
        - zlib (for both)
        - sqlite (for both)
        - automake (for both)
        - autotools (for both)
        - libtool (for both)
        
    1. Download and unpack latest git repository (git clone https://www.github.com/budspencer1/GoldMod-Cube2.git)
    2. type in console: cd GoldMod-Cube2 (connects to GoldMod-Cube2 repository)
    3. type in console: cd src (connects you to src/ directory)
    (4. Clean it: make clean (cleans archive))
    5.0 Build it for Linux: make (compiles GoldMod)
    5.1 Build it for Windows: make -f Makefile.win32 (executes src/Makefile.win32 to cross-compile from linux to windows)
    6. Clean it again: make clean
    If you did it as i described, a "remod64" or a "GoldModServer.exe" in GoldMod-Cube2 main directory
    To run Linux Server: cd GoldMod-Cube2 
                         ./Goldmod64
    To run Windows Server: go to mod archive
                           start GoldModServer.exe
   
   PS: DON'T FORGET TO SETUP SERVER. Just rename "server-init.cfg.default" to "server-init.cfg" and setup server with that file. Save and close it and start server.

-------------------------------------------------------------------------------------------------------------

**Contact:**

    E-Mail: buddymod.cube2@gmail.com
    IRC: Server: irc.gamesurge.com 6667 | Channel: #buds-servers, #novi, #sauercom and #impressivesquad ---> Names: BudSpencer
    Ingame: Names: /BudSpencer, Archaeopteryx, Cocoz

-------------------------------------------------------------------------------------------------------------

**Bug Reports:**

If you suspect any bugs and problems, likes and dislikes message me on IRC, E-Mail or talk with me ingame, I'm always listening. New Ideas for some features are desired ;), but no insulting about anything, I don't waste time with random noobs. 

-------------------------------------------------------------------------------------------------------------
