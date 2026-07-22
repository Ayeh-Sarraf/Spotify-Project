#ifndef SPOTIFY_PROJECT_ALBUMREPOSITORY_H
#define SPOTIFY_PROJECT_ALBUMREPOSITORY_H
#include "AbstractRepository.h"
#include "Album.h"
#include <vector>

using namespace std;

class AlbumRepository : public AbstractRepository<Album> {
private:
    static vector<Album> albumsList;

public:
    string save(Album entity) override;
    bool remove(string id) override;
    optional<Album> search(string id) override;

    vector<Album> albums(string artistId);
};
#endif
