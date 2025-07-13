#include "../include/Particle.h"
#include "../include/System.h"

void System::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    Uint32 flags = 0;

    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystem Initialised... \n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(window){
            std::cout << "Window created! \n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 10, 10, 10, 0);
            std::cout << "Renderer created! \n";
        }
        
        isRunning = true;

        particleVector.push_back(Particle(Vector2D(100, 100), 1.0f, 1.0f, 0.0f, 0.0f, 0, 0, 32, 32));

    } else {
        isRunning = false;
    }
}

void System::update(){
    for (Particle p : particleVector){
        p.update();
    }
}

void System::render(){
    for (Particle p : particleVector){
        p.draw();
    }
}


