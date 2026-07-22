#include "ArtistRepository.h"

using namespace std;

vector<Account> ArtistRepository::artists;

string ArtistRepository::save(Account entity) {
    artists.push_back(entity);
    return entity.getId();
}

bool ArtistRepository::remove(string id) {
    for (auto it = artists.begin(); it != artists.end(); ++it) {
        if (it->getId() == id) {
            artists.erase(it);
            return true;
        }
    }
    return false;
}

optional<Account> ArtistRepository::search(string id) {
    for (const auto& artist : artists) {
        if (artist.getId() == id) {
            return artist;
        }
    }
    return nullopt;
}

optional<Account> ArtistRepository::searchByUserName(string username) {
    for (const auto& artist : artists) {
        if (artist.getUsername() == username) {
            return artist;
        }
    }
    return nullopt;
}