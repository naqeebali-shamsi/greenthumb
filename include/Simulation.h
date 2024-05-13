#pragma once
#include "Garden.h"
#include "Sensor.h"
#include <memory>

class Simulation {
public:
    Simulation();
    void run();
    void setupSensors();
    Garden& getGarden() const { return *garden; }

private:
    std::shared_ptr<Garden> garden;
    Sensor tempSensor, moistureSensor, lightSensor;
};

