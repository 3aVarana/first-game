#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
private:
    double x, y;
    SDL_Rect currentFrame;
    SDL_Texture *tex;

public:
    Entity(double x, double y, SDL_Texture *tex);
};
