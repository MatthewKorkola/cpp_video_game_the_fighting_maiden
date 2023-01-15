/**
 * @brief A starting title screen
 *
 * This class draws a title screen when the game is run
 * @author Yakup Tezcan
 */
#ifndef THEFIGHTINGMAIDEN_TITLESCREENSTATE_H
#define THEFIGHTINGMAIDEN_TITLESCREENSTATE_H
#endif //THEFIGHTINGMAIDEN_TITLESCREENSTATE_H
#include "State.h"

class TitleScreenState:public State{
public:
    /**
    * @brief Title Screen constructor
    *
     * This function initializes titleScreen variable
    * @author Yakup Tezcan
    */
    TitleScreenState();
    /**
    * @brief Title Screen deconstructor
    *
    * @author Yakup Tezcan
    */
    ~TitleScreenState();
    /**
     * @brief Draws title screen
     *
     * This function draws the title screen when the game is run
     * @param window the current window that is passed to the function
     * @param clock the current time that is passed to the function
     */
    void drawScreen(sf::RenderWindow *window,  sf::Clock clock);
    /**
     * @brief Helper function for title screen
     *
     * This function helps to test if the title screen works
     * @return true if title screen works
     */
};