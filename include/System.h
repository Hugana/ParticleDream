#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <vector>
#include "Particle.h"

class System{

    public:
        System();
        ~System();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void update();
        void render();
        void clean();
        bool running();

        static SDL_Renderer* renderer;



    private:
        bool isRunning;
        std::vector<Particle> particleVector;
        
        SDL_Window* window;
};