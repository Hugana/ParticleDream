#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>

class System{

    public:
        System();

        void update();
        void render();
        void clean();

        bool running;

        static SDL_Renderer* renderer;

    private:
        bool isRunning;
        SDL_Window* window;

};