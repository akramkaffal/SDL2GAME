#ifndef HAZARD_H
#define HAZARD_H

#include <SDL2/SDL.h>

class Hazard {
public:
    Hazard(int x, int y, int width, int height, int speed, SDL_Renderer* renderer);
    ~Hazard() = default;

    void update();          // Update position
    void render() const;    // Render the hazard
    bool isOffScreen() const; // Check if the hazard has left the screen
    SDL_Rect& getBounds(); // For collision detection

private:
    SDL_Rect rect; // Position and size of the hazard
    int speed;     // Movement speed
    SDL_Renderer* renderer;
};

#endif
