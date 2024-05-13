#pragma once

class ILogger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~ILogger() {}  // Ensure there is a virtual destructor
};
