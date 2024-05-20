// src/TaskScheduler.cpp
#include "TaskScheduler.h"

TaskScheduler::TaskScheduler() : running(false) {}

TaskScheduler::~TaskScheduler() {
    stop();
}

void TaskScheduler::start() {
    if (!running.load()) {
        running.store(true);
        schedulerThread = std::thread(&TaskScheduler::run, this);
    }
}

void TaskScheduler::stop() {
    if (running.load()) {
        running.store(false);
        if (schedulerThread.joinable()) {
            schedulerThread.join();
        }
    }
}

void TaskScheduler::scheduleTask(const Task& task, std::chrono::milliseconds interval) {
    tasks.emplace_back(task, interval);
}

void TaskScheduler::run() {
    while (running.load()) {
        auto now = std::chrono::steady_clock::now();
        for (auto& [task, interval] : tasks) {
            task();
            std::this_thread::sleep_until(now + interval);
        }
    }
}
