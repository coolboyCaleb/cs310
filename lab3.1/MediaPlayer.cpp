#include "MediaPlayer.h"
#include <filesystem> // For directory iteration (C++17)
MediaPlayer::MediaPlayer() : window(sf::VideoMode(800, 600), "SFML Media Player"),
                             currentIndex(0), isPlaying(false)
{
    if (!font.loadFromFile("arial.ttf"))
    { // Download a free font or use system default
      // Handle error
    }
    // Initialize GUI elements...
    currentSongText.setFont(font);
    currentSongText.setString("No song loaded");
    currentSongText.setPosition(10, 10);
    // Buttons
    playButton.setSize({120.f, 40.f});
    playButton.setPosition(10.f, 540.f);
    nextButton.setSize({120.f, 40.f});
    nextButton.setPosition(140.f, 540.f);
    prevButton.setSize({120.f, 40.f});
    prevButton.setPosition(270.f, 540.f);

    // Labels
    playLabel.setFont(font);
    playLabel.setString("Play/Pause");
    playLabel.setCharacterSize(18);
    playLabel.setPosition(18.f, 546.f);

    nextLabel.setFont(font);
    nextLabel.setString("Next");
    nextLabel.setCharacterSize(18);
    nextLabel.setPosition(170.f, 546.f);

    prevLabel.setFont(font);
    prevLabel.setString("Prev");
    prevLabel.setCharacterSize(18);
    prevLabel.setPosition(305.f, 546.f);

    // Progress bar
    progressBG.setSize({760.f, 12.f});
    progressBG.setPosition(20.f, 500.f);
    progressFill.setSize({0.f, 12.f});
    progressFill.setPosition(20.f, 500.f);
    progressBG.setFillColor(sf::Color(100, 100, 100));
    progressFill.setFillColor(sf::Color(0, 200, 0));
}
void MediaPlayer::run()
{
    while (window.isOpen())
    {
        handleEvents();
        update();
        render();
    }
}
void MediaPlayer::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        // Handle button clicks (e.g., if mouse intersects playButton)
        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (playButton.getGlobalBounds().contains(mousePos))
            {
                if (isPlaying)
                {
                    music.pause();
                    isPlaying = false;
                }
                else
                {
                    music.play();
                    isPlaying = true;
                }
            }
            if (nextButton.getGlobalBounds().contains(mousePos))
            {
                playlist.nextSong();
                loadCurrentSong();
                music.play();
                isPlaying = true;
            }
            if (prevButton.getGlobalBounds().contains(mousePos))
            {
                playlist.previousSong();
                loadCurrentSong();
                music.play();
                isPlaying = true;
            }
            if (nextButton.getGlobalBounds().contains(mousePos))
            {
                playlist.nextSong();
                loadCurrentSong();
                music.play();
                isPlaying = true;
            }
            if (prevButton.getGlobalBounds().contains(mousePos))
            {
                playlist.previousSong();
                loadCurrentSong();
                music.play();
                isPlaying = true;
            }
        }
    }
}
void MediaPlayer::update()
{
    // Automatically advance to the next song when the current one finishes
    if (music.getStatus() == sf::SoundSource::Stopped && isPlaying && playlist.Length() > 0)
    {
        playlist.nextSong();
        loadCurrentSong();
        music.play();
    }

    // Update the progress bar as the song plays
    if (music.getDuration().asSeconds() > 0)
    {
        float ratio = music.getPlayingOffset().asSeconds() / music.getDuration().asSeconds();
        ratio = std::max(0.f, std::min(1.f, ratio)); // clamp 0–1
        progressFill.setSize({760.f * ratio, 12.f});
    }
}
void MediaPlayer::render()
{
    window.clear();
    window.draw(currentSongText);
    window.draw(playButton); // Draw buttons, list, etc.
    window.display();
}
void MediaPlayer::loadCurrentSong()
{
    Song *cur = playlist.getCurrentSong();
    if (!cur)
    {
        music.stop();
        currentSongText.setString("No song loaded");
        return;
    }

    if (loadedPath == cur->filePath)
        return; // already loaded

    if (!music.openFromFile(cur->filePath))
    {
        currentSongText.setString("Failed to load: " + cur->title);
        return;
    }
    music.setPlayingOffset(sf::Time::Zero);
    loadedPath = cur->filePath;
    currentSongText.setString(cur->title + " - " + cur->artist);
}

void MediaPlayer::loadPlaylist(const std::string &directory)
{
    for (const auto &entry : std::filesystem::directory_iterator(directory))
    {
        if (entry.path().extension() == ".mp3")
        {
            // Parse metadata or hardcode for simplicity
            Song song("Sample Title", "Sample Artist", 180, entry.path().string());
            playlist.addSong(song);
        }
    }
}