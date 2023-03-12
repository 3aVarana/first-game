#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.h"

enum GameState
{
    PLAY,
    EXIT
};

class Game
{
public:
    Game();
    ~Game();

    void run();

    SDL_Texture *loadTexture(const char *p_filePath);
    void cleanUp();
    void clear();
    void render(Entity &p_entity);
    void display();

private:
    void init(const char *title, int x, int y, int w, int h, Uint32 flags);
    void gameLoop();
    void handleEvents();

    SDL_Window *window;
    SDL_Renderer *renderer;

    int screenWidth;
    int screenHeight;

    GameState gameState;
    SDL_Event event;
};
