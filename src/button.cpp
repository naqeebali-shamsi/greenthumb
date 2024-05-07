#include <button.h>

Button::Button(int x, int y, int w, int h, std::function<void()> onClick)
    : rect({x, y, w, h}), onClick(onClick) {}

void Button::draw(SDL_Renderer *renderer, bool isHovered)
{
    SDL_SetRenderDrawColor(renderer, isHovered ? 100 : 0, 122, 204, 255);
    SDL_RenderFillRect(renderer, &rect);
}

bool Button::handleEvent(SDL_Event *e)
{
    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        int x = e->button.x;
        int y = e->button.y;
        if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
        {
            onClick();
            return true;
        }
    }
    return false;
}

bool Button::isHovered(int x, int y) const
{
    return x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h;
}
