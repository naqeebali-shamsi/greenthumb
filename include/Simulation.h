#pragma once
#include "Garden.h"
#include "Sensor.h"
#include "TaskScheduler.h"
#include <memory>

class Simulation {
public:
    Simulation();
    void run();
    void setupSensors();
    Garden& getGarden() const { return *garden; }
    TaskScheduler& getTaskScheduler() { return taskScheduler; }

private:
    std::shared_ptr<Garden> garden;
    Sensor tempSensor, moistureSensor, lightSensor;
    TaskScheduler taskScheduler;
};

