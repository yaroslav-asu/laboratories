#ifndef LABORATORIES_LOGGER_H
#define LABORATORIES_LOGGER_H

#include <string>
#include "Config/Config.h"
#include <iostream>
#include <fstream>

namespace logger {
    enum logLevels {
        INFO, DEBUG, ERROR, WARN
    };

    class Logger {
    private:
        logger::Config config;
        bool levels[4] = {true, true, true, true};

        void consoleLog(std::string logLevel, std::string message);

        void fileLog(std::string logLevel, std::string message);

        std::string _time();

        std::ofstream file;

    public:
        Logger();

        explicit Logger(Config config);

        ~Logger();

        void toggleLogLevel(std::string level);

        void info(std::string message);

        void debug(std::string message);

        void error(std::string message);

        void warn(std::string message);
    };
}
void runLogger();

#endif //LABORATORIES_LOGGER_H
