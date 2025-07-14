#include <vector>
#include "FastNoiseLite.h"
#include "Vector2D.h"

class PerlinGrid{

    public:
        PerlinGrid();
        ~PerlinGrid();
        void init(int width, int height, float increment, int magnitude);
        void update();
        Vector2D getValueAtPosition(float x, float y);
       
        FastNoiseLite noise;
        int scale, rows, cols, mag;
        std::vector<std::vector<Vector2D>> grid;
        float inc, zoff, yoff, xoff;

};