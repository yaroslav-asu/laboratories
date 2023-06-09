#ifndef LABORATORIES_CONFIG_H
#define LABORATORIES_CONFIG_H

namespace logger {
    class Config {
    public:
        bool file = true;
        bool console = true;

        Config();

        Config(bool file, bool console);
    };
}

#endif //LABORATORIES_CONFIG_H
