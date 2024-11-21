#include "Hazard.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
Hazard::Hazard(int x, int y, int width, int height, int speed, SDL_Renderer* renderer)
    : rect{x, y, width, height}, speed(speed), renderer(renderer) {
    this->speed = 1;
}

// Update position
void Hazard::update() {
    rect.x -= speed; // Move left by speed
}

// Render the hazard
void Hazard::render() const {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &rect);
}

// Check if the hazard is off the screen
bool Hazard::isOffScreen() const {
    return rect.x + rect.w < 0; // Completely out of the left side
}

// Get the bounding box for collision detection
SDL_Rect& Hazard::getBounds() {
    return rect;
}
