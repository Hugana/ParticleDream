#include <SDL2/SDL_video.h>
#include <exception>
#include <string>
#include <iostream>
#include "SDL2/SDL.h"
#include "include/System.h"
#include "include/Config.h"

const int fps = 90;
const int frameDelay = 1000 / fps;


// g++ main.cpp -o app `sdl2-config --cflags --libs` -lSDL2_image

int main( int argc, char * argv[] )
{
    Uint32 frameStart;
    Uint32 frameTime;

    Config appConfig;
    Config::GameConfig cfg = appConfig.load("config.yaml");

    System* system = new System();

    system->init(
        cfg.window.title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        cfg.window.width,
        cfg.window.height,
        cfg.window.fullscreen
    );


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