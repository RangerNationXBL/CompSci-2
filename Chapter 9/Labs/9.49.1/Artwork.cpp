#include "Artwork.h"
#include <iostream>
#include <iomanip>

// TODO: Define default constructor
Artwork::Artwork(){
    title = "unknown";
    yearCreated = -1;
}

// TODO: Define second constructor to initialize
//       private fields (title, yearCreated, artist)
Artwork::Artwork(string title, int yearCreated, const Artist& artist){
    this->title = title;
    this->yearCreated = yearCreated;
    this->artist = artist;
}

// TODO: Define get functions: GetTitle(), GetYearCreated()
string Artwork::GetTitle() const{
    return title;
}

int Artwork::GetYearCreated() const{
    return yearCreated;
}

// TODO: Define PrintInfo() function
//       Call the PrintInfo() function in the Artist class to print an artist's information
void Artwork::PrintInfo() const{
    artist.PrintInfo();
    cout << endl << "Title: " << title << ", " << yearCreated;
}