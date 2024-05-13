#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include "Simulation.h"
#include "SimulationControl.h"

void showHelp()
{
    std::cout << "\nAvailable Commands:\n";
    std::cout << "  help - Displays this help message.\n";
    std::cout << "  add - Adds a new plant to the garden.\n";
    std::cout << "  view - Displays current garden and environmental conditions.\n";
    std::cout << "  set-temp [value] - Sets the garden's temperature.\n";
    std::cout << "  exit - Exits the simulation.\n\n";
}

void handleCommands(Simulation &simulation)
{
    std::string input, command;
    while (true)
    {
        std::cout << "Enter command (type 'help' for options): ";
        std::getline(std::cin, input);
        std::istringstream stream(input);
        stream >> command;
        if (command == "exit")
        {
            break;
        }
        else if (command == "add")
        {
            std::shared_ptr<Plant> newPlant = std::make_shared<Plant>();
            simulation.getGarden().addPlant(newPlant);
            std::cout << "Plant added.\n";
        }
        else if (command == "view")
        {
            simulation.getGarden().displayStatus();
        }
        else if (command == "set-temp")
        {
            double newTemp;
            if (stream >> newTemp)
            {
                simulation.getGarden().getEnvironment().setTemperature(newTemp);
                std::cout << "Temperature set to " << newTemp << "°C.\n";
            }
            else
            {
                std::cout << "Invalid temperature. Please enter a numeric value.\n";
            }
        }
        else if (command == "help")
        {
            showHelp();
        }
        else if (command == "add")
        {
            std::string plantName;
            getline(stream, plantName);
            if (!plantName.empty())
            {
                plantName = plantName.substr(1);
            }
            plantName = simulation.getGarden().assignName(plantName.empty() ? "Plant" : plantName);
            std::shared_ptr<Plant> newPlant = std::make_shared<Plant>(plantName);
            simulation.getGarden().addPlant(newPlant);
            std::cout << "Plant added: " << newPlant->getName() << ".\n";
        }
        else if (command == "rename")
        {
            std::string oldName, newName;
            stream >> oldName >> newName;
            simulation.getGarden().renamePlant(oldName, newName);
            std::cout << "Plant renamed to: " << newName << ".\n";
        }
        else
        {
            std::cout << "Unknown command. Type 'help' for a list of valid commands.\n";
        }
    }
}

int main()
{
    Simulation simulation;
    SimulationControl simControl(simulation);
    simControl.start();
    handleCommands(simulation);
    simControl.stop();
    return 0;
}
