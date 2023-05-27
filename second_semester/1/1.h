#ifndef LABORATORIES_1_H
#define LABORATORIES_1_H

#include <string>
#include <SFML/Graphics.hpp>
#include <unistd.h>


class AnimatedText {
private:
    std::string currentText;
    void addLetter();
    unsigned int currentChar = 0;
public:
    AnimatedText(std::string text, unsigned int duration);
    std::string text;
    unsigned int duration;
    void update();
    void render(sf::RenderTarget *target) const;
};

void run_1();

#endif //LABORATORIES_1_H
