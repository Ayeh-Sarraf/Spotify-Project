#include "ListenerRepository.h"

using namespace std;

vector<Account> ListenerRepository::listeners;
vector<Like> ListenerRepository::likedSongs;

string ListenerRepository::save(Account entity) {
    listeners.push_back(entity);
    return entity.getId();
}

bool ListenerRepository::remove(string id) {
    for (auto it = listeners.begin(); it != listeners.end(); ++it) {
        if (it->getId() == id) {
            listeners.erase(it);
            return true;
        }
    }
    return false;
}

optional<Account> ListenerRepository::search(string id) {
    for (const auto& listener : listeners) {
        if (listener.getId() == id) {
            return listener;
        }
    }
    return nullopt;
}

optional<Account> ListenerRepository::searchByUserName(string username) {
    for (const auto& listener : listeners) {
        if (listener.getUsername() == username) {
            return listener;
        }
    }
    return nullopt;
}

void ListenerRepository::updateLiked(string listenerId, string songId) {
    for (auto it = likedSongs.begin(); it != likedSongs.end(); ++it) {
        if (it->listenerId == listenerId && it->songId == songId) {
            likedSongs.erase(it);
            return;
        }
    }
    likedSongs.push_back({listenerId, songId});
}

bool ListenerRepository::isLiked(string listenerId, string songId) {
    for (const auto& p : likedSongs) {
        if (p.listenerId == listenerId && p.songId == songId) {
            return true;
        }
    }
    return false;
}