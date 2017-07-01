#ifndef DOTIFYAPP_H
#define DOTIFYAPP_H

#include "Song.h"
#include "Library.h"
#include "Playlist.h"
#include "Driver.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

class DotifyApp{

private:
	DotifyDriver driver;
	
	//library specific prompts
	void addNewSongToLibraryPrompt();
	void removeSongFromLibraryPrompt();
	void displaySongsInLibraryPrompt();
	void playSongFromLibraryPrompt();
	//playlist specific prompts
	void rateSpecificPlaylistPrompt();
	void addNewSongToPlaylistPrompt();	
	void renameSpecificPlaylistPrompt();
	void removeSongFromPlaylistPrompt();
	void removeSpecificPlaylistPrompt();
	void createPlaylistPrompt();
	void autogeneratePlaylistPrompt();
	void displayPlaylistsAlphabeticalPrompt();
	void displayPlaylistInOrderAddedPrompt();
	//system general prompts
	void exportLibraryAndPlaylistPrompt();
	void displayHelp();
	void displayPrompt();
	
public:
	
	void run();
	void loadLibrary(ifstream x);
	void loadPlaylists(ifstream x);




};
#endif

