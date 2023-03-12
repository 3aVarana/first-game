#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Vector2f.h"

class Entity
{
private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture *tex;

public:
    Entity(Vector2f p_pos, SDL_Texture *p_tex);

    Vector2f getPos();
    SDL_Texture *getTex();
    SDL_Rect getCurrentFrame();
};
