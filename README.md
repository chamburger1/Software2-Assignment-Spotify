copyright Chris Hamburger 2016
*********************************************************************************************
*********************************************************************************************
********************************************DOTIFY*******************************************
*********************************************************************************************
*********************************************************************************************

Compiling: This is done from the command line in a terminal using the supplied makefile using the "make" command once navigated into the correct folder holding the Doitfy source files.

 

Running: The executable created is Dotify and can be run with "./Dotify".  It can also take in a "library.txt" file and a "playlist.txt" files as additional arguments to be run as "./Dotify library.txt playlist.txt". If only a "playlist.txt" file is supplied, the program will skip the platlist.txt file argument as no songs can be added to a a playlist if they are not in the library.

 

The Dotofy App allows the following commands to be entered:

 

AS: Purchases a new song to your library

RS: Removes a specific song from your library

AP: Creates an empty playlist

RP: Removes a specific playlist

RN: Renames a specific playlist

AG: Autogenerates a playlist based on song name, artist, album, or magic

ASP: Adds a specific song from your library to a playlist

RSP: Removes a specific song from a playlist

LB: Displays all the songs in your library

PLS: Displays all the of the playlists in alphabetical order of title

PL: Displays all the songs in a specific playlist in the order added

RT: Rates a specific playlist from 1 to 5

PLY: Plays a specific song in your library a specified number of time

EXP: Exports the song library and playlists to files

HELP: Displays this help menu

EXIT: Exits the program

 

The application uses STL map that holds a string key and a Song object pointer to allow Song objects to be created dynamically.  The map data structure was chosen for its quick key search and retreival O times.  Also it allows a Song to not be duplicated and inserted more then once.  A key is comprised of a title|artist|album structure.  Both a Playlist object and a Library object use the same format which allows quick confirmation if a song is in a Library and in a Playlist. 

 

A Driver class has a Library class, and a STL map of Playlist object pointers.  In this map of Playlists, a key is a Playlist name.  This allows quick confirmation if a Playlist of a specific name exists and allows quick retrieval of such a Playlist object. 

 

The Driver object abstracts the functionality of the library object and playlist object away.  In the driver class, member functions make calls to library and playlist object member functions.

 

The DotifyApp object has 3 public functions, run()-a series of if statements to for a commands to be entered by a user. A function to generate a library from a supplied command line argument and a function to generate a playlist from a supplied command line argument(both options mentioned

 

Notable functions and additions:

 

AG: There is an autogenerate playlist function that allows the user to specify the parameter to generate a playlist from and adds all the songs that match that parameter into a new playlist.  The MAGIC option of autogenerate is a bit different and has the following programming: First it copies all songs from a library into a vector of song object pointers, and then sorts it based on the amount of plays from greatest to least.  In a second vector, it takes the up to the first 15 most played songs, chooses 5 random songs, and stores them in a third vector. This is the hitlist vector.  There is a function that takes in the hitlist vector and a randomized string parameter as arguments.  Based on the randomized parameter, the funtion will choose a random song from the hitlist vector, and match it up to a song in the library and add that matching song to a playlist called "Autogenerated".

 

The LB command allows a user to specify what the ordered-ness of diaply should be.  This works by again copying the songs in a library to a vector and sorting the vector using a lambda funtion sorted by the specified order chosen by the user. ie. NAME, ARTIST, ALBUM, PLAYS.

 

RN: Renaming a playlist searches the driver's playlists map by a name to find the playlist to rename.  If it finds a playlist, it stores the playlist object pointer in a temporary playlist object pointer, creates a new playlist with a new key supplied by the user and the temporary object pointer.  After the insertion, the old key is erased using the map STL erase(key) member. 

 

The PLY command uses an exception handling try and catch c++ functionality to make sure user input matches a valid standard int.  If no valid input is used the amount of plays is automatically set to 0 and no plays are added to a Song's amount of times played.

 

The RT command allows a user to rate a specific playlist.  Again a try and catch used to make sure standard, valid input is received in the stream.  If invalid input is received, a Playlists's rating is unchanged.  All Playlists start at 0.

 

In the Library class is the STL map, which requires an iterator to traverse.  But in the driver class there is no STL map, only a Library object.  So in order to allow iteration of a map STL in the driver class, I created my own iterators as member functions.  This allows me to iterate through a library object inside a driver class object.  
