#include "../include/PerlinGrid.h"

void PerlinGrid::init(int width, int height){
    scale = 20;
    rows = (height / scale);
    cols = (width / scale);
}

void PerlinGrid::update(){
    int yoff = 0;
    for (int y; y < rows; y++){
        int xoff = 0;
        for (int x; x < cols; x++){
            int index = x * y * cols;

        }
    }
}