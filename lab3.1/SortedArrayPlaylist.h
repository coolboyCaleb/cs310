#ifndef SORTED_ARRAY_PLAYLIST_H
#define SORTED_ARRAY_PLAYLIST_H
#include <vector>
#include <algorithm>
#include "Song.h"

class SortedArrayPlaylist {
public:
    void addSong(const Song& s);
    void removeSong(const std::string& title);
    Song* getCurrentSong();
    void nextSong();
    void previousSong();
    int Length() const { return (int)songs.size(); }

    static SortedArrayPlaylist mergeSorted(const SortedArrayPlaylist& A, const SortedArrayPlaylist& B);

private:
    std::vector<Song> songs;
    int currentIndex = -1;
};

#endif