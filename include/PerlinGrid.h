#include <vector>

class PerlinGrid{

    public:
        PerlinGrid();
        ~PerlinGrid();
        void init(int width, int height);
        void update();
       
        
        std::vector<float> grid;
        int scale, rows, cols;

};