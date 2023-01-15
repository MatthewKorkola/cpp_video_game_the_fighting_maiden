/**
 * @brief User controlled player class
 *
 * This class deals with the PLayer object, it creates everything needed for the player, and facilitates its actions.
 * The player Class inherits from the Character class (a player is a character).
 *
 * @authors Xavier Hill Roy, Sam Near
 */
#ifndef THEFIGHTINGMAIDEN_PLAYER_H
#define THEFIGHTINGMAIDEN_PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Character.h"
#include "Armour.h"
enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT};
class Player : public Character{

protected:
    Player();

private:
    static Player *_instance;
    // Boolean variables
    const std::string spritePath= "textures/redHood.png";
    bool isAttacking;
    bool hasAttacked;
    int currentImage = 1;


    // Sfml objects
    sf::IntRect currentFrame;
    sf::IntRect attackFrame;
    sf::FloatRect m_hitbox;
    sf::Sprite playerSprite;
    sf::Texture texture;

    int score;
    int hp;
    int armourProtection;
    int attackClock;
    Armour *armour;

    // Animation 
    float movementSpeed;
    sf::Clock animationTimer;


    // Setter methods
    /**
     * @brief initialises the player texture for the player sprite
     *
     * Loads the texture to be used for the player sprite. Outputs error messages if it doesnt load properly.
     * @author Xavier Hill Roy
     */
    void initTexture();
    /**
     * @brief Initialises the player sprite
     *
     * Gets loaded texture, and sets it as the sprite.
     * Set the current frame to be animated within the loaded texture ( the rectangle that has the desired sprite of character)
     * Sets the the rectangle to be animated as the current frame.
     * Scales the sprite.
     * @author Xavier Hill Roy
     */
    void initSprite();


public:
    short animationState;// move to private with getter and setteer
    // Constructor and destructor
    //return the instance of the object
    static Player * instance();
    virtual ~Player();


    // Hitbox functions
    /**
     *@brief getter method for the global hitbox of the player
     *
     * Overwrites the sf function, and returns the global hitbox of the player.
     * @return Float rectangle which represents the player hitbox
     * @author Sam Near
     */
    sf::FloatRect getGlobalHitbox() const;

    /**
     * @brief setter method for player hitbox
     *
     * sets the player's m_hitbox to the referenced float rect passed in
     * @param hitbox a reference to a float rectangle which represents the hitbox of the player
     * @author Sam Near
     */
    void setHitbox(const sf::FloatRect &hitbox);

    // Movement
    /**
     * @brief updates player logic
     *
     * Calls 2 update functions, one that updates attack clock and the other that updates the player animation
     *
     *@authors Xavier Hill Roy, Sam Near
     */
    void update();
    /**
     * @brief Draws the player onto the render target
     *
     * Draws the player onto the render target that is passed in as a parameter.
     * @param target The render target which the player is to be rendered to (in this case it will be the display)
     * @author Xavier Hill Roy
     */
    void render(sf::RenderTarget *target);
    /**
     * @brief Method that moves the player
     *
     * This method gets called from the updateInput method in the Game class, where the key press determines the dirX and dirY.
     *For the movement, this method makes use of the sprite movement function that comes with SFML.
     * Pass in the direction to be moved multiplied by the movement speed of the charcter, the player will move that many pixels in direction specified.
     * Method also updates the player hitbox so it is always consistent with player position
     * @param dirX float that indicates the x direction of the movement (determines if player moves right or left)
     * @param dirY Float that indicates the y direction of the movement (determines if player should move up or down)
     * @author Xavier Hill Roy
     */
    void move(const float dirX, const float dirY);
    /**
     * @brief Setter method for movement speed
     *
     * Sets movementSpeed attribute to the value passed in as a parameter
     * @param newMovementSpeed a float which indicates the number of pixels a player should be moved whenever the move function is called
     * @author Xavier Hill Roy
     */
    void setMovementSpeed(float newMovementSpeed);
    /**
     * @brief Method that increments the attack Clock
     *
     * Increments the attack clock by 1. This method is called in the update method.
     * @author Sam Near
     */
    void increaseAttackClock();

    // Animation
    /**
     * @brief Does an attack animation
     *
     * Selects an appropriate frame from the sprite sheet (an attacking frame), sets chosen frame as the rectangle to be rendered.
     * Increments the attack clock
     * Sets the attacking status to be true
     * @author Xavier Hill Roy
     * @author Sam Near
     */
    void attackAnimation();
    /**
     * @brief Initialise the animation of the player
     *
     * Restarts the animation timer, and sets the movement state as MOVING LEFT (the player is initially facing left)
     * @author Xavier Hill Roy
     */
    void initAnimation();
    /**
     * @brief Iterates through row of in the sprite sheet, moving from frame to frame, simulating movement
     *
     * If the animation timer has elapsed more time than desired switch time , change frames.
     * If it has reached the end of the row, go back to the start of the row.
     * Restarts animation timer.
     * Sets the current frame as the one selected.
     *Checks if the animation state is in a moving right state, if so flip the sprite if not keep the sprite in the left facing direction
     * @author Xavier Hill Roy
     *
     */
    void updateAnimation();


    // Accessor
    /**
     * @brief Getter method for the player sprite
     *
     * Gets the player sprite attribute and returns it
     *
     * @return the sprite which is associated to the player
     * @author Xavier Hill Roy
     */
    sf::Sprite getPlayerSprite();
    /**
     * @brief accesor for the player texture
     *
     * Gets the player texture attribute and returns it
     * @return Sf Texture associated with the player
     * @author Xavier Hill Roy
     */
    sf::Texture getPlayerTexture();
    /**
     *@brief getter method for the player score
     *
     * Gets the player score attribute and returns it
     * @return integer representing the player score
     * @author Sam Near
     */
    int getScore();
    /**
     * @brief setter method for the player score
     *
     * Sets the player score attribute with the value from the parameter
     * @param val the integer value that is to be set as the player score
     * @author Sam Near
     */
    void setScore(int val);

    // Attack functions
    /**
     * @brief getter method for the attack status
     *
     * Gets the attack status attribute from the player and returns it, this determines if the player is currently attacking
     * @return The attack status boolean if true then player is attacking
     * @author Xavier Hill Roy
     */
    bool getAttackStatus();
    /**
    * @brief getter method for the hasAttacked attribute
    *
    * Gets the hasAttacked attribute and returns it
    * @return The attack status boolean if true then player is attacking
    * @author Xavier Hill Roy
    */
    bool getHasAttacked();
    /**
     * @brief Setter methodd for the has attacked attribute
     *
     * Sets the has attacked attribute with the value of the param
     * @param attack Boolean variable to be set as the hasAttacked attribute
     * @author Xavier Hill Roy
     */
    void setHasAttacked(bool attack);
    /**
    * @brief Setter methodd for the setAttackStatus attribute
    *
    * Sets the setAttackStatus attribute with the value of the param
    * @param attack Boolean variable to be set as the setAttackStatus  attribute
    * @author Xavier Hill Roy
    */
    void setAttackStatus(bool attack);
    /**
     * @brief getter method for attack clock
     *
     * Gets the attack clock attribute and returns it
     * @return the attack clock value
     * @author Sam Near
     */
    int getAttackClock();
    /**
     * @brief Indicates that an attack has occurred and to switch back to a non attacking state
     *
     * Sets the player sprite rect back to a movement frame
     *sets the is atacking attribute to false
     * sets the has attacked attribute to false
     * restarts the attack clock (sets it to 0)
     * @author Xavier Hill Roy
     */
    void UpdatePullWeaponOut();

    // Hp functions
    /**
     * @brief Getter method for hp attribute
     *
     * gets the value for hp attribute and returns it
     * @return integer that represents the hp value
     * @author Xavier Hill Roy
     */
    int getHP();
    /**
     * @brief Setter method for hp attribute
     *
     * Sets the hp attribute by the value from the parameter
     * @param hp int that will be set as the hp attribute for the player
     * @author Xavier Hill Roy
     */
    void setHP(int hp);

    // Armour functions
    /**
     * @brief Sets armour for the player
     *
     * Sets the armour passed in by the parameter as the players armour
     * it first changes the color of the player to indicate thge armour / potion is active
     * sets the armour protection value by the amount of protection the armour does
     * Increments the player HP by the amount of protection armour / potion does
     * Sets the armour using the armour setter method
     * @param armour The armour object that is to be set as the player armour
     * @author Xavier Hill Roy
     */
    void equipArmour(Armour *armour);
    /**
     * @brief setter method for the armour protection attribute
     *
     * Sets the vlaue of the param as the value for the armour protection attribute of the player
     *
     * @param protection int that represents protection level
     * @author Xavier Hill Roy
     */
    void setArmourProtection(int protection);
    /**
     * @brief setter method for player armour
     *
     * Sets the player armour attribute with the armour passed in as a parameter
     * @param armour Pointer to armour object to be set as the players armour
     * @author Xavier Hill Roy
     */
    void setArmour(Armour *armour);
    /**
     * @brief Getter method for the armour protection value
     *
     * Gets the value from the protection value attribute and returns it
     * @return int representing the protection value of the armour
     * @author Xavier Hill Roy
     *
     */
    int getArmourProtection();
    /**
     * @brief getter method for movement speed
     *
     * Getter method that returns the movement speed of the player
     * @return float representing the movement speed of the player
     */
    float getMovementSpeed();
    /**
     * @brief getter method for armour
     *
     * Getter method that returns the armour of the player
     * @return Arrmour object of the player
     */
    Armour getArmour();
    /**
    * @brief getter method for the currentFrame attribute
    *
    * Gets the currentFrame attribute and returns it
    * @return The IntRect of the current frame
    * @author Bryce Chevallier
    */
    sf::IntRect getCurrentFrame();
};
#endif //THEFIGHTINGMAIDEN_PLAYER_H