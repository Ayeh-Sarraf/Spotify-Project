#ifndef SPOTIFY_PROJECT_SONG_H
#define SPOTIFY_PROJECT_SONG_H
using namespace std;

class Song {
private:
    string songId;
    string name;
    int releaseYear;
    string genre;
    string audioFileName;
    string artistId;
    string albumId;

public:
    Song(string songId, string name, int releaseYear, string genre, string audioFileName, string artistId, string albumId);

    string getSongId() const;
    string getName() const;
    int getReleaseYear() const;
    string getGenre() const;
    string getAudioFileName() const;
    string getArtistId() const;
    string getAlbumId() const;
};
#endif
