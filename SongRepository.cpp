#include "SongRepository.h"

using namespace std;

vector<Song> SongRepository::songs;

string SongRepository::save(Song entity) {
    songs.push_back(entity);
    return entity.getSongId();
}

bool SongRepository::remove(string id) {
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (it->getSongId() == id) {
            songs.erase(it);
            return true;
        }
    }
    return false;
}

optional<Song> SongRepository::search(string id) {
    for (const auto& song : songs) {
        if (song.getSongId() == id) {
            return song;
        }
    }
    return nullopt;
}

vector<Song> SongRepository::singleSongs() {
    vector<Song> result;
    for (const auto& song : songs) {
        if (song.getAlbumId() == "") {
            result.push_back(song);
        }
    }
    return result;
}

vector<Song> SongRepository::getByAlbum(string albumId) {
    vector<Song> result;
    for (const auto& song : songs) {
        if (song.getAlbumId() == albumId) {
            result.push_back(song);
        }
    }
    return result;
}

vector<Song> SongRepository::getByArtist(string artistId) {
    vector<Song> result;
    for (const auto& song : songs) {
        if (song.getArtistId() == artistId) {
            result.push_back(song);
        }
    }
    return result;
}

vector<Song> SongRepository::getByPlaylist(string playlistId) {
    vector<Song> result;
    return result;
}

vector<Song> SongRepository::getByLikedSongs(string listenerId) {
    vector<Song> result;
    return result;
}