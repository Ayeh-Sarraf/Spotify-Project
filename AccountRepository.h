#ifndef SPOTIFY_PROJECT_ACCOUNTREPOSITORY_H
#define SPOTIFY_PROJECT_ACCOUNTREPOSITORY_H

#include "AbstractRepository.h"
#include "Account.h"
#include <optional>

using namespace std;

class AccountRepository : public AbstractRepository<Account> {
public:
    virtual optional<Account> searchByUserName(string username) = 0;
};

#endif
