#include "../include/Particle.h"
#include "../include/System.h"
#include <SDL2/SDL_image.h>

SDL_Renderer* System::renderer = nullptr;

System::System() {}

System::~System() {}

void System::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    Uint32 flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized.\n";

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) std::cout << "Window created.\n";

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
            std::cout << "Renderer created.\n";
        }

        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
            std::cerr << "IMG_Init failed: " << IMG_GetError() << "\n";
            isRunning = false;
            return;
        }

        int w, h;
        SDL_GetWindowSize(window, &w, &h);
        std::cout << "Window size: " << w << "x" << h << "\n";

        isRunning = true;

        int width, height;
        SDL_GetWindowSize(window, &width, &height);

        grid = PerlinGrid();
        grid.init(width, height,0.003,4);

        Particle::loadTexture();
        //SDL_SetTextureColorMod(Particle::texture, 255, 0, 0);
        Particle p = Particle(Vector2D(100, 100), 1.0f, 1.0f, 0.0f, 0.0f, 0, 0, 32, 32);
        

        particleVector.push_back(p);
        
    } else {
        isRunning = false;
    }
}

void System::update() {
    grid.update();
    for (Particle& p : particleVector) {
        Vector2D pos = p.getPosition();
        p.move(grid.getValueAtPosition(pos.getX(), pos.getY()));
        p.update();
    }
}

void System::render() {
    //SDL_RenderClear(renderer);
    for (Particle& p : particleVector) {
        p.draw();
    }
    SDL_RenderPresent(renderer);
}

void System::clean() {
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game cleaned.\n";
}

bool System::running() {
    return isRunning;
}

void System::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_SPACE) {
                    std::cout << "SPACE pressed → quitting.\n";
                    isRunning = false;
                }
                break;

            default:
                break;
        }
    }
}

