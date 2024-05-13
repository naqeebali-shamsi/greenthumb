// Sensor.h
#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

enum class SensorType
{
    Temperature,
    Moisture,
    Light
};

class Sensor
{
public:
    Sensor(SensorType type, double min_value, double max_value);
    double readValue();
    std::string getTypeName();

private:
    SensorType type;
    double min_value;
    double max_value;
    double lastValue;
};
