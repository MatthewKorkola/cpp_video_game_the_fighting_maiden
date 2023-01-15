//
// Created by Matthew Korkola and Yakup Tezcan on 2022-11-25.
//
#include "TitleScreenState.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>
TitleScreenState::TitleScreenState(){
}
TitleScreenState::~TitleScreenState(){
}
void TitleScreenState::drawScreen(sf::RenderWindow *window,  sf::Clock clock){
    // Imports a font from the fonts folder
    sf::Font font;
    if (!font.loadFromFile("fonts/FFF_Tusj.ttf")) {
        throw("Font could not be loaded");
    }
    // Creates the title screen.
    sf::RectangleShape title;
    sf::Vector2f titleScreenPosition(0.f, 0.f);
    title.setPosition(titleScreenPosition);
    title.setFillColor(sf::Color (0, 50, 115));
    title.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

    // The title text is "The Fighting Maiden" and "Press C to Continue"
    sf::Text the;
    the.setFont(font);
    the.setString("The");
    the.setCharacterSize(125);
    the.setFillColor(sf::Color (220, 0, 0));
    the.setPosition(200.f, 10.f);

    sf::Text fighting;
    fighting.setFont(font);
    fighting.setString("Fighting");
    fighting.setCharacterSize(225);
    fighting.setFillColor(sf::Color::Red);
    fighting.setStyle(sf::Text::Bold);
    fighting.setPosition(15.f, 150.f);

    sf::Text maiden;
    maiden.setFont(font);
    maiden.setString("Maiden");
    maiden.setCharacterSize(175);
    maiden.setFillColor(sf::Color (0, 255, 100));
    maiden.setPosition(600.f, 430.f);

    sf::Text play;
    play.setFont(font);
    play.setString("Press C to Continue");
    play.setCharacterSize(70);
    play.setFillColor(sf::Color::Black);
    play.setPosition(300.f, 620.f);

    // Prepare to make "Press C to continue" flash.
    bool drawPlay = false;
    sf::Clock clock1;
    sf::Time textTime;
    textTime = sf::seconds(1);
    clock.restart();

    do {
        // Draw the title screen.
        window -> clear();
        window->draw(title);
        window->draw(the);
        window->draw(fighting);
        window->draw(maiden);
        if (clock.getElapsedTime() >= textTime) {
            if (drawPlay) {
                drawPlay = false;
            }
            else {
                drawPlay = true;
            }
            clock.restart();
        }

        // Make "Press C to continue" flash.
        if (drawPlay) {
            window->draw(play);
        }

        // The window must be displayed again to see the title screen.
        window->display();
    }
        // Start the game when the player presses the "C".
    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C));
}