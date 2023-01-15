/**
 * @brief Game Over Screen
 *
 * This class creates a game over screen
 * @author Yakup Tezcan
 */
#pragma once
#ifndef THEFIGHTINGMAIDEN_GAMEOVERSTATE_H
#define THEFIGHTINGMAIDEN_GAMEOVERSTATE_H
#endif //THEFIGHTINGMAIDEN_GAMEOVERSTATE_H
#include "State.h"
#include <SFML/Graphics.hpp>

class GameOverState: public State {
private:
    // Helper variable for Game Over Screen Test
    bool gameOver;
public:
    /**
    * @brief Game Over Screen constructor
    *
     * This function initializes gameOver variable
    * @author Yakup Tezcan
    */
    GameOverState();
    /**
   * @brief Game Over Screen deconstructor
   *
   * @author Yakup Tezcan
   */
    ~GameOverState();
    /**
    * @brief Draws game over screen
    *
    * This function draws the game over screen when the player's hp is equal to or lower than 0
    * @param window the current window that is passed to the function
    */
    void drawScreen(sf::RenderWindow *window);
    /**
     * @brief Helper function for game over screen
     *
     * This function helps to test if the game over screen works
     * @return true if game over screen works
     */
    bool testCase();
};