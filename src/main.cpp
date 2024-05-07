#include <SDL.h>
#include <iostream>
#include <sensor.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Virtual Home Garden Simulator",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          800, 600, SDL_WINDOW_SHOWN);

    Sensor tempSensor(SensorType::Temperature, -10, 35);
    Sensor moistureSensor(SensorType::Moisture, 0, 100);
    Sensor lightSensor(SensorType::Light, 0, 1000);

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        std::cout << "Temperature: " << tempSensor.readValue() << "°C\n";
        std::cout << "Moisture: " << moistureSensor.readValue() << "%\n";
        std::cout << "Light: " << lightSensor.readValue() << " Lux\n";
        SDL_Delay(1000);  // Update every second
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
