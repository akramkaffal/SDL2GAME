#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "Avatar.h"
#include <vector>

#include "Hazard.h"


class Game {
public:
    Game(int screenWidth, int screenHeight, SDL_Renderer* renderer);
    ~Game() = default;

    bool run(); // Main game loop function

private:
    void handleEvents();
    void update();
    void render() const;
    std::vector<Hazard*> hazards; //vector to store hazards
    void spawnHazard();


    // Game state management
    enum GameState { MENU, RUNNING, GAME_OVER };
    GameState currentState;

    // Core properties
    SDL_Renderer* renderer;
    int screenWidth;
    int screenHeight;

    // Player properties
    int playerHealth;
    int playerScore;

    // Avatar
    Avatar* avatar;

    // Helper methods
    void startGame();
    void endGame();
    void displayMenu() ;
};

#endif
