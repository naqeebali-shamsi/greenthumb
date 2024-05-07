// Button.h
#pragma once
#include <SDL.h>
#include <functional>

class Button
{
public:
    Button(int x, int y, int w, int h, std::function<void()> onClick);
    void draw(SDL_Renderer *renderer, bool isHovered);
    bool handleEvent(SDL_Event *e);
    bool isHovered(int x, int y) const;

private:
    SDL_Rect rect;
    std::function<void()> onClick;
};
