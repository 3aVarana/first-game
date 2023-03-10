#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

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
    cleanUp();
}

void Game::run()
{
    init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    gameLoop();
}

SDL_Texture *Game::loadTexture(const char *p_filePath)
{
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void Game::cleanUp()
{
    SDL_DestroyWindow(window);
}

void Game::clear()
{
    SDL_RenderClear(renderer);
}

void Game::render(SDL_Texture *p_tex)
{
    SDL_RenderCopy(renderer, p_tex, nullptr, nullptr);
}

void Game::display()
{
    SDL_RenderPresent(renderer);
}

void Game::init(const char *title, int x, int y, int w, int h, Uint32 flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, x, y, w, h, flags);

    if (window == nullptr)
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, 0);
}

void Game::gameLoop()
{
    SDL_Texture *grassTexture = loadTexture("res/gfx/ground_grass_1.png");

    while (gameState != GameState::EXIT)
    {
        handleEvents();

        clear();
        render(grassTexture);
        display();
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
