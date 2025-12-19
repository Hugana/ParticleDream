#include "../include/Config.h" // Standard path to your header
#include <iostream>

Config::GameConfig Config::load(std::string filename) {

    GameConfig config;

    config.window = {"Particle Dream", 800, 600, false};
    config.particles = {2, 1000, "assets/particle_2x2.png"};
    config.grid = {0.1f, 0.1f, 0.1f, 1.0f}; 

    try {
        YAML::Node root = YAML::LoadFile(filename);

        if (root["window"]) {
            if (root["window"]["title"]) config.window.title = root["window"]["title"].as<std::string>();
            if (root["window"]["width"]) config.window.width = root["window"]["width"].as<int>();
            if (root["window"]["height"]) config.window.height = root["window"]["height"].as<int>();
            if (root["window"]["fullscreen"]) config.window.fullscreen = root["window"]["fullscreen"].as<bool>();
        }

        if (root["particles"]) {
            if (root["particles"]["size"]) config.particles.size = root["particles"]["size"].as<int>();
            if (root["particles"]["count"]) config.particles.count = root["particles"]["count"].as<int>();
            if (root["particles"]["filename"]) config.particles.filename = root["particles"]["filename"].as<std::string>();
        }

        if (root["grid"]) {
            if (root["grid"]["xoffInc"]) config.grid.xoffInc = root["grid"]["xoffInc"].as<float>();
            if (root["grid"]["yoffInc"]) config.grid.yoffInc = root["grid"]["yoffInc"].as<float>();
            if (root["grid"]["zoffInc"]) config.grid.zoffInc = root["grid"]["zoffInc"].as<float>();
            if (root["grid"]["magnitude"]) config.grid.magnitude = root["grid"]["magnitude"].as<float>();
        }

        std::cout << "Successfully loaded config: " << filename << "\n";

    } catch (const YAML::BadFile& e) {
        std::cerr << "Config file not found: " << filename << ". Using defaults.\n";
    } catch (const YAML::ParserException& e) {
        std::cerr << "YAML syntax error in " << filename << ": " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error loading config: " << e.what() << "\n";
    }

    return config;
}