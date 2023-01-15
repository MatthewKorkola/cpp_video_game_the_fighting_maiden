/**
 * @brief Armour/potion class
 *
 * This class deals with a Armour/potion object, the player is able to
 * walk over this object and collect it.
 * when the player collects the armour/potion object then it resets their health to full
 *
 * @authors Xavier Hill Roy, Sam Near
 */
#ifndef THEFIGHTINGMAIDEN_ARMOUR_H
#define THEFIGHTINGMAIDEN_ARMOUR_H
#include <SFML/Graphics.hpp>

class Armour {
private:
    // Background photo
    const std::string spritePath= "textures/16x16/potion_03c.png";

    // Protection value
    int protectionValue;

    // Armour
    sf::Sprite armour;
    
    // Texture
    sf::Texture texture;

    // Hitbox
    sf::FloatRect m_hitbox;

    // Texture and Sprite
    /**
     * @brief initialized the armour texture for the armour potion
     *
     * Loads the texture from the file that that is displayed to the screen
     *
     * @authors Xavier Hill Roy, Sam Near
     */
    void initTexture();
    /**
     * @brief initializes the potion sprite
     *
     * Gets the specific texture and sets it to the, set the current frame
     * to be loaded to the current frame and scales the sprite to an appropriate size.
     * @author Xavier Hill Roy, Sam Near
     */
    void initSprite();

    // Boolean for collected
    bool collected;

public:
    /**
     * @brief Class constructor, calls functions initTexture and initSprite
     *
     * Sets the protection value, collected boolean, and starting position
     * @authors Xavier Hill Roy, Sam Near
     */
    Armour();
    /**
     * @brief Class destructor, unallocated memory
     *
     * Class destructor, unallocated memory
     * @authors Xavier Hill Roy, Sam Near
     */
    ~Armour();
    
    // Drawing the armor
    /**
     * @brief renders the object to the screen
     *
     * takes a target then renders the armour object texture to that target
     * @param target where the object is getting rendered to. Screen object
     * @authors Xavier Hill Roy, Sam Near
     */
    void render(sf::RenderTarget *target);

    // Protection function
    /**
     * @brief How much the armour object increases your health
     *
     * The protection value of the armour/potion
     * @return the protection value of the armour/potion
     * @authors Xavier Hill Roy, Sam Near
     */
    int getProtectionValue();

    // Update function
    void update();

    // Setter for protection value
    /**
     * @brief setter for the armour protection value
     *
     * setter for the armour protection value
     * @param Value you want to set the protection value you to
     * @authors Xavier Hill Roy, Sam Near
     */
    void setProtectionValue(int value);

    // Global sfml hitbox object
    /**
     * @brief getter method for the hitbox of the object
     *
     * getter method for the hitbox of the object
     * @return the hitbox of the armour/potion object
     */
    sf::FloatRect getGlobalHitbox() const;

    // Setter for hitbox
    /**
     * @brief sets the armour hitbox
     *
     * takes in an sfml hitbox in the form of a rectangle and sets it to
     * the armour object hitbox
     * @param hitbox
     * @authors Xavier Hill Roy, Sam Near
     */
    void setHitbox(const sf::FloatRect &hitbox);

    /**
     * @brief function to return the sprite object
     *
     * function to return the sprite object
     * @return sprite object
     */
    sf::Sprite getArmourSprite();

    // Getter and setter for collected
    /**
     * @brief setter method for the collected boolean, is true if it was picked up
     *
     * setter method for the collected boolean, is true if it was picked up
     * @param status
     * @authors Xavier Hill Roy, Sam Near
     */
    void setCollected(bool status);
    /**
     * @brief getter method for the collected boolean
     *
     * getter method for the collected boolean.
     * @return the value of collected boolean
     * @authors Xavier Hill Roy, Sam Near
     */
    bool getCollected();
};

#endif //THEFIGHTINGMAIDEN_ARMOUR_H