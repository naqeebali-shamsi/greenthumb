// Plant.cpp
#include <SDL.h>
#include <SDL_ttf.h>
#include "plant.h"
#include "utils.h"

Plant::Plant(std::string species, int x, int y)
: species(species), health(100), x(x), y(y), growthStage(1) {}

void Plant::update() {
    // Implement growth and health effects based on environment
    // Growth effect: increase health and growth stage based on growth stage
    health += growthStage * 5;
    growthStage++;
    
    // Environment effects: decrease health based on environment
    int environment = rand() % 3;
    if (environment == 0) health -= 5; // dry
    else if (environment == 1) health -= 2; // normal
    else health -= 1; // wet
}

void Plant::draw(SDL_Renderer* renderer, TTF_Font* font) {
     // Drawing the plant rectangle
    SDL_Rect plantRect = {x, y, 50, 50}; // Adjust dimensions as necessary
    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255); // Set color to green
    SDL_RenderFillRect(renderer, &plantRect);

    // Draw the plant name and health
    std::string info = species + " Health: " + std::to_string(health);
    SDL_Color textColor = {0, 0, 0, 255}; // Text color black
    SDL_Texture* textTexture = createTextTexture(renderer, font, info, textColor);
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
    SDL_Rect textRect = {x, y - 30, textWidth, textHeight};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_DestroyTexture(textTexture);
}


void Plant::water() {
    health += 10; // Simple example
}

void Plant::fertilize() {
    growthStage++;
}

int Plant::getX() const {
    return x;
}

int Plant::getY() const {
    return y;
}

std::string Plant::getName() const {
    return species;
}
