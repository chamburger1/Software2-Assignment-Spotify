#include "Playlist.h"

//removes song from playlist
//matches the ID# and if its found erases the key
//if not found 
void Playlist::removeSong(int x){
	bool removed=false;
	for (auto& keyvalue: playlist){
		if(keyvalue.second->getIdentifier()==x){
			keyvalue.second->displayAll();
			playlist.erase(keyvalue.first);
			removed=true;
			cout<<" has been removed from \""<<keyvalue.first<<"\""<<endl;
		}
	}
	if(!removed)
		cout<<"No song with identifier #"<<x<<" exists in library."<<endl;
}


//Song added to playlist with key and Song object pointer
//if already in playlist inform user
void Playlist::addSong(string key, Song* song){
		if(isInPlaylist(key)){
			cout<<"\""<<song->getTitle()<<"\"";
			cout<<" by "<<song->getArtist();
			cout<<" ("<<song->getAlbum()<<")"; 
			cout<<" identified as "<<song->getIdentifier();
			cout<<" is already in playlist."<<endl;
		}
		else{
			playlist.insert(pair<string, Song*>(key, song));
			insertionOrder.push_back(key);
		}
}

//iterates through list member and prints songs from the underlying playlist map
void Playlist::printInInsertOrder(){
	for (auto& it: insertionOrder){ 
		playlist.find(it)->second->displayAll();
		cout<<endl;
	}
}

//since STL maps follow inherent ordering of keys and keys start with title of songs
//iteration through map from begin() to end() is O(N)
//call to song objects display function
void Playlist::printAlphabetic(){
	for (auto& key: playlist){
		key.second->displayAll();
		cout<<endl;
	}
}
	
