#include "Avatar.h"

Avatar::Avatar(int x, int y, int width, int height, SDL_Renderer* renderer)
    : rect{x, y, width, height}, speed(5), renderer(renderer) {}

// Handle keyboard input for movement
void Avatar::handleInput(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                rect.y -= speed;
            break;
            case SDLK_DOWN:
                rect.y += speed;
            break;
            default:
                break;
        }
    }
}

// Update avatar logic (e.g., constrain movement to screen bounds)
void Avatar::update() {
    if (rect.y < 0) rect.y = 0; // Prevent going off the top
    if (rect.y + rect.h > 600) rect.y = 600 - rect.h; // Prevent going off the bottom
}

// Render the avatar
void Avatar::render() const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
    SDL_RenderFillRect(renderer, &rect);
}

// Get the bounding box for collision detection
SDL_Rect& Avatar::getBounds() {
    return rect;
}
