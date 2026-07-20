cmake_minimum_required(VERSION 3.20)
project(Spotify_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Spotify_Project
        main.cpp
        Account.cpp
        Album.cpp
        AlbumRepository.cpp
        ArtistRepository.cpp
        ListenerRepository.cpp
        Playlist.cpp
        PlaylistRepository.cpp
        Song.cpp
        SongRepository.cpp
        SpotifySystem.cpp
)