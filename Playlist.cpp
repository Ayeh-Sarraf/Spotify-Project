#include "Playlist.h"

using namespace std;

Playlist::Playlist(string playlistId, string name, string listenerId) {
    this->playlistId = playlistId;
    this->name = name;
    this->listenerId = listenerId;
}

string Playlist::getPlaylistId() const {
    return playlistId;
}

string Playlist::getName() const {
    return name;
}

string Playlist::getListenerId() const {
    return listenerId;
}

vector<Song> Playlist::getSongs() const {
    return songs;
}

void Playlist::addSong(Song song) {
    songs.push_back(song);
}