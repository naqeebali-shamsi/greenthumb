// include/TaskScheduler.h
#pragma once
#include <functional>
#include <vector>
#include <chrono>
#include <thread>
#include <atomic>

class TaskScheduler {
public:
    using Task = std::function<void()>;

    TaskScheduler();
    ~TaskScheduler();

    void start();
    void stop();
    void scheduleTask(const Task& task, std::chrono::milliseconds interval);

private:
    void run();

    std::vector<std::pair<Task, std::chrono::milliseconds>> tasks;
    std::atomic<bool> running;
    std::thread schedulerThread;
};

