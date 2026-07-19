#ifndef SPOTIFY_PROJECT_ALBUM_H
#define SPOTIFY_PROJECT_ALBUM_H
#include <vector>
#include "Song.h"

using namespace std;

class Album {
private:
    string albumId;
    string name;
    string artistId;
    vector<Song> songs;

public:
    Album(string albumId, string name, string artistId);

    string getAlbumId() const;
    string getName() const;
    string getArtistId() const;
    vector<Song> getSongs() const;

    void addSong(Song song);
};

#endif
