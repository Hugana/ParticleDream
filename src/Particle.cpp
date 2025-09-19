#include "../include/Particle.h"
#include "../include/System.h"
#include "../include/ColorUtils.h"
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

    baseColor = { static_cast<Uint8>(0),
              static_cast<Uint8>(255),
              static_cast<Uint8>(130),
              255 };

    targetColor = { 0, 0, 255, 255 }; // or pick anything, e.g. a rainbow target

}

Particle::~Particle() {}

void Particle::move(Vector2D dir){    
    pos += dir;
};

void Particle::draw(){
    SDL_Color modColor = ColorUtils::oscillateColor(baseColor, targetColor, 2.0f);
    SDL_SetTextureColorMod(texture, modColor.r, modColor.g, modColor.b);
    SDL_RenderCopy(System::renderer, texture, &srcRect, &destRect);
}

void Particle::update(){
    destRect.x = pos.getX();
    destRect.y = pos.getY();
    destRect.w = srcRect.w;  
    destRect.h = srcRect.h;
}

Vector2D Particle::getPosition(){
    return pos;
}

void Particle::wrapAround(int width, int height) {
    float x = pos.getX();
    float y = pos.getY();

    if (x < 0){
        x += width;
    }else if (x >= width){
         x -= width;
    } 
    
    if (y < 0) {
        y += height;
    }
    else if (y >= height){
        y -= height;
    }

    pos = Vector2D(x, y);
}

void Particle::loadTexture() {
    if (texture) return; 

    SDL_Surface* tmpSurface = IMG_Load("assets/particle_2x2.png");
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