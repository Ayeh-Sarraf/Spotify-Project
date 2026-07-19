#include "PlaylistRepository.h"

using namespace std;

vector<Playlist> PlaylistRepository::playlistsList;

string PlaylistRepository::save(Playlist entity) {
    playlistsList.push_back(entity);
    return entity.getPlaylistId();
}

bool PlaylistRepository::remove(string id) {
    for (auto it = playlistsList.begin(); it != playlistsList.end(); ++it) {
        if (it->getPlaylistId() == id) {
            playlistsList.erase(it);
            return true;
        }
    }
    return false;
}

optional<Playlist> PlaylistRepository::search(string id) {
    for (const auto& playlist : playlistsList) {
        if (playlist.getPlaylistId() == id) {
            return playlist;
        }
    }
    return nullopt;
}

void PlaylistRepository::insertSong(string playlistId, Song song) {
    for (auto& playlist : playlistsList) {
        if (playlist.getPlaylistId() == playlistId) {
            playlist.addSong(song);
            break;
        }
    }
}

void PlaylistRepository::removeSong(string playlistId, string songId) {

}

vector<Playlist> PlaylistRepository::playlists(string listenerId) {
    vector<Playlist> result;
    for (const auto& playlist : playlistsList) {
        if (playlist.getListenerId() == listenerId) {
            result.push_back(playlist);
        }
    }
    return result;
}