#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Playlist.h"
class MediaPlayer
{
private:
    sf::RenderWindow window;
    sf::Music music; // SFML's music player for MP3
    Playlist playlist;
    int currentIndex;
    bool isPlaying;
    // GUI elements
    sf::Font font;
    sf::Text currentSongText;
    sf::RectangleShape playButton;
    std::string loadedPath; // track what's loaded
    sf::RectangleShape nextButton, prevButton;
    sf::Text playLabel, nextLabel, prevLabel;
    sf::RectangleShape progressBG, progressFill;
    std::string loadedPath; // keeps track of currently loaded songc
public:
    MediaPlayer();
    void run();
    void handleEvents();
    void update();
    void render();
    void loadCurrentSong();           // open file, reset offset, update UI
    void loadPlaylist(const std::string &directory); // Load MP3s from folder
};
#endif