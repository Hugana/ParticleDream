#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "Vector2D.h"

class Particle {
    public:
        Particle(Vector2D pos, float size, float r, float g, float b,  int srcX, int srcY, int srcW, int srcH);
        virtual ~Particle();

        void init();

        void move(Vector2D dir);

        void draw();

        void update();

        void wrapAround(int width, int height);
        Vector2D previousPos;
        Vector2D getPosition();

        
        static void loadTexture();
        static SDL_Texture* texture;

        Vector2D pos;
        float size, r, g, b;
        SDL_Rect srcRect, destRect;
};