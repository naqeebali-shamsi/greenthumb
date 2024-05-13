#include "Sensor.h"
#include <cmath>

Sensor::Sensor(SensorType type, double min_value, double max_value)
    : type(type), min_value(min_value), max_value(max_value), lastValue((min_value + max_value) / 2.0)
{
    srand(time(NULL));
}

double Sensor::readValue()
{
    double fluctuation = (double(rand()) / RAND_MAX - 0.5) * (max_value - min_value) * 0.11;
    lastValue = std::max(min_value, std::min(max_value, lastValue + fluctuation));
    return lastValue;
}

std::string Sensor::getTypeName()
{
    switch (type)
    {
    case SensorType::Temperature:
        return "Temperature";
    case SensorType::Moisture:
        return "Moisture";
    case SensorType::Light:
        return "Light";
    default:
        return "Unknown";
    }
}
