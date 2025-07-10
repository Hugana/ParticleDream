#include <exception>
#include <string>
#include <iostream>
#include "SDL2/SDL.h"

const int fps = 60;
const int frameDelay = 1000 / fps;

int main( int argc, char * argv[] )
{
    Uint32 frameStart;
    Uint32 frameTime;

    while(true){
        frameStart = SDL_GetTicks();

  

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    return 0;
}