#include <headers/game.h>

Game::Game()
{
    window = nullptr;
    renderer = nullptr;
    screenWidth = 1024;
    screenHeight = 600;
    gameState = GameState::PLAY;
}

Game::~Game()
{
    SDL_DestroyWindow(window);
}

void Game::run()
{
    init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    gameLoop();
}

void Game::init(const char *title, int x, int y, int w, int h, Uint32 flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, x, y, w, h, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void Game::gameLoop()
{
    while (gameState != GameState::EXIT)
    {
        handleEvents();
    }
}

void Game::handleEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            /* code */
            gameState = GameState::EXIT;
            break;

        default:
            break;
        }
    }
}
