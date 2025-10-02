#include "Song.h"
#include <string>

using namespace std;

Song::Song(const string &t, const string &a, int d, const string &path) : title(t), artist(a), duration(d), filePath(path) {}
bool Song::operator<(const Song &other) const
{
    return title < other.title; // Sort by title alphabetically
}