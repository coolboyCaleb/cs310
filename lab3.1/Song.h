#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song
{
public:
    string title;
    string artist;
    int duration;                                                      // in seconds
    string filePath;                                                   // path to MP3 file
    Song(const string &t, const string &a, int d, const string &path); /// constructor
    bool operator<(const Song &other) const;                           // For potential sorting
};

#endif