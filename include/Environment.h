#pragma once
#include <vector>
#include <random>
#include <memory>
#include "EnvironmentEvent.h"
#include "Weather.h"

class Weather; 
class EnvironmentObserver {
public:
    virtual void onEnvironmentChanged(const EnvironmentEvent& event) = 0;
};

class Environment {
public:
    Weather weather;
    Environment(double temperature = 22.0, double humidity = 50.0, double lightLevel = 300.0);
    void updateEnvironment();
    void registerObserver(std::shared_ptr<EnvironmentObserver> observer);
    void notifyObservers(const EnvironmentEvent& event);

    // Setters and getters...
    void setTemperature(double temperature);
    void setHumidity(double humidity);
    void setLightLevel(double lightLevel);
    double getTemperature() const;
    double getHumidity() const;
    double getLightLevel() const;

private:
    std::vector<std::shared_ptr<EnvironmentObserver>> observers;
    double temperature, humidity, lightLevel;
    std::default_random_engine generator;
    std::normal_distribution<double> temperatureChange, humidityChange, lightLevelChange;
    void checkForRandomEvent();
};
