#ifndef SPOTIFY_PROJECT_ARTISTREPOSITORY_H
#define SPOTIFY_PROJECT_ARTISTREPOSITORY_H
#include "AccountRepository.h"
#include <vector>

using namespace std;

class ArtistRepository : public AccountRepository {
private:
    static vector<Account> artists;

public:
    string save(Account entity) override;
    bool remove(string id) override;
    optional<Account> search(string id) override;
    optional<Account> searchByUserName(string username) override;
};
#endif
