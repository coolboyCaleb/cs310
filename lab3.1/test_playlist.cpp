#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "Playlist.h"
TEST_CASE("Playlist Operations") {
Playlist pl;
pl.addSong(Song("Song1", "Artist1", 200, "path1.mp3"));
pl.addSong(Song("Song2", "Artist2", 150, "path2.mp3"));
REQUIRE(pl.getLength() == 2);
// Add merge tests, e.g., merge two playlists and check order
}
Build with CMake: Create CMakeLists.txt:
cmake_minimum_required(VERSION 3.10)
project(MediaPlayer)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(tests test_playlist.cpp Playlist.cpp Song.cpp)
target_link_libraries(tests SFML::Graphics SFML::Audio Catch2::Catch2)
add_executable(player MediaPlayer.cpp Playlist.cpp Song.cpp)
target_link_libraries(player SFML::Graphics SFML::Audio)