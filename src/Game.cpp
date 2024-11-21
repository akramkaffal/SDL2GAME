#include "Game.h"
#include <iostream>

// Constructor
Game::Game(int screenWidth, int screenHeight, SDL_Renderer* renderer)
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight),
      currentState(MENU), playerHealth(3), playerScore(0) {
    avatar = new Avatar(50, screenHeight / 2 - 25, 50, 50, renderer); // Position and size
}


// Main game loop function
bool Game::run() {
    std::cout << "Current State: " << currentState << std::endl;
    switch (currentState) {
        case MENU:
            displayMenu();
            break;
        case RUNNING:
            handleEvents();
            update();
            render();
            break;
        case GAME_OVER:
            endGame();
            break;
    }
    return currentState != GAME_OVER; // Exit loop if the game state is GAME_OVER
}

// Handle player input
void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            currentState = GAME_OVER;
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                currentState = MENU;
            }
        }
    }
}

// Update game logic
void Game::update() {
    static int hazardSpawnTimer = 0; // Timer to control spawning
    avatar->update();
    // Increment the timer
    hazardSpawnTimer++;
    // Spawn a hazard every 60 frames (about 1 second at 60 FPS)
    if (hazardSpawnTimer >= 60) {
        spawnHazard();
        hazardSpawnTimer = 0; // Reset the timer
    }

    // Update hazards
    for (auto it = hazards.begin(); it != hazards.end();) {
        (*it)->update();

        // Check for collisions with the avatar
        if (SDL_HasIntersection(&((*it)->getBounds()), &(avatar->getBounds()))) {
            playerHealth--; // Reduce health on collision
            delete *it;     // Remove hazard
            it = hazards.erase(it);
        }
        // Remove off-screen hazards
        else if ((*it)->isOffScreen()) {
            delete *it;
            it = hazards.erase(it);
        } else {
            ++it;
        }
    }

    // Spawn new hazards periodically
   // if (rand() % 100 < 5) { // 5% chance each frame
   //     spawnHazard();
   // }

    // Decrease health if playerHealth reaches zero
    if (playerHealth <= 0) {
        currentState = GAME_OVER;
    }

    playerScore++; // Increment score
}


// Render the game
void Game::render() const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear screen with black
    SDL_RenderClear(renderer);

    avatar->render(); // Render the avatar
    // Render hazards
    for (const auto& hazard : hazards) {
        hazard->render();
    }

    SDL_RenderPresent(renderer); // Present the updated screen

}


    // Placeholder for rendering game objects (player, hazards, etc.)

// Display the main menu
void Game::displayMenu() {
    std::cout << "Main Menu - Press Enter to Start the Game" << std::endl;

    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
            currentState = RUNNING; // Transition to RUNNING state
            break;                  // Exit the loop
        } else if (event.type == SDL_QUIT) {
            currentState = GAME_OVER; // Exit the game
            break;
        }
    }
}


// Start the game
void Game::startGame() {
    currentState = RUNNING;
    playerHealth = 3;
    playerScore = 0;
}

void Game::spawnHazard() {
    int y = rand() % (screenHeight - 50); // Random y position
    hazards.push_back(new Hazard(screenWidth, y, 50, 50, 5, renderer));
}


// End the game and show the final score
void Game::endGame() {
    std::cout << "Game Over! Final Score: " << playerScore << std::endl;
    currentState = MENU;
}
