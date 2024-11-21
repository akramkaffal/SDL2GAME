cmake_minimum_required(VERSION 3.29)
project(SDL2GAME)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_IMAGE_LIBRARY_DIRS} ${SDL2_MIXER_LIBRARY_DIRS})
# Include directories
include_directories(
        /opt/homebrew/include
        /opt/homebrew/Cellar/sdl2_image/2.8.2_2/include/SDL2
        /opt/homebrew/Cellar/sdl2_mixer/2.8.0/include/SDL2
)

# Library directories
link_directories(
        /opt/homebrew/lib
        /opt/homebrew/Cellar/sdl2_image/2.8.2_2/lib
        /opt/homebrew/Cellar/sdl2_mixer/2.8.0/lib
)
add_executable(SDL2GAME src/main.cpp src/Game.cpp src/Avatar.cpp src/Hazard.cpp src/PowerUp.cpp src/Background.cpp
        src/Game.h
        src/Avatar.h
        src/Hazard.h
        src/PowerUp.h)

target_link_libraries(SDL2GAME ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES})
target_link_libraries(SDL2GAME
        /opt/homebrew/Cellar/sdl2_image/2.8.2_2/lib/libSDL2_image.dylib
)

