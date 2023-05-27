#include "1.h"


AnimatedText::AnimatedText(std::string text, unsigned int duration) {
    this->text = text;
    this->duration = duration;
}

void AnimatedText::addLetter() {
    if (this->currentText.length() < this->text.length()) {
        this->currentText += text[currentChar];
        currentChar++;
    }
}

void AnimatedText::update() {
    if (this->text.length() > 0) {
        usleep(duration * 1000000 / text.length());
        this->addLetter();
    }
}

void AnimatedText::render(sf::RenderTarget *target) const {
    sf::Text renderableText;
    sf::Font font;
    font.loadFromFile("../second_semester/1/font/roboto.ttf");
    renderableText.setString(this->currentText);
    renderableText.setFont(font);
    renderableText.setFillColor(sf::Color::White);
    target->draw(renderableText);
}

void run_1() {
    sf::RenderWindow window(sf::VideoMode(300, 100), "");
    AnimatedText text("abcdefghj", 1);
    bool windowDisplayed = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        if (windowDisplayed) {
            text.update();
            text.render(&window);
        } else {
            windowDisplayed = true;
        }
        window.display();
    }

}