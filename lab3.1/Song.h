#ifndef SONG_H
#define SONG_H
#include "ItemType.h"
#include <string>

using namespace std;

class Song : public ItemType
{
public:
    string title;
    string artist;
    int duration;                                                      // in seconds
    string filePath;                                                   // path to MP3 file
    Song(const string &t, const string &a, int d, const string &path); /// constructor
    bool operator<(const Song &other) const;                           // For potential sorting
    bool CompareTo(const ItemType &other) const override; // equality by title (simple remove-by-title)
    bool LessThan(const ItemType &other) const override;  // order by title (tie-break by artist)
    void Print(std::ostream &out) const override;         // "[title — artist (123s)]"
};

#endif