#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ILogger.h"

class Logger : public ILogger {
public:
    Logger(const std::string& filename);
    ~Logger();

    void log(const std::string& message);

private:
    std::ofstream file;
};
