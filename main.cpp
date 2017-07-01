#include "Song.h"
#include "Playlist.h"
#include "Library.h"
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "Driver.h"
#include "DotifyApp.h"

using namespace std;

int main (int argc, char *argv[]){
  
	DotifyApp dotify;

	if(argc>2){
		dotify.loadLibrary(ifstream(argv[1]));
		dotify.loadPlaylists(ifstream(argv[2]));
	}
	else if(argc>1){
		dotify.loadLibrary(ifstream(argv[1]));
	}

	dotify.run();

return 0;

}


