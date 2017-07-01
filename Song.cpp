#include "Song.h"

//display contents of Song object function
void Song::displayAll(){
	cout<<"\""<<getTitle()<<"\" by ";
	cout<<getArtist()<<" (";
	cout<<getAlbum()<<") - ";
	cout<<getAmtPlays()<<" plays ID#[";
	cout<<getIdentifier()<<"]";
}

