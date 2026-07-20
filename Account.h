
#ifndef SPOTIFY_PROJECT_ACCOUNT_H
#define SPOTIFY_PROJECT_ACCOUNT_H
#include <iostream>
using namespace std;

class Account {
private:
    string id;
    string fullName;
    string username;
    string password;
    string biography;
    string role;

public:
    Account(string id, string fullName, string username, string password, string biography, string role);

    string getId() const;
    string getFullName() const;
    string getUsername() const;
    string getPassword() const;
    string getBiography() const;
    string getRole() const;
};
#endif
