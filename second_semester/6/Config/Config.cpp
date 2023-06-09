#include "Config.h"

logger::Config::Config() {}

logger::Config::Config(bool file, bool console) {
    this->file = file;
    this->console = console;
}
