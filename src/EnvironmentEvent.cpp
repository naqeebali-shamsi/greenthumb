#include "EnvironmentEvent.h"
#include "Environment.h"

EnvironmentEvent::EnvironmentEvent(std::string description, double impactDuration, double impactTemperature, double impactHumidity, double impactLightLevel)
    : description(description), impactDuration(impactDuration), impactTemperature(impactTemperature), impactHumidity(impactHumidity), impactLightLevel(impactLightLevel)
{}

void EnvironmentEvent::applyEvent(Environment& env) const {
    env.setTemperature(env.getTemperature() + impactTemperature);
    env.setHumidity(env.getHumidity() + impactHumidity);
    env.setLightLevel(env.getLightLevel() + impactLightLevel);
}
