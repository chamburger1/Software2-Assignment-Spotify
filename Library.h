#ifndef LIBRARY_H
#define LIBRARY_H

#include "Song.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <iterator>

using namespace std;

class Library{

private:
	map <string, Song*> library;

public:
	Library(){}
	~Library(){}
	
	//library manipulation
	void addSong(string x, string y, string z);
	void addSongFromFile(string x, string y, string z, int a, int b);
	void removeSong(int x);
	string keyReturn(int x){	for(auto &key: library){ if(key.second->getIdentifier()==x) return key.first;}}
	void updateAmountOfPlays_Library(int x, int y);
	void displayInOrder(string x);
	//iterators to allow abstraction an iteration in driver class
	map <string, Song*>::iterator beginLibrary(){			return library.begin();}
	map <string, Song*>::iterator endLibrary(){			return library.end();}
	//utility functiosn to confirm object is in library
	bool isInLibrary(int x);
	bool isKeyInLibrary(string key){	if(library.count(key)==1) return true;}
	//returns how many songs are in library
	int getSongAmount(){			return library.size();}
	//function to return a song object by key
	Song * getSong(string key){		return library.find(key)->second;}


	//song object access
	string getArtist(string key){ 		return library.find(key)->second->getArtist();}
	string getAlbum(string key){ 		return library.find(key)->second->getAlbum();}
	int getAmtPlays(string key){		return library.find(key)->second->getAmtPlays();}

};


#endif
