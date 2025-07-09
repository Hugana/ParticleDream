#include "../include/Particle.h"
#include <SDL2/SDL_image.h>

Particle::Particle(Vector2D posVector, float particleSize, float red, float green, float blue){
    pos = posVector;
    size = particleSize;
    r = red;
    g = green;
    b = blue;
}

void Particle::move(Vector2D dir){
    pos += dir;
};

void Particle::draw(){

}