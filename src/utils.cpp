#include <stdexcept>
#include <utils.h>

static const std::string FONT_PATH = "assets/fonts/Poppins-Regular.ttf";

TTF_Font *initializeFont(int fontSize)
{
    if (TTF_Init() == -1)
    {
        throw std::runtime_error("SDL_ttf could not initialize: " + std::string(TTF_GetError()));
    }

    TTF_Font *font = TTF_OpenFont(FONT_PATH.c_str(), fontSize);
    if (font == nullptr)
    {
        throw std::runtime_error("Failed to load font: " + std::string(TTF_GetError()));
    }

    return font;
}

SDL_Texture *createTextTexture(SDL_Renderer *renderer, TTF_Font *font, const std::string &text, SDL_Color color)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == nullptr)
    {
        throw std::runtime_error("Failed to create surface from text: " + std::string(TTF_GetError()));
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr)
    {
        SDL_FreeSurface(surface);
        throw std::runtime_error("Failed to create texture from surface: " + std::string(SDL_GetError()));
    }
    SDL_FreeSurface(surface);
    return texture;
}