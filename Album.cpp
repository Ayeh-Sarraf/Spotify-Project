#include "Album.h"
using namespace std;

Album::Album(string albumId, string name, string artistId) {
    this->albumId = albumId;
    this->name = name;
    this->artistId = artistId;
}

string Album::getAlbumId() const {
    return albumId;
}

string Album::getName() const {
    return name;
}

string Album::getArtistId() const {
    return artistId;
}

vector<Song> Album::getSongs() const {
    return songs;
}

void Album::addSong(Song song) {
    songs.push_back(song);
}