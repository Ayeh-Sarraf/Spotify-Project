#ifndef SPOTIFY_PROJECT_PLAYLIST_H
#define SPOTIFY_PROJECT_PLAYLIST_H
#include <iostream>
#include <vector>
#include "Song.h"
using namespace std;

class Playlist {
private:
    string playlistId;
    string name;
    string listenerId;
    vector<Song> songs;

public:
    Playlist(string playlistId, string name, string listenerId);

    string getPlaylistId() const;
    string getName() const;
    string getListenerId() const;
    vector<Song> getSongs() const;

    void addSong(Song song);
};
#endif
