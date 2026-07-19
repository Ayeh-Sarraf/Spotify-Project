#include "Account.h"

using namespace std;

Account::Account(string id, string fullName, string username, string password, string biography, string role) {
    this->id = id;
    this->fullName = fullName;
    this->username = username;
    this->password = password;
    this->biography = biography;
    this->role = role;
}

string Account::getId() const {
    return id;
}

string Account::getFullName() const {
    return fullName;
}

string Account::getUsername() const {
    return username;
}

string Account::getPassword() const {
    return password;
}

string Account::getBiography() const {
    return biography;
}

string Account::getRole() const {
    return role;
}