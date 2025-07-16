#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <vector>
#include "Particle.h"
#include "PerlinGrid.h"
class System{
    public:
        System();
        ~System();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void update();
        void render();
        void clean();
        bool running();
        void handleEvents();
        static SDL_Renderer* renderer;
    private:
        int screenWidth, screenHeight;
        bool isRunning;
        std::vector<Particle> particleVector;
        PerlinGrid grid;
        SDL_Window* window;
};