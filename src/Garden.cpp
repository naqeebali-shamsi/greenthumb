#include "Garden.h"
#include "Logger.h"
#include "ILogger.h"

Garden::Garden(std::shared_ptr<Environment> environment, std::shared_ptr<ILogger> logger)
    : environment(environment), logger(logger) {
    // Delay any shared_from_this() usage until after construction.
    // This is because shared_from_this() can only be used after the object is fully constructed.
}

void Garden::addPlant(const std::shared_ptr<Plant>& plant) {
    plants.push_back(plant);
}

void Garden::updateGarden() {
    environment->updateEnvironment();
    for (auto& plant : plants) {
        plant->updateHealth();
        logger->log("Updated plant " + plant->getName() + " health to " + std::to_string(plant->getHealth()));
    }
}

void Garden::onEnvironmentChanged(const EnvironmentEvent& event) {
    // Use the getters to access the private fields of EnvironmentEvent
    logger->log("Environment changed due to: " + event.getDescription());
    environment->setTemperature(environment->getTemperature() + event.getImpactTemperature());
    environment->setHumidity(environment->getHumidity() + event.getImpactHumidity());
    environment->setLightLevel(environment->getLightLevel() + event.getImpactLightLevel());
}

void Garden::displayStatus() const {
    std::cout << "\nGarden Status:\n";
    std::cout << "Environment - Temperature: " << environment->getTemperature()
              << "°C, Humidity: " << environment->getHumidity()
              << "%, Light Level: " << environment->getLightLevel() << " lux\n";
    if (plants.empty()) {
        std::cout << "No plants in the garden.\n";
    } else {
        for (const auto& plant : plants) {
            std::cout << "Plant '" << plant->getName()
                      << "' - Health: " << plant->getHealth()
                      << ", Water Level: " << plant->getWaterLevel()
                      << ", Growth Stage: " << plant->getGrowthStage() << "\n";
        }
    }
    std::cout << "\n";
}

void Garden::initialize() {
    environment->registerObserver(shared_from_this());
}

Environment& Garden::getEnvironment() {
    return *environment;
}

std::string Garden::assignName(std::string baseName) {
    int& count = nameCount[baseName];
    std::string newName = baseName;
    if (count > 0) {
        newName += " " + std::to_string(count);
    }
    count++;
    return newName;
}

void Garden::renamePlant(const std::string& oldName, const std::string& newName) {
    for (auto& plant : plants) {
        if (plant->getName() == oldName) {
            plant->setName(newName);
            break;
        }
    }
    // Update name counts accordingly
    nameCount[newName] = nameCount[oldName];
    nameCount.erase(oldName);
}
