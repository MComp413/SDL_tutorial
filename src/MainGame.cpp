#include <iostream>
#include "MainGame.hpp"

MainGame::MainGame()
{
    _window = nullptr;
    _screenWidth = 512;
    _screenHeight = 384;
    _gameState = GameState::PLAY;
}

void MainGame::run()
{
    int initResult = initSystems();
    if(initResult != 0)
    {
        SDL_Quit();
        return;
    }

    gameLoop();
}

int MainGame::initSystems()
{
    int initResult = SDL_Init(SDL_INIT_EVERYTHING);
    if(initResult != 0)
    {
        std::cout << "Error with system init" << SDL_GetError() << std::endl;
        return initResult;
    }
    std::cout << "Systems initialized" << std::endl;

    _window = SDL_CreateWindow("GameEngine",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
    
    if(_window == nullptr)
    {
        initResult = 1;
        std::cout << "Error with window init" << SDL_GetError() << std::endl;
        return initResult;
    }

    std::cout << "Window opened" << std::endl;

    return initResult;
}

void MainGame::processInput()
{
    SDL_Event evnt;
    while(SDL_PollEvent(&evnt))
    {
        switch(evnt.type)
        {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
            case SDL_MOUSEMOTION:
                std::cout << "Mouse position: " << evnt.motion.x << ", " << evnt.motion.y << std::endl;
                break;
        }
    }
}

void MainGame::gameLoop()
{
    while(_gameState != GameState::EXIT)
    {
        processInput();
    }
}

MainGame::~MainGame()
{

}