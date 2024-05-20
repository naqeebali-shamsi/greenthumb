#include <cstdlib>
#include "Environment.h"
#include "Weather.h"

Environment::Environment(double temperature, double humidity, double lightLevel)
    : temperature(temperature), humidity(humidity), lightLevel(lightLevel),
      temperatureChange(0.0, 2.0), humidityChange(0.0, 5.0), lightLevelChange(0.0, 50.0) {
    generator.seed(std::random_device()());
}
void Environment::updateEnvironment() {
    weather.updateWeather();
    switch (weather.getCurrentCondition()){
        case Weather::Condition::Sunny:
            lightLevel += 10;
            break;
        case Weather::Condition::Cloudy:
            humidity += 5;
            lightLevel -= 5;
            break;
        case Weather::Condition::Rainy:
            humidity += 10;
            lightLevel -= 10;
            break;
        case Weather::Condition::Snowy:
            humidity -= 5;
            lightLevel -= 5;
            break;
    }
    checkForRandomEvent();
    temperature += temperatureChange(generator);
    humidity += humidityChange(generator);
    lightLevel += lightLevelChange(generator);
}

void Environment::registerObserver(std::shared_ptr<EnvironmentObserver> observer) {
    observers.push_back(observer);
}

void Environment::notifyObservers(const EnvironmentEvent& event) {
    for (auto& observer : observers) {
        observer->onEnvironmentChanged(event);
    }
}

void Environment::checkForRandomEvent() {
    if ((rand() % 100) < 5) {
        EnvironmentEvent event("Heatwave", 24, 5, 0, 0);
        notifyObservers(event);
    }
}

double Environment::getTemperature() const {
    return temperature;
}

double Environment::getHumidity() const {
    return humidity;
}

double Environment::getLightLevel() const {
    return lightLevel;
}

void Environment::setTemperature(double temperature) {
    this->temperature = temperature;
}

void Environment::setHumidity(double humidity) {
    this->humidity = humidity;
}

void Environment::setLightLevel(double lightLevel) {
    this->lightLevel = lightLevel;
}

