#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song{

private:
	string title, artist, album;
	int amount_of_plays, identifier;

public:
	Song(string x, string y, string z, int a, int b){ 	title=x; artist=y; album=z; amount_of_plays=a; identifier=b;}
	~Song(){}
	
	//updates for plays and rating
	void updateAmountOfPlays(int x){ 	amount_of_plays=amount_of_plays+x;}

	//getters
	string getTitle(){ 	return title;}
	string getArtist(){ 	return artist;}
	string getAlbum(){ 	return album;}
	int getAmtPlays(){	return amount_of_plays;}
	int getIdentifier(){	return identifier;}
	
	//a display song details function
	void displayAll();

};

#endif
