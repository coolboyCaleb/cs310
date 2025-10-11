#include "MediaPlayer.h"
#include <filesystem> // For directory iteration (C++17)
MediaPlayer::MediaPlayer()
    : window(sf::VideoMode(800, 600), "SFML Media Player"),
      currentIndex(0), isPlaying(false)
{
    window.setFramerateLimit(60); // smoother without vsync

    if (!font.loadFromFile("Roboto-Regular.ttf"))
    {
        std::cout << "Warning: could not load Roboto font. Text may not display.\n";
    }

    // --- Title text ---
    currentSongText.setFont(font);
    currentSongText.setCharacterSize(32);
    currentSongText.setFillColor(sf::Color::White);
    currentSongText.setString("No song loaded");
    currentSongText.setPosition(24.f, 20.f);

    // --- Buttons (bigger, with outlines) ---
    playButton.setSize({140.f, 44.f});
    playButton.setPosition(24.f, 540.f);
    nextButton.setSize({140.f, 44.f});
    nextButton.setPosition(24.f + 156.f, 540.f);
    prevButton.setSize({140.f, 44.f});
    prevButton.setPosition(24.f + 312.f, 540.f);

    auto styleButton = [&](sf::RectangleShape &r)
    {
        r.setFillColor(sf::Color(230, 230, 230));
        r.setOutlineColor(sf::Color::White);
        r.setOutlineThickness(2.f);
    };
    styleButton(playButton);
    styleButton(nextButton);
    styleButton(prevButton);

    // --- Labels (centered on buttons) ---
    auto styleLabel = [&](sf::Text &t, const std::string &s, float x, float y)
    {
        t.setFont(font);
        t.setString(s);
        t.setCharacterSize(18);
        t.setFillColor(sf::Color::Black);
        // center text within button rect
        auto bounds = t.getLocalBounds();
        t.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
        t.setPosition(x + 70.f, y + 22.f); // half of 140x44
    };
    styleLabel(playLabel, "Play/Pause", playButton.getPosition().x, playButton.getPosition().y);
    styleLabel(nextLabel, "Next", nextButton.getPosition().x, nextButton.getPosition().y);
    styleLabel(prevLabel, "Prev", prevButton.getPosition().x, prevButton.getPosition().y);

    // --- Progress bar ---
    progressBG.setSize({752.f, 10.f});
    progressBG.setPosition(24.f, 500.f);
    progressBG.setFillColor(sf::Color(60, 60, 60));

    progressFill.setSize({0.f, 10.f});
    progressFill.setPosition(24.f, 500.f);
    progressFill.setFillColor(sf::Color(0, 190, 0));
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

        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            // --- Play / Pause ---
            if (playButton.getGlobalBounds().contains(mousePos))
            {
                if (!isPlaying)
                {
                    if (loadedPath.empty())
                    {
                        if (!loadCurrentSong())
                            return; // prevent SFML error
                    }
                    music.play();
                    isPlaying = true;
                }
                else
                {
                    music.pause();
                    isPlaying = false;
                }
            }

            // --- Next song ---
            if (nextButton.getGlobalBounds().contains(mousePos))
            {
                playlist.nextSong();
                if (loadCurrentSong())
                {
                    music.play();
                    isPlaying = true;
                }
            }

            // --- Previous song ---
            if (prevButton.getGlobalBounds().contains(mousePos))
            {
                playlist.previousSong();
                if (loadCurrentSong())
                {
                    music.play();
                    isPlaying = true;
                }
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
    sf::Vector2f mp = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    auto hover = [&](sf::RectangleShape &r)
    {
        if (r.getGlobalBounds().contains(mp))
            r.setFillColor(sf::Color(255, 255, 255));
        else
            r.setFillColor(sf::Color(230, 230, 230));
    };
    hover(playButton);
    hover(nextButton);
    hover(prevButton);
}
void MediaPlayer::render()
{
    // Clear the window (background color)
    window.clear(sf::Color::Black);

    // --- Song title/artist text ---
    window.draw(currentSongText);

    // --- Progress bar ---
    window.draw(progressBG);
    window.draw(progressFill);

    // --- Buttons ---
    window.draw(playButton);
    window.draw(nextButton);
    window.draw(prevButton);

    // --- Button labels ---
    window.draw(playLabel);
    window.draw(nextLabel);
    window.draw(prevLabel);

    // Display everything
    window.display();
}

bool MediaPlayer::loadCurrentSong()
{
    Song *cur = playlist.getCurrentSong();
    if (!cur)
    {
        music.stop();
        currentSongText.setString("No song loaded");
        loadedPath.clear();
        return false;
    }

    if (loadedPath == cur->filePath)
        return true; // already loaded

    if (!music.openFromFile(cur->filePath))
    {
        std::cout << "Failed to open: " << cur->filePath << "\n";
        currentSongText.setString("Failed to load: " + cur->title);
        loadedPath.clear();
        return false;
    }

    music.setPlayingOffset(sf::Time::Zero);
    loadedPath = cur->filePath;
    currentSongText.setString(cur->title + " - " + cur->artist);
    return true;
}

void MediaPlayer::loadPlaylist(const std::string &directory)
{
    int count = 0;
    for (const auto &entry : std::filesystem::directory_iterator(directory))
    {
        auto ext = entry.path().extension().string();
        if (ext == ".mp3" || ext == ".ogg") // supports both types
        {
            Song s(entry.path().stem().string(), "Sample Artist", 0, entry.path().string());
            playlist.addSong(s);
            std::cout << "Loaded: " << s.filePath << "\n";
            ++count;
        }
    }

    std::cout << "Total songs loaded: " << count << std::endl;

    loadedPath.clear();
    loadCurrentSong(); // load the first song so play/pause works
    isPlaying = false;
}