#ifndef SPOTIFY_PROJECT_LISTENERREPOSITORY_H
#define SPOTIFY_PROJECT_LISTENERREPOSITORY_H
#include "AccountRepository.h"
#include <vector>

using namespace std;

struct Like {
    string listenerId;
    string songId;
};

class ListenerRepository : public AccountRepository {
private:
    static vector<Account> listeners;
    static vector<Like> likedSongs;

public:
    string save(Account entity) override;
    bool remove(string id) override;
    optional<Account> search(string id) override;
    optional<Account> searchByUserName(string username) override;

    void updateLiked(string listenerId, string songId);
    bool isLiked(string listenerId, string songId);
};

#endif