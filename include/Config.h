#pragma once
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>


class Config{

    public:
        struct WindowConfig
        {
            std::string title;
            int width;
            int height;
            bool fullscreen;
        };

        struct ParticleConfig
        {
            int size;
            int count;
            std::string filename;
        };

        struct PerlingGrid
        { 
            float zoffInc;
            float yoffInc;
            float xoffInc;
            float magnitude;
        };

        struct GameConfig {
            WindowConfig window;
            ParticleConfig particles;
            PerlingGrid grid;
        };
        
        GameConfig load(std::string filename);

};