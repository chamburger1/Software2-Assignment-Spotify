#include "Library.h"

//strings come in as title, artist,album
//function used for runtime, user created songs
void Library::addSong(string x, string y, string z){ 
string key=x+string("|")+y+string("|")+z;
	if(library.count(key)>0){
		cout<<"Song already in library. Identified as #";
		cout<<library.find(key)->second->getIdentifier()<<endl;
	}
	else{
		Song * newSong;
		newSong= new Song(x, y, z, 0, library.size()+1);
		library.insert(pair<string, Song*>(key, newSong));
	}
}

//this is a modifed function to add songs from a file
//this is used because a liubrary file might have different ID# schemes and times played
//used for when a program given a file as commandline args
void Library::addSongFromFile(string x, string y, string z, int a, int b){
string key=x+string("|")+y+string("|")+z;
	if(library.count(key)>0){
		cout<<"Song already in library. Identified as #";
		cout<<library.find(key)->second->getIdentifier()<<endl;
	}
	else{
		Song * newSong;
		newSong= new Song(x, y, z, a, b);
		library.insert(pair<string, Song*>(key, newSong));
	}
}	

//loop through map from begining,  compare x to the song identifiers and if a match remove by keyvalue
void Library::removeSong(int x){
	for (auto& keyvalue: library){
		if(keyvalue.second->getIdentifier()==x){
			cout<<"\""<<keyvalue.second->getTitle()<<"\" by ";
			cout<<keyvalue.second->getArtist()<<"("<<keyvalue.second->getAlbum()<<") ";
			cout<<", identified by #"<<x;
			library.erase(keyvalue.first);
			cout<<" was removed successfully from library."<<endl;
		}
	}

}

//user enters a string order specifier
//map's second elements copied into vector 
//for loop to iterate through
void Library::displayInOrder(string x){
	if(library.empty()){
		cout<<"Library has no songs."<<endl;
		return;
	}
	vector <Song*> displayInOrderVector;
//using lambda functions with c++11
//sort a vector based on a specified object attribute
//sort uses the 3rd predicate option to take in a comparasion function object
	if(x=="NAME"){
		for (auto& keyvalue: library){
			displayInOrderVector.push_back(keyvalue.second);
		}
		sort(displayInOrderVector.begin(), displayInOrderVector.end(), [](Song* a, Song* b){return a->getTitle() < b->getTitle();});
		for(int count=0; count<displayInOrderVector.size(); count++){
			cout<<count+1<<". ";
			displayInOrderVector.at(count)->displayAll();
			cout<<endl;
		}
	}
	else if(x=="ARTIST"){
		for (auto& keyvalue: library){
			displayInOrderVector.push_back(keyvalue.second);
		}
		sort(displayInOrderVector.begin(), displayInOrderVector.end(), [](Song* a, Song* b){return a->getArtist() < b->getArtist();});
		for(int count=0; count<displayInOrderVector.size(); count++){
			cout<<count+1<<". ";
			displayInOrderVector.at(count)->displayAll();
			cout<<endl;
		}
	}
	else if(x=="ALBUM"){
		for (auto& keyvalue: library){
			displayInOrderVector.push_back(keyvalue.second);
		}
		sort(displayInOrderVector.begin(), displayInOrderVector.end(), [](Song* a, Song* b){return a->getAlbum() < b->getAlbum();});
		for(int count=0; count<displayInOrderVector.size(); count++){
			cout<<count+1<<". ";
			displayInOrderVector.at(count)->displayAll();
			cout<<endl;
		}
	}
	else if(x=="PLAYS"){
		for (auto& keyvalue: library){
			displayInOrderVector.push_back(keyvalue.second);
		}
		sort(displayInOrderVector.begin(), displayInOrderVector.end(), [](Song* a, Song* b){return a->getAmtPlays() < b->getAmtPlays();});
		for(int count=0; count<displayInOrderVector.size(); count++){
			cout<<count+1<<". ";
			displayInOrderVector.at(count)->displayAll();
			cout<<endl;
		}
	}
}//end of funintion

//utility function to check if an ID # is in a library
bool Library::isInLibrary(int x){
	for (auto& key:library){
		if(key.second->getIdentifier()==x)
			return true;
	}
}

//updates amount of plays for a song
//if song not found let user know
//could use utility function isInLibrary()
//but function iterates through map already 
//and would be unneccessary
void Library::updateAmountOfPlays_Library(int x, int y){
	bool found;
	for (auto& key:library){
		if(key.second->getIdentifier()==x){
			cout<<"\""<<key.second->getTitle()<<"\"";
			cout<<" by "<<key.second->getArtist()<<" (";
			cout<<") "<<key.second->getAlbum()<<"), identified as #";
			cout<<key.second->getIdentifier()<<", played "<<y<<" times.";
			cout<<"( "<<key.second->getAmtPlays();
			key.second->updateAmountOfPlays(y);
			cout<<"->"<<key.second->getAmtPlays()<<")"<<endl;
			found=true;
			return;
		}
	}
	if(!found)
		cout<<"No song ID# "<<x<<" found in library."<<endl;
}
