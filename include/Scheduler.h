#pragma once
#include <chrono>
#include <vector>
#include <functional>
#include <thread>
#include <atomic>
#include <iostream>

class Scheduler {
public:
    using Task = std::function<void()>;

    Scheduler() : running(true) {
        worker = std::thread([this]() {
            while (running) {
                auto now = std::chrono::system_clock::now();
                for (auto& task : tasks) {
                    if (now >= task.nextRun) {
                        task.task();
                        task.nextRun += task.interval;
                    }
                }
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        });
    }

    ~Scheduler() {
        running = false;
        if (worker.joinable()) worker.join();
    }

    void scheduleTask(Task task, unsigned int intervalInSeconds) {
        tasks.push_back({task, std::chrono::system_clock::now() + std::chrono::seconds(intervalInSeconds), std::chrono::seconds(intervalInSeconds)});
    }

private:
    struct ScheduledTask {
        Task task;
        std::chrono::system_clock::time_point nextRun;
        std::chrono::seconds interval;
    };

    std::vector<ScheduledTask> tasks;
    std::atomic<bool> running;
    std::thread worker;
};