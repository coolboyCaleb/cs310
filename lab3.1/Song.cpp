#include "Song.h"
#include <string>
using namespace std;

Song::Song(const string &t, const string &a, int d, const string &path) : title(t), artist(a), duration(d), filePath(path) {}

bool Song::operator<(const Song &other) const {
    return title < other.title;
}

bool Song::CompareTo(const ItemType &other) const {
    const Song &rhs = static_cast<const Song&>(other);
    return title == rhs.title;  // equal if titles match
}

bool Song::LessThan(const ItemType &other) const {
    // For sorting, compare alphabetically by title, then artist
    const Song &rhs = static_cast<const Song&>(other);
    if (title != rhs.title) return title < rhs.title;
    return artist < rhs.artist;
}

void Song::Print(ostream &out) const {
    out << title << " — " << artist << " (" << duration << "s)";
}