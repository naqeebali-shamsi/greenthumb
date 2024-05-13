#include "SimulationControl.h"

SimulationControl::SimulationControl(Simulation& sim)
    : simulation(sim), running(false) {}

SimulationControl::~SimulationControl() {
    stop();
}

void SimulationControl::start() {
    if (!running.load()) {
        running.store(true);
        simThread = std::thread(&SimulationControl::runSimulation, this);
    }
}

void SimulationControl::stop() {
    if (running.load()) {
        running.store(false);
        if (simThread.joinable()) {
            simThread.join();
        }
    }
}

void SimulationControl::runSimulation() {
    while (running.load()) {
        simulation.run(); // Ensure `Simulation::run` can handle periodic checks or has a break condition.
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
