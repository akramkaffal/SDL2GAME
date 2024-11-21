#ifndef AVATAR_H
#define AVATAR_H

#include <SDL2/SDL.h>

class Avatar {
public:
    Avatar(int x, int y, int width, int height, SDL_Renderer* renderer);
    ~Avatar() = default;

    void handleInput(const SDL_Event& event);
    void update();
    void render() const;

    SDL_Rect& getBounds(); // For collision detection

private:
    SDL_Rect rect; // Position and size of the avatar
    int speed;     // Movement speed
    SDL_Renderer* renderer;
};

#endif
