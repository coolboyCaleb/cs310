cmake_minimum_required(VERSION 3.10)

# Project name
project(MinHeapTaskSchedulerTests CXX)

# Use C++11 (or higher if you want)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable warnings
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Source files
set(SOURCES
    main.cpp
    MinHeap.cpp
)

# Header files (optional, just for IDEs)
set(HEADERS
    MinHeap.h
    Task.h
)

# Build the test executable
add_executable(scheduler_tests
    ${SOURCES}
    ${HEADERS}
)

# If you ever add tests using CTest, you can hook them here
# enable_testing()
# add_test(NAME MinHeapTests COMMAND scheduler_tests)