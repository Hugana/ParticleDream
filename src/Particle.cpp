#include "../include/Particle.h"
#include <SDL2/SDL_image.h>
#include "../include/System.h"

Particle::Particle(Vector2D posVector, float particleSize, float red, float green, float blue,  int srcX, int srcY, int srcW, int srcH){
    pos = posVector;
    size = particleSize;
    r = red;
    g = green;
    b = blue;
    texture = Particle::loadTexture();
    srcRect.x = srcX;
    srcRect.y = srcY;
    srcRect.w = srcW;
    srcRect.h = srcH;
}

void Particle::move(Vector2D dir){
    pos += dir;
};

void Particle::draw(){
    SDL_RenderCopy(System::renderer, texture, &srcRect, &destRect);
}

SDL_Texture* Particle::loadTexture(){

    SDL_Surface* tmpSurface = IMG_Load("../assets/particle.png");

    if (!tmpSurface) {
        std::cout << "Failed to load image: " << IMG_GetError() << "\n";
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(System::renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return tex;
}