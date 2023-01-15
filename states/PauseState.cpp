//
// Created by Yakup Tezcan on 2022-11-25.
//
#include "PauseState.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "unistd.h"
PauseState::PauseState(){
    // Pause variable to help game over test case
    this->pause = false;
}
PauseState::~PauseState(){

}
void PauseState::drawScreen(sf::RenderWindow *window){
    // Draws the Game Paused Screen
    // Entire screen will be dark
    sf::RectangleShape gameOverScreen;
    sf::Vector2f gameOverScreenPosition(0.f, 0.f);
    gameOverScreen.setPosition(gameOverScreenPosition);
    gameOverScreen.setFillColor(sf::Color::Black);
    gameOverScreen.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    window ->draw(gameOverScreen);

    // Print "Game Paused" to the screen.
    // Imports a font from the fonts folder
    sf::Font font;
    if (!font.loadFromFile("fonts/FFF_Tusj.ttf")) {
        throw ("Font could not be loaded");
    }
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Paused");
    gameOverText.setCharacterSize(150);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(220.f, 250.f);
    window ->draw(gameOverText);
    // The window must be displayed again to see the game paused screen.
    window ->display();
    // Returns true if the pause screen is displayed
    pause = true;
}
bool PauseState::testCase(){
    // Returns true if game pause screen works
    return pause;
}