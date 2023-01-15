//
// Created by Matthew Korkola and Yakup Tezcan on 2022-11-24.
//
#include "GameOverState.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>
GameOverState::GameOverState() {
    // Game Over variable to help game over test case
    gameOver = false;
}
GameOverState::~GameOverState() {
}
void GameOverState:: drawScreen(sf::RenderWindow *window){
    // Draws the Game over Screen
    // Entire screen will be dark
    sf::RectangleShape gameOverScreen;
    sf::Vector2f gameOverScreenPosition(0.f, 0.f);
    gameOverScreen.setPosition(gameOverScreenPosition);
    gameOverScreen.setFillColor(sf::Color::Black);
    gameOverScreen.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    window ->draw(gameOverScreen);

    // Prints "Game Over" to the screen.
    // Imports a font from the fonts folder
    sf::Font font;
    if (!font.loadFromFile( "fonts/FFF_Tusj.ttf")) {
        throw ("Font could not be loaded");
    }
    // Game Over text
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(150);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(220.f, 250.f);
    window ->draw(gameOverText);
    // The window must be displayed again to see the game over screen.
    window ->display();
    sleep(3);
    // The game is over, so exit.
    gameOver = true;
    // Closes the window after 3 seconds.
    window->close();
}
bool GameOverState::testCase() {
    // Returns true if game over screen works
    return gameOver;
}