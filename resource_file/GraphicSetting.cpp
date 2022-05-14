#include "GraphicSetting.h"

GraphicSetting::GraphicSetting()
{
    this->title = "DEFAULT";
    this->resolution = sf::VideoMode::getDesktopMode();
    this->fullscreen = false;
    this->verticalSync = false;
    this->frameRateLimit = 60;
    this->contextSetting.antialiasingLevel = 0;
    this->videoModes = sf::VideoMode::getFullscreenModes();
}

GraphicSetting::~GraphicSetting()
{
    
}

void GraphicSetting::saveToFile(const std::string path)
{
    std::ofstream fout("Config/graphics.ini");
    if (fout.is_open())
    {
        fout << title;
        fout << this->resolution.width << " " << this->resolution.height;
        fout << fullscreen;
        fout << this->frameRateLimit;
        fout << this->verticalSync;
        fout << this->contextSetting.antialiasingLevel;
    }
    fout.close();
}

void GraphicSetting::loadFromFile(const std::string path)
{
    std::ifstream fin("Config/graphics.ini");
    if (fin.is_open())
    {
        std::getline(fin, this->title);
        fin >> this->resolution.width >> this->resolution.height;
        fin >> fullscreen;
        fin >> this->frameRateLimit;
        fin >> this->verticalSync;
        fin >> this->contextSetting.antialiasingLevel;
    }
    fin.close();
}