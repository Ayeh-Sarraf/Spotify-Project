#include "AlbumRepository.h"

using namespace std;

vector<Album> AlbumRepository::albumsList;

string AlbumRepository::save(Album entity) {
    albumsList.push_back(entity);
    return entity.getAlbumId();
}

bool AlbumRepository::remove(string id) {
    for (auto it = albumsList.begin(); it != albumsList.end(); ++it) {
        if (it->getAlbumId() == id) {
            albumsList.erase(it);
            return true;
        }
    }
    return false;
}

optional<Album> AlbumRepository::search(string id) {
    for (const auto& album : albumsList) {
        if (album.getAlbumId() == id) {
            return album;
        }
    }
    return nullopt;
}

vector<Album> AlbumRepository::albums(string artistId) {
    vector<Album> result;
    for (const auto& album : albumsList) {
        if (album.getArtistId() == artistId) {
            result.push_back(album);
        }
    }
    return result;
}