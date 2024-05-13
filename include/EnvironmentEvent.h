#pragma once
#include <string>
class Environment; // Forward declaration

class EnvironmentEvent {
public:
    EnvironmentEvent(std::string description, double impactDuration, double impactTemperature, double impactHumidity, double impactLightLevel);
    void applyEvent(Environment &env) const;
    std::string getDescription() const { return description; }
    double getImpactDuration() const { return impactDuration; }
    double getImpactTemperature() const { return impactTemperature; }
    double getImpactHumidity() const { return impactHumidity; }
    double getImpactLightLevel() const { return impactLightLevel; }

private:
    std::string description;
    double impactDuration;
    double impactTemperature;
    double impactHumidity;
    double impactLightLevel;
};
