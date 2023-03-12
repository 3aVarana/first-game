#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include <headers/game.h>
#include <headers/Entity.h>
#include <headers/Vector2f.h>

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

void Game::render(Entity &p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getPos().x * 4;
    dst.y = p_entity.getPos().y * 4;
    dst.w = p_entity.getCurrentFrame().w * 4;
    dst.h = p_entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
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

    // Entity entitiy0(100, 50, grassTexture);
    std::vector<Entity> entities = {
        Entity(Vector2f(0, 0), grassTexture),
        Entity(Vector2f(30, 0), grassTexture),
        Entity(Vector2f(30, 30), grassTexture),
        Entity(Vector2f(30, 60), grassTexture),
    };

    {
        Entity wilson(Vector2f(100, 50), grassTexture);
        entities.push_back(wilson);
    }

    while (gameState != GameState::EXIT)
    {
        handleEvents();

        clear();

        for (Entity &e : entities)
        {
            render(e);
        }

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
