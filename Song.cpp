#include "Song.h"

using namespace std;

Song::Song(string songId, string name, int releaseYear, string genre, string audioFileName, string artistId, string albumId) {
    this->songId = songId;
    this->name = name;
    this->releaseYear = releaseYear;
    this->genre = genre;
    this->audioFileName = audioFileName;
    this->artistId = artistId;
    this->albumId = albumId;
}

string Song::getSongId() const {
    return songId;
}

string Song::getName() const {
    return name;
}

int Song::getReleaseYear() const {
    return releaseYear;
}

string Song::getGenre() const {
    return genre;
}

string Song::getAudioFileName() const {
    return audioFileName;
}

string Song::getArtistId() const {
    return artistId;
}

string Song::getAlbumId() const {
    return albumId;
}