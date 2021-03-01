#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "GameState.hpp"
#include "Sprite.hpp"

class MainGame
{
public:
    MainGame();
    ~MainGame();

    void run();
private:
    int _screenWidth, _screenHeight;
    SDL_Window* _window;
    GameState _gameState;
    Sprite _sprite;
    
    void initSystems();
    void gameLoop();
    void processInput();
    void drawGame();
};