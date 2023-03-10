#include <headers/game.h>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout<<"HEY.. SDL_Init HA ";
    }

    Game game;

    game.run();

    return EXIT_SUCCESS;
}
