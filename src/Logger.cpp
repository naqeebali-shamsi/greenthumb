#include "Logger.h"

Logger::Logger(const std::string& filename) {
    file.open(filename, std::ios::app);
}

Logger::~Logger() {
    if (file.is_open()) {
        file.close();
    }
}

void Logger::log(const std::string& message) {
    if (file.is_open()) {
        file << message << std::endl;
    } else {
        std::cerr << "Error: Log file is not open." << std::endl;
    }
}
