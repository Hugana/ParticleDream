#pragma once
#include <SDL2/SDL.h>

namespace ColorUtils {
    SDL_Color oscillateColor(const SDL_Color& a, const SDL_Color& b, float speed);
    SDL_Color rainbowCycle(float t);
    SDL_Color lerpColor(const SDL_Color& a, const SDL_Color& b, float t);
}
