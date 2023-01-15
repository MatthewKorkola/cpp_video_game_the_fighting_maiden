/**
 * @brief State class
 *
 * This class creates a state
 * @author Yakup Tezcan
 */
#pragma once
#ifndef THEFIGHTINGMAIDEN_STATE_H
#define THEFIGHTINGMAIDEN_STATE_H
#endif //THEFIGHTINGMAIDEN_STATE_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"

class State{
public:
    /**
     * @brief Draws screen for states
     *
     * This function draws screen for all possible states in the game.
     * @author Yakup Tezcan
     */
    void drawScreen();
    /**
     * @brief Helper function for test case
     *
     * This function helps to test if the screens work
     * @return true if the state works
     */
    bool testCase();
};