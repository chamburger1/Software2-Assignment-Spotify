#include "DotifyApp.h"

//library specific prompts
void DotifyApp::addNewSongToLibraryPrompt(){
	string titleX, artistX, albumX;
	cout<<"What is the name of the song you’d like to purchase?"<<endl;
	getline(cin, titleX);
	cout<<"Who is its artist?"<<endl;
	getline(cin, artistX);
	cout<<"Which album does it belong to?"<<endl;
	getline(cin, albumX);
	driver.addSongToLibrary(titleX, artistX, albumX);
}

void DotifyApp::removeSongFromLibraryPrompt(){
	string idXstring;
	int idX;
	cout<<"What is the identifier of the song you’d like to remove from your library?"<<endl;
	getline(cin, idXstring);
	idX=stoi(idXstring);
	driver.removeSongLibrary(idX);
}

void DotifyApp::displaySongsInLibraryPrompt(){
	if(driver.getLibrarySize()==0)
		cout<<"You have no songs in your library."<<endl;
	else{	
		string choice;
		cout<<"What category should the songs be ordered by? (NAME/ARTIST/ALBUM/PLAYS)"<<endl;
		getline(cin, choice);
		driver.printLibrary(choice);
	}		
}

//plays song based on the id# and the times to play it
//does an exception handle if input is not valid
//if negative numvber amt=0
//if anything not int, amt=0
void DotifyApp::playSongFromLibraryPrompt(){
	if(driver.getLibrarySize()==0){
		cout<<"No songs in library."<<endl;
		return;
	}
	string idXString, amtString;
	int idX, amt;
	cout<<"What is the identifier of the song you’d like to play from your library?"<<endl;
	getline(cin, idXString);
	idX=stoi(idXString);
	cout<<"How many times would you lke to play this song?"<<endl;
	getline(cin, amtString);
	try{
		amt=stoi(amtString);
	}
	catch(invalid_argument&){
		amt=0;
	}
	if(amt<0)
		amt=0;

	driver.playSong(idX, amt);
}

//playlist specific prompts
void DotifyApp::rateSpecificPlaylistPrompt(){
	string playlistX, ratingXstring;
	int ratingX;
	cout<<"What is the title of the playlist you’d like to rate?"<<endl;
	getline(cin, playlistX);
	if(!driver.isPlaylist(playlistX)){
		cout<<"\""<<playlistX<<"\" does not exist."<<endl;
		return;
	}
	else{
		cout<<"What rating would you like to give this playlist? (1 to 5)"<<endl;
		getline(cin, ratingXstring);
		try{
			ratingX=stoi(ratingXstring);
		}
		catch(invalid_argument&){
			cout<<"\""<<ratingXstring<<"\""<<" is not valid."<<endl;
		}
		if(ratingX<1||ratingX>5)
			cout<<"\""<<ratingX<<"\""<<" is not valid."<<endl;
		else{	
			driver.updatePlaylistRating(playlistX, ratingX);
			cout<<"\""<<playlistX<<"\""<<" updated rating is "<<driver.getPlaylistRating(playlistX)<<endl;
		}
	}
}

//asks user for a key and searches the playlists map
//if found erase key, if not inform user
void DotifyApp::removeSpecificPlaylistPrompt(){
	string playlistX;
	cout<<"What is the title of the playlist you’d like to remove?"<<endl;
	getline(cin, playlistX);
	if(driver.isPlaylist(playlistX)==false)
		cout<<"\""<<playlistX<<"\""<<" is not a playlist."<<endl;
	else{
		driver.removePlaylist(playlistX);
		cout<<"\""<<playlistX<<"\""<<" removed successfully."<<endl;
	}

}

//asks user for a playlists key to add song to
//and an id# to add, errors handled by function called
void DotifyApp::addNewSongToPlaylistPrompt(){
	string playlistX, idString;
	int idX;
	cout<<"What is the title of the playlist you’d like to add a song to?"<<endl;
	getline(cin, playlistX);
	cout<<"What is identifier of the song to add to the playlist?"<<endl;
	getline(cin, idString);
	idX=stoi(idString);
	driver.addSongToPlaylist(playlistX, idX);
}

//user input for key and new key
//makes sure its a playlist and calls renamePlaylist() from driver class
void DotifyApp::renameSpecificPlaylistPrompt(){
	string playlistX, playlistY;
	cout<<"What is the title of the playlist you’d like to rename?"<<endl;
	getline(cin, playlistX);
	if(!driver.isPlaylist(playlistX))
		cout<<playlistX<<" is not a playlist."<<endl;
	else{
		cout<<"What is the new title that you’d like to rename it to?"<<endl;
		getline(cin, playlistY);
		if(driver.isPlaylist(playlistY))
			cout<<"\""<<playlistY<<"\""<<" is already a playlist."<<endl;
		else
			driver.renamePlaylist(playlistX, playlistY);
	}
}

void DotifyApp::removeSongFromPlaylistPrompt(){
	string playlistX, idXstring;
	int idX;
	cout<<"What is the title of the playlist you’d like to remove a song from?"<<endl;
	getline(cin, playlistX);

	if(!driver.isPlaylist(playlistX))
		cout<<"\""<<playlistX<<"\""<<" is not a playlist."<<endl;
	else{
		cout<<"What is identifier of the song to remove from the playlist?"<<endl;
		getline(cin, idXstring);
		idX=stoi(idXstring);
		driver.removeSongPlaylist(playlistX, idX);
		cout<<"Song removed."<<endl;
	}
}

void DotifyApp::createPlaylistPrompt(){
	string playlistX;
	cout<<"What is the title of the playlist you’d like to create?"<<endl;
	getline(cin, playlistX);
	if(driver.isPlaylist(playlistX))
		cout<<"\""<<playlistX<<"\""<<" is already a playlist."<<endl;
	else
		driver.createNewPlaylist(playlistX);
}

void DotifyApp::autogeneratePlaylistPrompt(){
	string choice;
	cout<<"What is the category you’d like to autogenerate a playlist with?";
	cout<<"(NAME/ARTIST/ALBUM/MAGIC)"<<endl;
	getline(cin, choice);
	driver.autogeneratePlaylist(choice);
}

void DotifyApp::displayPlaylistsAlphabeticalPrompt(){
	driver.printAllPlaylists();
}


void DotifyApp::displayPlaylistInOrderAddedPrompt(){
	string playlistX;
	cout<<"What is the title of the playlist you’d like to display?"<<endl;
	getline(cin, playlistX);
	if(driver.isPlaylist(playlistX)&&driver.getPlaylistSize(playlistX)==0)
		cout<<"\""<<playlistX<<"\""<<" playlist has no songs."<<endl;
	else if(driver.isPlaylist(playlistX)==false)
		cout<<"\""<<playlistX<<"\""<<" is not a playlist."<<endl;
	else
		driver.printInInsertOrder(playlistX);
}

//system general prompt to display some intro to user
void DotifyApp::displayPrompt(){
	
	cout<<"Welcome to Dotify, Spotify's forgotten competitor."<<endl;
	cout<<"What would you like to do?"<<endl;
}

//export prompt for user to specifiy and name file for library and playlist
void DotifyApp::exportLibraryAndPlaylistPrompt(){
	string libraryFile, playlistFile; 
	cout<<"What is the name of the file you’d like to export your library to?"<<endl;
	getline(cin, libraryFile);
	cout<<"What is the name of the file you’d like to export your playlists to?"<<endl;
	getline(cin, playlistFile);
	driver.exportLibraryAndPlaylists(libraryFile, playlistFile);
	cout<<"Library and playlists exported successfully!"<<endl;
}

//if statements in run function that execute as long as "EXIT" isn't entered
//command input makes calls to variosu prompts
void DotifyApp::run(){
string command;	
	displayPrompt();

	while(command!="EXIT"){
	cout<<endl;
	cin.clear();
	cin.sync();
	cout<<"Enter Command. Enter HELP for list of commands."<<endl;
	getline(cin, command);

	if(command=="AS"){
		addNewSongToLibraryPrompt();
	}
	else if(command=="RS"){
		removeSongFromLibraryPrompt();
	}
	else if(command=="AP"){
		createPlaylistPrompt();
	}
	else if(command=="RP"){
		removeSpecificPlaylistPrompt();
	}
	else if(command=="RN"){
		renameSpecificPlaylistPrompt();
	}
	else if(command=="AG"){
		autogeneratePlaylistPrompt();
	}
	else if(command=="ASP"){
		addNewSongToPlaylistPrompt();
	}
	else if(command=="RSP"){
		removeSongFromPlaylistPrompt();
	}
	else if(command=="LB"){
		displaySongsInLibraryPrompt();
	}
	else if(command=="PLS"){
		displayPlaylistsAlphabeticalPrompt();
	}
	else if(command=="PL"){
		displayPlaylistInOrderAddedPrompt();
	}
	else if(command=="RT"){
		rateSpecificPlaylistPrompt();
	}
	else if(command=="PLY"){
		playSongFromLibraryPrompt();
	}
	else if(command=="EXP"){
		exportLibraryAndPlaylistPrompt();
	}
	else if(command=="HELP"){
		displayHelp();
	}
}//end while
}//end function

//displays the command options available to user
void DotifyApp::displayHelp(){

	cout<<"AS: Purchases a new song to your library"<<endl;
	cout<<"RS: Removes a specific song from your library"<<endl;
	cout<<"AP: Creates an empty playlist"<<endl;
	cout<<"RP: Removes a specific playlist"<<endl;
	cout<<"RN: Renames a specific playlist"<<endl;
	cout<<"AG: Autogenerates a playlist based on song name, artist, album, or magic"<<endl;
	cout<<"ASP: Adds a specific song from your library to a playlist"<<endl;
	cout<<"RSP: Removes a specific song from a playlist"<<endl;
	cout<<"LB: Displays all the songs in your library"<<endl;
	cout<<"PLS: Displays all the of the playlists in alphabetical order of title"<<endl;
	cout<<"PL: Displays all the songs in a specific playlist in the order added"<<endl;
	cout<<"RT: Rates a specific playlist from 1 to 5"<<endl;
	cout<<"PLY: Plays a specific song in your library a specified number of time"<<endl;
	cout<<"EXP: Exports the song library and playlists to files"<<endl;
	cout<<"HELP: Displays this help menu"<<endl;
	cout<<"EXIT: Exits the program"<<endl;
}

//takes in an ifstream reference for command line arguments
//parses through file with getline and string stream
//checks for validate file format and if not indicate to user and close the file and return
void DotifyApp::loadLibrary(ifstream x){
string line;

if(!x){
	cout<<"Library File Error. Skipping."<<endl;
}
else{
	while(getline(x, line)){

		string artistX, titleX, albumX, playsX, idX;
		int playToInt, idToInt;
		istringstream   linestream(line);
		getline(linestream, titleX, '|');  // read up-to the first tab (discard tab).
		getline(linestream, artistX, '|');  // read up-to the first tab (discard tab).
		getline(linestream, albumX, '|'); 
		getline(linestream, playsX, '|');
		getline(linestream, idX); 

		try{
			idToInt=stoi(idX);
			playToInt=stoi(playsX);
		}
		catch(invalid_argument&){
			cout<<"Format error. Check formating of file. Closing file."<<endl;
			x.close();
			return;
		}


		driver.addSongToLibraryFromFile(titleX, artistX, albumX, playToInt, idToInt);
   	}

	x.close();
}
}

//takes in an ifstream reference for command line arguments
//parses through file with getline and string stream
//checks for validate file format and if not indicate to user and close the file and return
void DotifyApp::loadPlaylists(ifstream x){
if(driver.getLibrarySize()==0){
	cout<<"Empty Library. No Playlists added."<<endl;
	return;
}

string line;

if(!x){
	cout<<"Playlist File Error. Skipping."<<endl;
}
else{
	while(getline(x, line)){
		
		string playlistTitle, playlistRating, playlistSongCount, xx;
		int playlistratingX, playlistsongcountX;
		istringstream   linestream(line);
		getline(linestream, playlistTitle, '|'); 
		getline(linestream, playlistRating, '|');
		getline(linestream, playlistSongCount);

		driver.createNewPlaylist(playlistTitle);
		try{
			playlistratingX=stoi(playlistRating);
			playlistsongcountX=stoi(playlistSongCount);
		}
		catch(invalid_argument&){
			cout<<"Format error. Check formating of file. Closing file."<<endl;
			x.close();
			return;
		}


		for(int count=0; count<playlistsongcountX; count++){
			string titleX, artistX, albumX;
			getline(x, titleX, '|');
			getline(x, artistX, '|');
			getline(x, albumX); 
			string key=titleX+string("|")+artistX+("|")+albumX;
			driver.addSongToPlaylistFromFile(key, playlistTitle, driver.getSongFromLibrary(key));
		}
   	}
	x.close();
    }
}

