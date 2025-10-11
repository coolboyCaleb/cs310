#include "MediaPlayer.h"
#include <iostream>

int main()
{
    MediaPlayer app;

    // Load MP3s from a folder relative to where the executable runs.
    // Create a folder named "music" in the same directory as your project
    // and place a few .mp3 files inside it.
    std::string folder = "music";

    std::cout << "Loading playlist from: " << folder << std::endl;
    app.loadPlaylist(folder);

    std::cout << "Starting Media Player..." << std::endl;
    app.run();

    std::cout << "Media Player closed successfully." << std::endl;
    return 0;
}