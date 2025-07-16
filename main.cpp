#include <exception>
#include <string>
#include <iostream>
#include "SDL2/SDL.h"
#include "include/System.h"

const int fps = 60;
const int frameDelay = 1000 / fps;


// g++ main.cpp -o app `sdl2-config --cflags --libs` -lSDL2_image

int main( int argc, char * argv[] )
{
    Uint32 frameStart;
    Uint32 frameTime;

    System* system = new System();
    
    system->init("Particle Dream", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, true);


    while(system->running()){
        frameStart = SDL_GetTicks();

        system->update();
        system->render();
        system->handleEvents();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    system->clean();

    return 0;
}