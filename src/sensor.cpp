// Sensor.cpp
#include "sensor.h"

Sensor::Sensor(SensorType type, double min_value, double max_value)
: type(type), min_value(min_value), max_value(max_value) {
    srand(time(NULL)); // Seed the random number generator
}

double Sensor::readValue() {
    return min_value + (double(rand()) / RAND_MAX) * (max_value - min_value);
}

std::string Sensor::getTypeName() {
    switch (type) {
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
