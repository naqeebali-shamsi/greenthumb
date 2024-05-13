#include "EventManager.h"
#include "EnvironmentEvent.h"

void EventManager::subscribe(const EventListener& listener) {
    listeners.push_back(listener);
}

void EventManager::publish(const EnvironmentEvent& event) {
    for (auto& listener : listeners) {
        listener(event);
    }
}
