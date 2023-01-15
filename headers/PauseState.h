/**
 * @brief Pause Screen
 *
 * This class creates a pause screen when button "P" is pressed
 * @author Yakup Tezcan
 */
#pragma once
#ifndef THEFIGHTINGMAIDEN_PAUSESTATE_H
#define THEFIGHTINGMAIDEN_PAUSESTATE_H
#endif //THEFIGHTINGMAIDEN_PAUSESTATE_H
#include "State.h"
#include <SFML/Graphics.hpp>

class PauseState:public State{
private:
    // pause variable to help the test case
    bool pause;
public:
    /**
     * @brief Pause State constructor
     *
     * This function initializes pause variable.
     * @author Yakup Tezcan
     */
    PauseState();
    /**
    * @brief Pause State deconstructor
    *
    * @author Yakup Tezcan
    */
    ~PauseState();
    /**
     * @brief Pause screen
     *
     * This function draws a pause screen
     * @param window an sfml object that is passed to function which is current window
     * @author Yakup Tezcan
     */
    void drawScreen(sf::RenderWindow *window);
    /**
     * @brief Pause Screen Test helper
     *
     * This method helps to test pause screen state.
     * @return true if the pause screen does work
     * @author Yakup Tezcan
     */
    bool testCase();
};