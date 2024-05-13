#pragma once
#include "Simulation.h"
#include <atomic>
#include <thread>

class SimulationControl {
public:
    SimulationControl(Simulation& sim);
    ~SimulationControl();

    void start();
    void stop();

private:
    Simulation& simulation;
    std::atomic<bool> running;
    std::thread simThread;

    void runSimulation();
};
