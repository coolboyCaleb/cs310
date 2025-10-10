#include "Playlist.h"
#include <iostream>

using namespace std;

static Node* findTail(Node* head) {
    Node* tail = head;
    while (tail && tail->next) {
        tail = tail->next;
    }
    return tail;
}
static Node* findPrev(Node* head, Node* node) {
    if (!head || head == node) {
        return nullptr;
    }
    Node* prev = head;
    while (prev && prev->next != node) 
    {
        prev = prev->next;
    }
    return prev;
}

void Playlist::addSong(const Song &song) {
    Insert(new Song(song));
    if (currentPos == nullptr) {currentPos = listData;
    }
}

void Playlist::removeSong(const std::string &title) {
    if (IsEmpty()) return;
    Song key(title, "", 0, "");
    int before = Length();
    Remove(key);
    if (Length() == before) return; // nothing removed

    // Fix selection if needed
    if (IsEmpty()) { currentPos = nullptr; return; }

    // Ensure currentPos still points to a live node; if not, pick head
    Node* curr = listData;
    bool ok = false;
    while (curr) { if (curr == currentPos) { ok = true; break; } curr = curr->next; }
    if (!ok) currentPos = listData;
}

Song* Playlist::getCurrentSong() {
    if (IsEmpty()) {return nullptr;}
    if (currentPos == nullptr) {currentPos = listData;}      // start at head
    return (Song*) currentPos->item;
}

void Playlist::nextSong() {
    if (IsEmpty()) {return;}
    if (currentPos == nullptr) { currentPos = listData; return; }
    currentPos = currentPos->next ? currentPos->next : listData; // wrap to head
}

void Playlist::previousSong() {
    if (IsEmpty()) return;
    if (currentPos == nullptr) { currentPos = listData; return; }

    if (currentPos == listData) {
        currentPos = findTail(listData);   // wrap to tail
    } else {
        Node* prev = findPrev(listData, currentPos);
        if (prev) currentPos = prev;       // move back one
    }
}

void Playlist::sortByTitle() {
    if (!listData || !listData->next) {return;}

    Node* sorted = nullptr;

    while (listData) {
        Node* node = listData;        // detach head
        listData = listData->next;
        node->next = nullptr;

        // Insert node into 'sorted' in order using ItemType::LessThan
        if (!sorted || node->item->LessThan(*sorted->item)) {
            node->next = sorted;
            sorted = node;
        } else {
            Node* p = sorted;
            while (p->next && !node->item->LessThan(*p->next->item)) {
                p = p->next;
            }
            node->next = p->next;
            p->next = node;
        }
    }

    listData = sorted;
    currentPos = listData; // after sorting, point to head
}