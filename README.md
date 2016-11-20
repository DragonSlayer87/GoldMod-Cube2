# GoldMod-Cube2
Sauerbraten Server Modification


-------------------------------------------------------------------------------------------------------------

**General Information:**

Goldmod is an advanced server modification based on remod.

-------------------------------------------------------------------------------------------------------------

** Features:**

- very good UI
- very userfriendly
- IRC-Bot
- cubescript scripting language
- GEOIP SUPPORT FOR geoip country, geoip city, geoip region, geoip timezone
- about 80 commands
- many useful scripts for server 
- scoreboard (sqlite3 + mysql)
- remote control (udp, tdp, netcat)
- user system (username, password1, password2)
- cross platform (windows, linux, mac, bsd, arch, ...) 
- Duel Mode
- possibility to rename bots ("ainame" in server-init)
- askidban libary (ban some vpns from server)
- really often updates with bugfixes, new functions, ...

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
    #claim - claim master/admin via user system (e.g. #claim username password1 password2)
    
    ... and much more ... :D

-------------------------------------------------------------------------------------------------------------

**Work in Process:**

    enable-disable-commands-system (currently not in work)
    MixModule (currently not in work)
    Clantag Detection (in work)
    GeoIP TimeZone (in work)

-------------------------------------------------------------------------------------------------------------

**Installation:**

    0. First you need to make sure, you've the following packages installed:
    
        - mingw-w64 (cross-compiler -> for cross-compile)
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
    (6. Clean it again: make clean)
    If you did it as i described, a "GoldMod64"(linux) or a "GoldModServer.exe"(windows) in GoldMod-Cube2 main directory
    To run Linux Server: cd GoldMod-Cube2 
                            ./Goldmod64
    To run Windows Server: go to mod archive
                           start GoldModServer.exe
  
    PS: DON'T FORGET TO SETUP SERVER. Just rename "server-init.cfg.default" to "server-init.cfg" and setup server with that file. Save and close it and start server.
    PPS: You don't need to do Step 4 and 6. This command just clean your mod archive from the while compiling generated .o files -> saves disk space
    PPPS: If you run the server on windows, you don't need to follow any of that steps, execpt step 1. Just go to mod archive, setup server-init.cfg (if it says on first server start "...rename server-init.cfg.default to ..." rename it to server-init.cfg) then start server again. DONE!

-------------------------------------------------------------------------------------------------------------

**Update your Server-Mod:**

    1. Open Terminal Shell
    2. type in: cd GoldMod-Cube2
    3. type in: git pull
    
    4. Build it: cd src
    5. Start Compiler: make (for cross-compile: make -f Makefile.win32)
    
------------------------------------------------------------------------------------------------------------- 

**Contact:**

    E-Mail: githubseb.contact@gmail.com
    IRC: Server: irc.gamesurge.com 6667 | Channel: #buds-servers, #novi, #sauercom and #impressivesquad ---> Names: BudSpencer
    Ingame: Names: /BudSpencer, Archaeopteryx, Cocoz

-------------------------------------------------------------------------------------------------------------

**Bug Reports:**

If you suspect any bugs and problems, likes and dislikes message me on IRC, E-Mail or talk with me ingame, I'm always listening. New Ideas for some features are desired ;), but no insulting anything offensive, I don't waste time with random noobs. 

-------------------------------------------------------------------------------------------------------------
