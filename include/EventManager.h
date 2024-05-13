#pragma once
#include <vector>
#include <functional>

class EnvironmentEvent; // Forward declaration

class EventManager {
public:
    using EventListener = std::function<void(const EnvironmentEvent&)>;

    void subscribe(const EventListener& listener);
    void publish(const EnvironmentEvent& event);

private:
    std::vector<EventListener> listeners;
};
