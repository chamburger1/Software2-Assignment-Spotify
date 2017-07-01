#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "Song.h"
#include "Library.h"
#include "Playlist.h"
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;



class DotifyDriver{

private:
	Library library;
	map<string, Playlist*> playlists;

public:
	DotifyDriver(){}
	~DotifyDriver(){}
	
	void createNewPlaylist(string name);

	//adding songs to library and playlists
	void addSongToPlaylist(string name, int x);
	void addSongToPlaylistMagic(string name, int x);
	void addSongToPlaylistFromFile(string name, string playlistsKey, Song* x);
	void addSongToLibrary(string x, string y, string z){ 		library.addSong(x, y, z);}
	void addSongToLibraryFromFile(string x, string y, string z, int a, int b){library.addSongFromFile(x, y, z, a, b);}

	//playlist utility functions
	int getPlaylistSize(string name){		playlists.find(name)->second->getNumberOfSongs();}
	int getPlaylistRating(string name){		playlists.find(name)->second->getRating();}
	void updatePlaylistRating(string name, int x){	playlists.find(name)->second->setRating(x);}
	bool isPlaylist(string key){			if(playlists.count(key)==1) return true;}
	bool isInAPlaylist(string key, string key2){	if(playlists.find(key)->second->isInPlaylist(key2)) return true;}

	//library utility functions
	bool isInLibrary(int x){			return library.isInLibrary(x);}
	int getLibrarySize(){				return library.getSongAmount();}

	//autgen helper takes in a vector and a choice to populate a playlist
	void autogenerateHelper(vector<Song*>vec, string choice);
	string autogenerateRandomizerHelper();

	//encapsulation from library class function to return a song with a key
	Song * getSongFromLibrary(string key){		return library.getSong(key);}

	//remove from library and playlists
	void removeSongPlaylist(string name, int x){ 	playlists.find(name)->second->removeSong(x);}
	void removeSongLibrary(int x);

	//rename a playlist
	void renamePlaylist(string x, string y);
	
	//prints the whole library in a specified order
	void printLibrary(string choice);

	//plays song in library takes ID# and a times played args
	void playSong(int x, int y);

	//export library and playlists to two file args
	void exportLibraryAndPlaylists(string libraryFile, string playlistFile);
	void removePlaylist(string name);
	//takes in a choice and generates a playlist
	void autogeneratePlaylist(string choice);
	//to print playlists 
	void printInInsertOrder(string name){		playlists.find(name)->second->printInInsertOrder();}
	void printAlphabetic(string name){		playlists.find(name)->second->printAlphabetic();}
	void printAllPlaylists();

};


#endif

