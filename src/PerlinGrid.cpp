#include "../include/PerlinGrid.h"
#include "../include/pcg_random.hpp"
#include <numbers>
#include <cmath>
#include "../include/Vector2D.h"


PerlinGrid::PerlinGrid(){};
PerlinGrid::~PerlinGrid(){};

void PerlinGrid::init(int width, int height, float increment, int magnitude ){
    scale = 20;
    rows = (height / scale);
    cols = (width / scale);
    inc = increment;
    mag = magnitude;

    zoff = 0;
    yoff = 0;
    xoff = 0;

    grid.resize(rows, std::vector<Vector2D>(cols, Vector2D(0.0f, 0.0f)));
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetFrequency(0.5);
}

void PerlinGrid::update() {
    yoff = 0;
    for (int y = 0; y < rows; y++) {
        float xoff = 0;
        for (int x = 0; x < cols; x++) {
            float angle = noise.GetNoise(xoff, yoff, zoff) * M_2_PI * 4; 
            Vector2D vector = Vector2D(cos(angle) * mag, sin(angle) * mag);
            grid[y][x] = vector;

            xoff += inc;
        }
        yoff += inc;
    }

    zoff += 0.03f; 
}

Vector2D PerlinGrid::getValueAtPosition(float x, float y) {
    int gx = x / scale;
    int gy = y / scale;

    if (gx >= 0 && gx < cols && gy >= 0 && gy < rows) {
        return grid[gy][gx];
    }

    return Vector2D(0,0);
}