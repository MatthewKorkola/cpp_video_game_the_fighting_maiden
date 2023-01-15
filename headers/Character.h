/**
 * @brief Character Class
 *
 * T
 * There are no actual character objects but these are implemented by enemy and player
 *
 * @author Xavier Hill Roy
*/

#ifndef THEFIGHTINGMAIDEN_CHARACTER_H
#define THEFIGHTINGMAIDEN_CHARACTER_H
#include <SFML/Graphics.hpp>

class Character {

public:

    /**
     * @brief Movement function which is to be implmeneted by classes that inherit from character
     * @param x x direction float
     * @param y y direction float
     */
   void move(float x, float y);
    /**
      * @brief Draws the character onto the render target
      *
      *TO be implemented by classes which inherit it
      * @param target The render target which the character is to be rendered to (in this case it will be the display)
      * @author Xavier Hill Roy
      */
   void render(sf::RenderTarget &target);
    /**
   * @brief initialises the character texture for the character sprite
   *
   * To be implemented by classes which inherit it: Loads the texture to be used for the player sprite. Outputs error messages if it doesnt load properly.
   * @author Xavier Hill Roy
   */
   void initTexture();
    /**
      * @brief Initialises the character sprite
      *
      * TO be implemented by children class
      * Gets loaded texture, and sets it as the sprite.
      * Set the current frame to be animated within the loaded texture ( the rectangle that has the desired sprite of character)
      * Sets the the rectangle to be animated as the current frame.
      * Scales the sprite.
      *
      * @author Xavier Hill Roy
      */
   void initSprite();
   /**
    * @brief update relevant logic for character
    *
    * This is to be implmented by enemy and player
    * @author Xavier Hill Roy
    */
   void update();
};

#endif //THEFIGHTINGMAIDEN_CHARACTER_H