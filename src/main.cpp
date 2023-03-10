#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <headers/game.h>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    Game game;

    game.run();

    return EXIT_SUCCESS;
}
