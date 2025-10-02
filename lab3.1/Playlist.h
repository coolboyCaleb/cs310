#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Song.h"
#include "UnsortedLinkedList.h"

class Playlist : public UnsortedLinkedList
{
public:
    void addSong(const Song &song);
    void removeSong(const std::string &title);
    Song *getCurrentSong(); // Returns current playing song
    void nextSong();        // Move to next in list
    void previousSong();    // Move to previous
    // Add sorting method later
    void sortByTitle();
};
#endif