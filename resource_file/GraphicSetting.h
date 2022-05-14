#ifndef GRAPHICSETTING_H
#define GRAPHICSETTING_H

#include <iostream>
#include <string>
#include <fstream>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "SFML\System.hpp"

class GraphicSetting
    {
    public:
        GraphicSetting();
        virtual ~GraphicSetting();

        // Variables
        std::string title;
        sf::VideoMode resolution;
        bool fullscreen;
        bool verticalSync;
        unsigned frameRateLimit;
        sf::ContextSettings contextSetting;
        std::vector<sf::VideoMode> videoModes;

        // Functions
        void saveToFile(const std::string path);
        void loadFromFile(const std::string path);
    };

#endif