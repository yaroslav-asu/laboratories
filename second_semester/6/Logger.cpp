#include <iostream>
#include "Logger.h"


void logger::Logger::consoleLog(std::string logLevel, std::string message) {
    std::cout << "[" << this->_time() << "] " << logLevel << ": " << message << std::endl;
}

void logger::Logger::fileLog(std::string logLevel, std::string message) {
    this->file << "[" << this->_time() << "] " << logLevel << ": " << message << std::endl;
}

logger::Logger::Logger() {
    this->config = Config();
    this->file.open("log.txt");
}

logger::Logger::Logger(logger::Config config) {
    this->config = config;
    if (config.file) {
        this->file.open("log.txt");
    }
}

void logger::Logger::info(std::string message) {
    if (this->config.console) {
        if (this->levels[INFO]) {
            this->consoleLog("INFO", message);
        }
    }
    if (this->config.file) {
        this->fileLog("INFO", message);
    }
}

void logger::Logger::debug(std::string message) {
    if (this->config.console) {
        if (this->levels[DEBUG]) {
            this->consoleLog("DEBUG", message);
        }
    }
    if (this->config.file) {
        this->fileLog("DEBUG", message);
    }
}

void logger::Logger::warn(std::string message) {
    if (this->config.console) {
        if (this->levels[WARN]) {
            this->consoleLog("WARN", message);
        }
    }
    if (this->config.file) {
        this->fileLog("WARN", message);
    }
}

void logger::Logger::error(std::string message) {
    if (this->config.console) {
        if (this->levels[ERROR]) {
            this->consoleLog("ERROR", message);
        }
    }
    if (this->config.file) {
        this->fileLog("ERROR", message);
    }
}

void logger::Logger::toggleLogLevel(std::string level) {
    if (level == "info") {
        this->levels[INFO] = !this->levels[INFO];
    } else if (level == "debug") {
        this->levels[DEBUG] = !this->levels[DEBUG];
    } else if (level == "error") {
        this->levels[ERROR] = !this->levels[ERROR];
    } else if (level == "warn") {
        this->levels[WARN] = !this->levels[WARN];
    }
}

std::string logger::Logger::_time() {
    time_t now = time(nullptr);
    std::string t = ctime(&now);
    return t.substr(0, t.length() - 1);
}

logger::Logger::~Logger() {
    if (this->config.file) {
        this->file.close();
    }
}

void runLogger() {
    logger::Logger l = logger::Logger();
    l.info("aoeuoaeu");
    l.warn("aoeuoaeu");
    l.debug("aoeuoaeu");
    l.error("aoeuoaeu");
}
