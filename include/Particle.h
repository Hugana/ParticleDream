#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector2D.h"

class Particle {
    public:
        Particle(Vector2D pos, float size, float r, float g, float b);
        virtual ~Particle();

        void init();

        void move(Vector2D dir);

        void draw();

        SDL_Texture* texture;

        Vector2D pos;
        float size, r, g, b;
};