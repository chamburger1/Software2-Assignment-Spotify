#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Library.h"
#include <map>
#include "Song.h"
#include <string>
#include <list>

using namespace std;

class Playlist{

private:
	map<string, Song*> playlist;
	int rating=1;
	string name;
	//list to keep track of when a song is inserted in a playlist
	list<string> insertionOrder;

public:
	Playlist(string _name){	name=_name;}
	~Playlist(){}
	void setRating(int x){	rating=x;}
	void removeSong(int x);
	void erase(string key){				playlist.erase(key);}
	void addSong(string key, Song * song);
	void printInInsertOrder();
	void printAlphabetic();
	bool isInPlaylist(string key){			if(playlist.count(key)==1) return true;}
	int getRating(){				return rating;}
	int getNumberOfSongs(){				return playlist.size();}
	map <string, Song*>::iterator begin(){		return playlist.begin();}
	map <string, Song*>::iterator end(){		return playlist.end();}
};


#endif
