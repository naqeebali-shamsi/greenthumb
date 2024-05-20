#include "Simulation.h"
#include "Garden.h"
#include "Sensor.h"
#include "Logger.h"
#include <chrono>
#include <thread>

Simulation::Simulation() 
: garden(std::make_shared<Garden>(std::make_shared<Environment>(), std::make_shared<Logger>("log.txt"))),
  tempSensor(SensorType::Temperature, 10, 30),
  moistureSensor(SensorType::Moisture, 30, 70),
  lightSensor(SensorType::Light, 200, 400) {
    garden->initialize();
}

void Simulation::setupSensors() {
    tempSensor = Sensor(SensorType::Temperature, 10, 30);
    moistureSensor = Sensor(SensorType::Moisture, 30, 70);
    lightSensor = Sensor(SensorType::Light, 200, 400);
}

void Simulation::run() {
    setupSensors();
    taskScheduler.start();

    while (true) {
        garden->getEnvironment().setTemperature(tempSensor.readValue());
        garden->getEnvironment().setHumidity(moistureSensor.readValue());
        garden->getEnvironment().setLightLevel(lightSensor.readValue());
        garden->updateGarden();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
