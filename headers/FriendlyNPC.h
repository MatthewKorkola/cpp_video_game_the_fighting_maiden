/**
 * @brief Class that repersents the non enemy NPC characters
 *
 * This class repersents the non enemy NPC characters, they have a
 * hitbox and dialog that will let the player interact with the npc
 *
 * @author Matthew Korkola
 */

#ifndef THEFIGHTINGMAIDEN_FRIENDLYNPC_H
#define THEFIGHTINGMAIDEN_FRIENDLYNPC_H


#include <SFML/Graphics.hpp>

class FriendlyNPC {
private:
    // Background photo
    const std::string spritePath =  "textures/player.png";

    std::string dialogueNPC;

    // Armour
    sf::Sprite spriteNPC;

    // Texture
    sf::Texture textureNPC;

    // Hitbox
    sf::FloatRect m_hitboxNPC;

    // Texture and Sprite
    /**
     * @brief initialized the armour texture for the NPC
     *
     * Loads the texture from the file that that is displayed to the screen
     */
    void initTexture();
    /**
     * @brief initializes the NPC sprite
     *
     * Gets the specific texture and sets it to the, set the current frame
     * to be loaded to the current frame and scales the sprite to an appropriate size.
     */
    void initSprite();

public:
    // Constructor and deconstructor
    /**
     * @brief Class constructor, calls functions initTexture and initSprite
     *
     * Sets the NPC dialog, and the position of the NPC
     */
    FriendlyNPC();
    /**
     * @brief Class destructor, unallocated memory
     *
     * Class destructor, unallocated memory
     */
    ~FriendlyNPC();

    // Drawing the NPC
    /**
     * @brief renders the object to the screen
     *
     * takes a target then renders the NPC object texture to that target
     * @param target where the object is getting rendered to. Screen object
     */
    void render(sf::RenderTarget *target);

    // Update function
    /**
     *
     */
    void update();


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
     * the NPC object hitbox
     * @param hitbox
     */
    void setHitbox(const sf::FloatRect &hitbox);

    /**
     * @brief function to return the sprite object
     *
     * function to return the sprite object
     * @return sprite object
     */
    sf::Sprite getNPCSprite();

    // Getter for dialogue
    /**
     * @brief getter method for the NPC Dialog
     *
     * getter method for the NPC dialog.
     * @return string of dialog
     */
    std::string getDialogue();

    // Setter for position
    /**
     * @brief function to change the x, y cords of the NPC
     *
     * function to change the x, y cords of the NPC
     * @param x new x pos of the NPC
     * @param y new y pos of the NPC
     */
    void changeLocation(float x, float y);

    // Setter for dialogue
    /**
     * @brief setter method for the dialog of the NPC
     *
     * setter method for the dialog of the NPC
     * @param newDialogue dialog to replace the old NPC dialog
     */
    void changeDialogue(std::string newDialogue);

    // Setter for spritePath
    /**
     * @brief setter method the sprite object of the NPC
     *
     * setter method the sprite object of the NPC
     * @param newSpritePath
     */
    void changeSprite(std:: string newSpritePath);
};

#endif //THEFIGHTINGMAIDEN_FRIENDLYNPC_H
