// utils.h
#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

TTF_Font* initializeFont(int fontSize);
SDL_Texture* createTextTexture(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, SDL_Color color);