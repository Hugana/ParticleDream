#include "../include/Particle.h"
#include "../include/System.h"
#include <SDL2/SDL_image.h>

SDL_Texture* Particle::texture = nullptr;


Particle::Particle(Vector2D posVector, float particleSize, float red, float green, float blue,  int srcX, int srcY, int srcW, int srcH){
    pos = posVector;
    size = particleSize;
    r = red;
    g = green;
    b = blue;
    srcRect.x = srcX;
    srcRect.y = srcY;
    srcRect.w = srcW;
    srcRect.h = srcH;
}

Particle::~Particle() {}

void Particle::move(Vector2D dir){
    pos += dir;
};

void Particle::draw(){
    SDL_RenderCopy(System::renderer, texture, &srcRect, &destRect);
}

void Particle::update(){
    destRect.x = pos.getX();
    destRect.y = pos.getY();
    destRect.w = srcRect.w * 0.3;
    destRect.h = srcRect.h * 0.3;
}

void Particle::loadTexture() {
    if (texture) return; 

    SDL_Surface* tmpSurface = IMG_Load("assets/particle.png");
    if (!tmpSurface) {
        std::cerr << "IMG_Load failed: " << IMG_GetError() << "\n";
        return;
    }

    Particle::texture = SDL_CreateTextureFromSurface(System::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    if (!Particle::texture) {
        std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << "\n";
    } else {
        SDL_SetTextureBlendMode(Particle::texture, SDL_BLENDMODE_BLEND);
        std::cout << "Shared texture loaded.\n";
    }
}