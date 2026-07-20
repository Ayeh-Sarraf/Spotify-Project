#include "SpotifySystem.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    SpotifySystem system;
    int mainChoice;

    while (true) {
        cout << "\n=== Welcome to Spotify ===" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            string fullName, username, password, bio, role;
            cin.ignore();

            cout << "Enter Full Name: ";
            getline(cin, fullName);

            cout << "Enter Username: ";
            getline(cin, username);

            cout << "Enter Password: ";
            getline(cin, password);

            cout << "Enter Biography: ";
            getline(cin, bio);

            cout << "Enter Role (Artist / Listener): ";
            getline(cin, role);

            system.registerUser(fullName, username, password, bio, role);

        } else if (mainChoice == 2) {
            string username, password;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            auto userOpt = system.login(username, password);

            if (userOpt.has_value()) {
                Account user = userOpt.value();

                while (true) {
                    cout << "\n--- User Menu (" << user.getRole() << ") ---" << endl;

                    if (user.getRole() == "Artist") {
                        cout << "1. Create Album\n2. Publish Song\n3. Logout\nChoice: ";
                        int subChoice;
                        cin >> subChoice;

                        if (subChoice == 1) {
                            string albumName;
                            cout << "Album Name: ";
                            cin.ignore();
                            getline(cin, albumName);
                            system.createAlbum(user.getId(), albumName);
                        } else if (subChoice == 2) {
                            string albumId, title, genre, path;
                            int year;
                            cout << "Album ID (0 for Single): ";
                            cin >> albumId;
                            cout << "Song Title: ";
                            cin.ignore();
                            getline(cin, title);
                            cout << "Release Year: ";
                            cin >> year;
                            cout << "Genre: ";
                            cin.ignore();
                            getline(cin, genre);
                            cout << "File Path: ";
                            getline(cin, path);
                            system.createSong(user.getId(), albumId, title, year, genre, path);
                        } else {
                            break;
                        }
                    } else if (user.getRole() == "Listener") {
                        cout << "1. Create Playlist\n2. Add Song to Playlist\n3. Like Song\n4. Suggest Songs\n5. Logout\nChoice: ";
                        int subChoice;
                        cin >> subChoice;

                        if (subChoice == 1) {
                            string pName;
                            cout << "Playlist Name: ";
                            cin.ignore();
                            getline(cin, pName);
                            system.createPlaylist(user.getId(), pName);
                        } else if (subChoice == 2) {
                            string pId, sId;
                            cout << "Playlist ID: ";
                            cin >> pId;
                            cout << "Song ID: ";
                            cin >> sId;
                            system.addSongToPlaylist(user.getId(), pId, sId);
                        }
                        else if (subChoice == 3) {
                            string sId;
                            cout << "Song ID: ";
                            cin >> sId;
                            system.likeSong(user.getId(), sId);
                        } else if (subChoice == 4) {
                            system.suggestSongs(user.getId());
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
        } else if (mainChoice == 3) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}