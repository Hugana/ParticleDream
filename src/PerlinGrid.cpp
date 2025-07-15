#include "../include/PerlinGrid.h"
#include "../include/pcg_random.hpp"
#include <numbers>
#include <cmath>
#include "../include/Vector2D.h"
#include <random>


PerlinGrid::PerlinGrid(){};
PerlinGrid::~PerlinGrid(){};

void PerlinGrid::init(int width, int height, float increment, float magnitude ){
    scale = 10;
    rows = (height / scale);
    cols = (width / scale);
    inc = increment;
    mag = magnitude;

    zoff = 0;
    yoff = 0;
    xoff = 0;

    grid.resize(rows, std::vector<Vector2D>(cols, Vector2D(0.0f, 0.0f)));


    pcg_extras::seed_seq_from<std::random_device> seed_src;
    pcg32 rng(seed_src);
    uint32_t value = rng();
    noise.SetSeed(value);
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetFractalOctaves(4);
    noise.SetFrequency(0.25);
}

void PerlinGrid::update() {
    yoff = 0;
    for (int y = 0; y < rows; y++) {
        float xoff = 0;
        for (int x = 0; x < cols; x++) {
            float angle = noise.GetNoise(xoff, yoff, zoff) * M_PI;
            Vector2D vector = Vector2D(std::cos(angle) * mag, std::sin(angle) * mag);
            grid[y][x] = vector;

            xoff += inc;
        }
        yoff += inc;
    }

    zoff += 0.008f; 
}


Vector2D PerlinGrid::getValueAtPosition(float x, float y) {
    int gx = x / scale;
    int gy = y / scale;

    if (gx >= 0 && gx < cols && gy >= 0 && gy < rows) {
        return grid[gy][gx];
    }

    return Vector2D(0,0);
}