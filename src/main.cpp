#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "MainGame.hpp"

int main(int argc, char** argv)
{
    MainGame mainGame;
    mainGame.run();
    return 0;
}