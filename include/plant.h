// Plant.h
#pragma once
#include <string>
#include <SDL.h>

class Plant {
public:
    Plant(std::string species, int x, int y);
    void update();
    void draw(SDL_Renderer* renderer, TTF_Font* font);
    void water();
    void fertilize();
    int getX() const;
    int getY() const;
    std::string getName() const;

private:
    std::string species;
    int health;
    int x, y; // Position in the garden
    int growthStage;
};
