#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include "Simulation.h"
#include "SimulationControl.h"
#include "TaskScheduler.h"

void showHelp() {
    std::cout << "\nAvailable Commands:\n";
    std::cout << "  help - Displays this help message.\n";
    std::cout << "  add - Adds a new plant to the garden.\n";
    std::cout << "  view - Displays current garden and environmental conditions.\n";
    std::cout << "  set-temp [value] - Sets the garden's temperature.\n";
    std::cout << "  set-weather [sunny|cloudy|rainy|snowy] - Sets the weather condition.\n";
    std::cout << "  schedule [action] [interval] - Schedules a task (water|fertilize|weather [sunny|cloudy|rainy|snowy]) with an interval in seconds.\n";
    std::cout << "  exit - Exits the simulation.\n\n";
}

void handleCommands(Simulation &simulation) {
    std::string input, command;
    while (true) {
        std::cout << "Enter command (type 'help' for options): ";
        std::getline(std::cin, input);
        std::istringstream stream(input);
        stream >> command;
        if (command == "exit") {
            break;
        } else if (command == "add") {
            std::shared_ptr<Plant> newPlant = std::make_shared<Plant>();
            simulation.getGarden().addPlant(newPlant);
            std::cout << "Plant added.\n";
        } else if (command == "view") {
            simulation.getGarden().displayStatus();
        } else if (command == "set-temp") {
            double newTemp;
            if (stream >> newTemp) {
                simulation.getGarden().getEnvironment().setTemperature(newTemp);
                std::cout << "Temperature set to " << newTemp << "°C.\n";
            } else {
                std::cout << "Invalid temperature. Please enter a numeric value.\n";
            }
        } else if (command == "set-weather") {
            std::string weatherCondition;
            stream >> weatherCondition;
            if (weatherCondition == "sunny") {
                simulation.getGarden().getEnvironment().weather.setWeatherCondition(Weather::Condition::Sunny);
                std::cout << "Weather set to Sunny.\n";
            } else if (weatherCondition == "cloudy") {
                simulation.getGarden().getEnvironment().weather.setWeatherCondition(Weather::Condition::Cloudy);
                std::cout << "Weather set to Cloudy.\n";
            } else if (weatherCondition == "rainy") {
                simulation.getGarden().getEnvironment().weather.setWeatherCondition(Weather::Condition::Rainy);
                std::cout << "Weather set to Rainy.\n";
            } else if (weatherCondition == "snowy") {
                simulation.getGarden().getEnvironment().weather.setWeatherCondition(Weather::Condition::Snowy);
                std::cout << "Weather set to Snowy.\n";
            } else {
                std::cout << "Invalid weather condition. Valid options are: sunny, cloudy, rainy, snowy.\n";
            }
        } else if (command == "schedule") {
            std::string action, param;
            int interval;
            stream >> action >> interval;
            if (action == "water") {
                simulation.getTaskScheduler().scheduleTask([&simulation] { simulation.getGarden().waterAll(); }, std::chrono::seconds(interval));
                std::cout << "Scheduled watering every " << interval << " seconds.\n";
            } else if (action == "fertilize") {
                simulation.getTaskScheduler().scheduleTask([&simulation] { simulation.getGarden().fertilizeAll(); }, std::chrono::seconds(interval));
                std::cout << "Scheduled fertilizing every " << interval << " seconds.\n";
            } else if (action == "weather") {
                stream >> param;
                if (param == "sunny") {
                    simulation.getTaskScheduler().scheduleTask([&simulation] { simulation.getGarden().getEnvironment().weather.setWeatherCondition(Weather::Condition::Sunny); }, std::chrono::seconds(interval));
                    std::cout << "Scheduled weather change to Sunny every " << interval << " seconds.\n";
                } else if (param == "cloudy") {
                    simulation.getTaskScheduler().scheduleTask([&simulation] { simulation.getGarden().getEnvironment().weather.setWeatherCondition(Weather::Condition::Cloudy); }, std::chrono::seconds(interval));
                    std::cout << "Scheduled weather change to Cloudy every " << interval << " seconds.\n";
                } else if (param == "rainy") {
                    simulation.getTaskScheduler().scheduleTask([&simulation] { simulation.getGarden().getEnvironment().weather.setWeatherCondition(Weather::Condition::Rainy); }, std::chrono::seconds(interval));
                    std::cout << "Scheduled weather change to Rainy every " << interval << " seconds.\n";
                } else if (param == "snowy") {
                    simulation.getTaskScheduler().scheduleTask([&simulation] { simulation.getGarden().getEnvironment().weather.setWeatherCondition(Weather::Condition::Snowy); }, std::chrono::seconds(interval));
                    std::cout << "Scheduled weather change to Snowy every " << interval << " seconds.\n";
                } else {
                    std::cout << "Invalid weather condition for scheduling. Valid options are: sunny, cloudy, rainy, snowy.\n";
                }
            } else {
                std::cout << "Invalid action for scheduling. Valid options are: water, fertilize, weather.\n";
            }
        } else if (command == "help") {
            showHelp();
        } else {
            std::cout << "Unknown command. Type 'help' for a list of valid commands.\n";
        }
    }
}

int main() {
    Simulation simulation;
    SimulationControl simControl(simulation);
    simControl.start();
    handleCommands(simulation);
    simControl.stop();
    return 0;
}
