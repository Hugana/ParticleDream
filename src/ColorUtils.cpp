#include "../include/ColorUtils.h"
#include <cmath>
#include <algorithm>

SDL_Color ColorUtils::lerpColor(const SDL_Color& a, const SDL_Color& b, float t) {
    SDL_Color result;
    result.r = static_cast<Uint8>(a.r + (b.r - a.r) * t);
    result.g = static_cast<Uint8>(a.g + (b.g - a.g) * t);
    result.b = static_cast<Uint8>(a.b + (b.b - a.b) * t);
    return result;
}

SDL_Color ColorUtils::oscillateColor(const SDL_Color& a, const SDL_Color& b, float speed) {
    float time = SDL_GetTicks() / 1000.0f;
    float factor = (sinf(time * speed) + 1.0f) / 2.0f;
    return lerpColor(a, b, factor);
}

SDL_Color ColorUtils::rainbowCycle(float t) {
    t = fmod(t, 1.0f);
    float r = fabs(fmod(t * 6.0f + 0.0f, 6.0f) - 3.0f) - 1.0f;
    float g = fabs(fmod(t * 6.0f + 4.0f, 6.0f) - 3.0f) - 1.0f;
    float b = fabs(fmod(t * 6.0f + 2.0f, 6.0f) - 3.0f) - 1.0f;

    return SDL_Color{
        Uint8(std::clamp(r, 0.0f, 1.0f) * 255),
        Uint8(std::clamp(g, 0.0f, 1.0f) * 255),
        Uint8(std::clamp(b, 0.0f, 1.0f) * 255)
    };
}
