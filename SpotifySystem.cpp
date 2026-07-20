#include "SpotifySystem.h"

using namespace std;

bool SpotifySystem::registerUser(string fullName, string username, string password, string biography, string role) {
    if (artistRepo.searchByUserName(username).has_value() || listenerRepo.searchByUserName(username).has_value()) {
        cout << "Error: This username is already taken!" << endl;
        return false;
    }

    string newId = to_string(nextUserId++);
    Account newUser(newId, fullName, username, password, biography, role);

    if (role == "Artist") {
        artistRepo.save(newUser);
    } else if (role == "Listener") {
        listenerRepo.save(newUser);
    } else {
        cout << "Error: Invalid role!" << endl;
        return false;
    }

    cout << "Success: User " << username << " registered successfully as a " << role << "!" << endl;
    return true;
}

optional<Account> SpotifySystem::login(string username, string password) {
    auto artistOpt = artistRepo.searchByUserName(username);
    if (artistOpt.has_value() && artistOpt.value().getPassword() == password) {
        cout << "Login successful! Welcome Artist " << artistOpt.value().getFullName() << endl;
        return artistOpt.value();
    }

    auto listenerOpt = listenerRepo.searchByUserName(username);
    if (listenerOpt.has_value() && listenerOpt.value().getPassword() == password) {
        cout << "Login successful! Welcome Listener " << listenerOpt.value().getFullName() << endl;
        return listenerOpt.value();
    }

    cout << "Error: Invalid username or password!" << endl;
    return nullopt;
}

bool SpotifySystem::createAlbum(string artistId, string albumName) {
    auto artistOpt = artistRepo.search(artistId);
    if (!artistOpt.has_value()) {
        cout << "Error: Artist not found!" << endl;
        return false;
    }

    string newAlbumId = "ALB" + to_string(nextAlbumId++);
    Album newAlbum(newAlbumId, albumName, artistId);
    albumRepo.save(newAlbum);

    cout << "Success: Album '" << albumName << "' created successfully!" << endl;
    return true;
}

bool SpotifySystem::createSong(string artistId, string albumId, string title, int releaseYear, string genre, string filePath) {
    auto artistOpt = artistRepo.search(artistId);
    if (!artistOpt.has_value()) {
        cout << "Error: Artist not found!" << endl;
        return false;
    }

    if (albumId != "0" && !albumRepo.search(albumId).has_value()) {
        cout << "Error: Album not found!" << endl;
        return false;
    }

    string newSongId = "SNG" + to_string(nextSongId++);
    Song newSong(newSongId, title, releaseYear, genre, filePath, artistId, albumId);
    songRepo.save(newSong);

    cout << "Success: Song '" << title << "' published successfully!" << endl;
    return true;
}

bool SpotifySystem::createPlaylist(string listenerId, string playlistName) {
    auto listenerOpt = listenerRepo.search(listenerId);
    if (!listenerOpt.has_value()) {
        cout << "Error: Listener not found!" << endl;
        return false;
    }

    string newPlaylistId = "PL" + to_string(nextPlaylistId++);
    Playlist newPlaylist(newPlaylistId, playlistName, listenerId);
    playlistRepo.save(newPlaylist);

    cout << "Success: Playlist '" << playlistName << "' created successfully!" << endl;
    return true;
}

bool SpotifySystem::addSongToPlaylist(string listenerId, string playlistId, string songId) {
    auto playlistOpt = playlistRepo.search(playlistId);
    if (!playlistOpt.has_value() || playlistOpt.value().getListenerId() != listenerId) {
        cout << "Error: Playlist not found or access denied!" << endl;
        return false;
    }

    auto songOpt = songRepo.search(songId);
    if (!songOpt.has_value()) {
        cout << "Error: Song not found!" << endl;
        return false;
    }

    playlistRepo.insertSong(playlistId, songOpt.value());
    cout << "Success: Song added to playlist successfully!" << endl;
    return true;
}

bool SpotifySystem::likeSong(string listenerId, string songId) {
    auto listenerOpt = listenerRepo.search(listenerId);
    if (!listenerOpt.has_value()) {
        cout << "Error: Listener not found!" << endl;
        return false;
    }

    auto songOpt = songRepo.search(songId);
    if (!songOpt.has_value()) {
        cout << "Error: Song not found!" << endl;
        return false;
    }

    listenerRepo.updateLiked(listenerId, songId);
    cout << "Success: Song liked status updated!" << endl;
    return true;
}

bool SpotifySystem::suggestSongs(string listenerId) {
    auto listenerOpt = listenerRepo.search(listenerId);
    if (!listenerOpt.has_value()) {
        cout << "Error: Listener not found!" << endl;
        return false;
    }

    vector<string> likedGenres;
    vector<string> likedArtists;

    for (int i = 1; i < nextSongId; i++) {
        string sId = "SNG" + to_string(i);
        auto songOpt = songRepo.search(sId);
        if (songOpt.has_value() && listenerRepo.isLiked(listenerId, sId)) {
            likedGenres.push_back(songOpt.value().getGenre());
            likedArtists.push_back(songOpt.value().getArtistId());
        }
    }

    bool foundAny = false;
    for (int i = 1; i < nextSongId; i++) {
        string sId = "SNG" + to_string(i);
        auto songOpt = songRepo.search(sId);
        if (songOpt.has_value() && !listenerRepo.isLiked(listenerId, sId)) {
            bool match = false;
            for (string g : likedGenres) {
                if (songOpt.value().getGenre() == g) match = true;
            }
            for (string a : likedArtists) {
                if (songOpt.value().getArtistId() == a) match = true;
            }

            if (match) {
                cout << "Suggestion: '" << songOpt.value().getTitle() << "' (Matches your taste!)" << endl;
                foundAny = true;
            }
        }
    }

    if (!foundAny) {
        cout << "No suggestions available right now." << endl;
    }
    return true;
}