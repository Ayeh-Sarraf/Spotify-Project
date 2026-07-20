#ifndef SPOTIFY_PROJECT_SPOTIFYSYSTEM_H
#define SPOTIFY_PROJECT_SPOTIFYSYSTEM_H

#include "ArtistRepository.h"
#include "ListenerRepository.h"
#include "AlbumRepository.h"
#include "SongRepository.h"
#include "PlaylistRepository.h"
#include <string>
#include <optional>
#include <iostream>
#include <vector>

using namespace std;

class SpotifySystem {
private:
    ArtistRepository artistRepo;
    ListenerRepository listenerRepo;
    AlbumRepository albumRepo;
    SongRepository songRepo;
    PlaylistRepository playlistRepo;

    int nextUserId = 1;
    int nextAlbumId = 1;
    int nextSongId = 1;
    int nextPlaylistId = 1;

public:
    bool registerUser(string fullName, string username, string password, string biography, string role);
    optional<Account> login(string username, string password);

    bool createAlbum(string artistId, string albumName);
    bool createSong(string artistId, string albumId, string title, int releaseYear, string genre, string filePath);

    bool createPlaylist(string listenerId, string playlistName);
    bool addSongToPlaylist(string listenerId, string playlistId, string songId);
    bool likeSong(string listenerId, string songId);

    bool suggestSongs(string listenerId);
};

#endif