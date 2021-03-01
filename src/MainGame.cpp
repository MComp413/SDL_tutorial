#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>

#include "MainGame.hpp"
#include "Sprite.hpp"

void fatalError(std::string errorMessage)
{
    std::cout << errorMessage << SDL_GetError() << std::endl;
    SDL_Quit();
}

MainGame::MainGame()
{
    _window = nullptr;
    _screenWidth = 512;
    _screenHeight = 384;
    _gameState = GameState::PLAY;
    _sprite = Sprite();
}

void MainGame::run()
{
    initSystems();
    _sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);
    gameLoop();
}

void MainGame::initSystems()
{
    int initResult = SDL_Init(SDL_INIT_EVERYTHING);
    if(initResult != 0)
        fatalError("Error with system init");
    std::cout << "Systems initialized" << std::endl;

    _window = SDL_CreateWindow("GameEngine",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
    if(_window == nullptr)
        fatalError("Error with window creation");
    std::cout << "Window created" << std::endl;

    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if(glContext == nullptr)
        fatalError("Error with glContext creation");
    std::cout << "GLContext created" << std::endl;

    GLenum glewErr = glewInit();
    if(glewErr != GLEW_OK)
        fatalError("Error with glew initializing");
    std::cout << "glew initialized" << std::endl;

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    glClearColor(1.0f, 0.0f, 0.3f, 1.0f);
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

void MainGame::drawGame()
{
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _sprite.draw();
    SDL_GL_SwapWindow(_window);
}

void MainGame::gameLoop()
{
    while(_gameState != GameState::EXIT)
    {
        processInput();
        drawGame();
    }
}

MainGame::~MainGame()
{

}