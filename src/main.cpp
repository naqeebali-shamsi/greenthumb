// #include <iostream>
// #include <vector>
// #include <stdexcept>
// #include <string>
// #include <SDL.h>
// #include <SDL_ttf.h>
// #include <sensor.h>
// #include <plant.h>
// #include <button.h>
// #include <utils.h>

// TTF_Font *globalFont = nullptr;

// /**
//  * The main function that initializes the SDL library and creates a window and renderer.
//  * It also creates a vector of plants and a button for watering all the plants.
//  * The function enters a loop where it handles events, clears the screen, updates and draws the plants and the button.
//  * Finally, it destroys the renderer, window, and quits the SDL library.
//  *
//  * @param argc the number of command line arguments
//  * @param argv an array of command line arguments
//  *
//  * @return 0 indicating successful execution of the program
//  *
//  * @throws std::runtime_error if any of the SDL calls fail
//  */
// int main(int argc, char *argv[])
// {
//     std::cout << "Program started" << std::endl;
//     try
//     {
//         if (SDL_Init(SDL_INIT_VIDEO) != 0)
//         {
//             throw std::runtime_error("Could not initialize SDL: " + std::string(SDL_GetError()));
//         }

//         if (TTF_Init() == -1)
//         {
//             throw std::runtime_error("SDL_ttf could not initialize: " + std::string(TTF_GetError()));
//         }
//         globalFont = initializeFont(20);

//         SDL_Window *window = SDL_CreateWindow("Virtual Home Garden Simulator",
//                                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
//                                               800, 600, SDL_WINDOW_SHOWN);
//         if (window == nullptr)
//         {
//             throw std::runtime_error("Could not create SDL window: " + std::string(SDL_GetError()));
//         }

//         SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//         if (renderer == nullptr)
//         {
//             throw std::runtime_error("Could not create SDL renderer: " + std::string(SDL_GetError()));
//         }

//         std::vector<Plant> plants;
//         plants.emplace_back("Rose", 100, 100);
//         plants.emplace_back("Tulip", 200, 100);

//         Button waterAllButton(50, 550, 100, 50, [&plants]()
//                               {
//         for (Plant& plant : plants) {
//             plant.water();
//         } });

//         bool quit = false;
//         SDL_Event e;
//         std::cout << "Rendering frame" << std::endl;
//         while (!quit)
//         {
//             std::cout << "Rendering frame" << std::endl;
//             while (SDL_PollEvent(&e) != 0)
//             {
//                 if (e.type == SDL_QUIT)
//                 {
//                     quit = true;
//                 }
//                 if (e.type == SDL_MOUSEBUTTONDOWN)
//                 {
//                     int x = e.button.x;
//                     int y = e.button.y;
//                     plants.emplace_back("New Plant", x, y);
//                 }

//                 waterAllButton.handleEvent(&e);
//             }

//             if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) != 0)
//             {
//                 throw std::runtime_error("Could not set render draw color: " + std::string(SDL_GetError()));
//             }
//             if (SDL_RenderClear(renderer) != 0)
//             {
//                 throw std::runtime_error("Could not clear renderer: " + std::string(SDL_GetError()));
//             }
//             for (Plant &plant : plants)
//             {
//                 plant.draw(renderer, globalFont);
//                 plant.update();
//             }

//             if (!waterAllButton.isHovered(e.button.x, e.button.y))
//             {
//                 plants.emplace_back("New Plant", e.button.x, e.button.y);
//             }

//             SDL_RenderPresent(renderer);
//             SDL_Delay(100);
//         }

//         SDL_DestroyRenderer(renderer);
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 0;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Error: " << e.what() << std::endl;
//         return 1;
//     }
// }

#include <SDL.h>
#include <iostream>

#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


