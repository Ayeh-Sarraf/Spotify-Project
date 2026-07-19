#ifndef SPOTIFY_PROJECT_SONGREPOSITORY_H
#define SPOTIFY_PROJECT_SONGREPOSITORY_H
#include "AbstractRepository.h"
#include "Song.h"
#include <vector>

using namespace std;

class SongRepository : public AbstractRepository<Song> {
private:
    static vector<Song> songs;

public:
    string save(Song entity) override;
    bool remove(string id) override;
    optional<Song> search(string id) override;

    vector<Song> singleSongs();
    vector<Song> getByAlbum(string albumId);
    vector<Song> getByArtist(string artistId);
    vector<Song> getByPlaylist(string playlistId);
    vector<Song> getByLikedSongs(string listenerId);
};
#endif