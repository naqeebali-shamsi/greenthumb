#pragma once
#include <string>
#include <cstdlib>

class Weather {
public:
    enum class Condition { Sunny, Cloudy, Rainy, Snowy };

    Weather() : currentCondition(Condition::Sunny) {
        updateWeather(); // Initialize with random weather
    }

    void updateWeather() {
        currentCondition = static_cast<Condition>(rand() % 4);
    }

    void setWeatherCondition(Condition newCondition) {
        currentCondition = newCondition;
    }

    std::string getWeatherString() const {
        switch (currentCondition) {
            case Condition::Sunny: return "Sunny";
            case Condition::Cloudy: return "Cloudy";
            case Condition::Rainy: return "Rainy";
            case Condition::Snowy: return "Snowy";
            default: return "Unknown";
        }
    }

    Condition getCurrentCondition() const {
        return currentCondition;
    }

private:
    Condition currentCondition;
};

