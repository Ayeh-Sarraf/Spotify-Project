#ifndef SPOTIFY_PROJECT_PLAYLISTREPOSITORY_H
#define SPOTIFY_PROJECT_PLAYLISTREPOSITORY_H
#include "AbstractRepository.h"
#include "Playlist.h"
#include <vector>

using namespace std;

class PlaylistRepository : public AbstractRepository<Playlist> {
private:
    static vector<Playlist> playlistsList;

public:
    string save(Playlist entity) override;
    bool remove(string id) override;
    optional<Playlist> search(string id) override;

    void insertSong(string playlistId, Song song);
    void removeSong(string playlistId, string songId);
    vector<Playlist> playlists(string listenerId);
};

#endif
