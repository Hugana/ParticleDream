#include "../include/Particle.h"
#include "../include/System.h"
#include <SDL2/SDL_image.h>
#include <random>
#include "../include/pcg_random.hpp"

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

        isRunning = true;

        SDL_GetWindowSize(window, &screenWidth, &screenHeight);
        grid = PerlinGrid();
        grid.init(screenWidth, screenHeight, 0.08f, 3.0f);

        Particle::loadTexture();

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"); // Nearest (pixelated)

        pcg_extras::seed_seq_from<std::random_device> seed_src;
        pcg32 rng(seed_src); // This will give a new seed on every run
 

        std::uniform_int_distribution<int> distX(0, screenWidth - 1);
        std::uniform_int_distribution<int> distY(0, screenHeight - 1);

        for (int nParticles = 0; nParticles < 200; ++nParticles) {
            int x = distX(rng);
            int y = distY(rng);

            Particle p(Vector2D(x, y), 1.0f, 1.0f, 0.0f, 0.0f, 0, 0, 2, 2);
            particleVector.push_back(p);
        }

        SDL_SetTextureColorMod(Particle::texture, 255, 140,0);
        SDL_SetTextureAlphaMod(Particle::texture, 30);
        
    } else {
        isRunning = false;
    }
}

void System::update() {
    grid.update();
    for (Particle& p : particleVector) {
        Vector2D pos = p.getPosition();
        p.update();
        p.move(grid.getValueAtPosition(pos.getX(), pos.getY()));
        p.wrapAround(screenWidth, screenHeight);
        
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

