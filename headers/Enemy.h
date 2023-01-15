/**
 * @brief The enemy class
 *
 * THis class deals with the creation of the main enemy the player has to fight
 *
 * @authors Xavier Hill Roy, Sam Near
 */
#ifndef THEFIGHTINGMAIDEN_ENEMY_H
#define THEFIGHTINGMAIDEN_ENEMY_H
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Player.h"

class Enemy: public Character{
    // Sfml objects
private:

    const std::string spritePath= "textures/enemySpriteSheet.png";
    sf::FloatRect m_hitbox;
    sf::Sprite enemySprite;
    sf::Texture enemyTexture;
    sf::FloatRect hit_box;
    sf::IntRect currentFrame;

    // Variables
    int hp;
    int hpMax;
    int damage;
    bool attackingStatus;
    int damageClock;

    // Directions
    float xMovementVelocity;
    float yMovementVelocity;

public:
    // Constructor and destructor
    /**
     * @brief Enemy Constructor
     *
     * Calls intialialise texture and initialise sprite methods to (initialise the enemies appearance )
     * Sets the movement speed of the enemy
     * sets enemy hp, damage
     * sets atack status to true and damage clock to 0
     * sets the inital position of the enemy based on the param
     * @param posX  float that represents x coordinate of enemy
     * @param posY float that reps the y coordinate of enemy
     * @author Xavier Hill Roy
     * @author Sam Near
     */
    Enemy(float posX,float posY);

    /**
     * @brief enemy destructor
     *
     * method to destroy object
     */
    virtual ~Enemy();

    // Hitbox
    /**
   *@brief getter method for the global hitbox of the enemy
   *
   * Overwrites the sf function, and returns the global hitbox of the enemy.
   * @return Float rectangle which represents the enemy hitbox
   * @author Sam Near
   */
    sf::FloatRect getGlobalHitbox() const;
    /**
    * @brief setter method for enemy hitbox
    *
    * sets the enemy's m_hitbox to the referenced float rect passed in
    * @param hitbox a reference to a float rectangle which represents the hitbox of the enemy
    * @author Sam Near
    */
    void setHitbox(const sf::FloatRect &hitbox);


    void update();
    /**
   * @brief Draws the enemy onto the render target
   *
   * Draws the enemy onto the render target that is passed in as a parameter.
   * @param target The render target which the enemy is to be rendered to (in this case it will be the display)
   * @author Xavier Hill Roy
   */
    void render(sf::RenderTarget* target);
    /**
     * @brief Enemy movement method
     *
     * Moves enemy uses the sf:: sprite movement methods in sfml to move the sprite.
     * Conditions in method check the players position ( gets fed player position as parameter)
     * Logic to move towards player
     *
     * @param x float containing the player x position
     * @param y float containing player y position
     * @author Xavier HIll Roy
     */
    void move(float x, float y);
    
    // Sfml object init
    /**
    * @brief Initialises the enemy sprite
    *
    * Gets loaded texture, and sets it as the sprite.
    * Set the current frame to be animated within the loaded texture ( the rectangle that has the desired image of character)
    * Sets the the rectangle to be animated as the current frame.
    * Scales the sprite.
    * @author Xavier Hill Roy
    */
    void initSprite();
    /**
    * @brief initialises the enemy texture for the enemy sprite
    *
    * Loads the texture to be used for the enemy sprite. Outputs error messages if it doesnt load properly.
    * @author Xavier Hill Roy
    */
    void initTexture();

    // Enemy health
    /**
   * @brief Getter method for the enemy sprite
   *
   * Gets the enemy sprite attribute and returns it
   *
   * @return the sprite which is associated to the enemy
   * @author Xavier Hill Roy
   */
    sf::Sprite getEnemySprite();
    /**
     * @brief method that decrements the enemy health
     *
     * Decrements the enemy health by the amount indicated by the param
     * @param damage int that represents the amount of damage that is to be decremented from enemy hp
     * @return  a boolean, true if the enemy is dead
     * @author Xavier Hill Roy
     */
    bool decrementHealth(int damage);
    /**
    * @brief Getter method for hp attribute
    *
    * gets the value for hp attribute and returns it
    * @return integer that represents the hp value
    * @author Xavier Hill Roy
    */
    int getHP();

    void dead();

    /**
     * @brief Setter methodd for the setAttackStatus attribute
     *
     *  Sets the setAttackStatus attribute with the value of the param
     * @param val Boolean variable to be set as the setAttackStatus  attribute
     *  @author Xavier Hill Roy
     */
    void setAttackingStatus(bool val);
    /**
   * @brief getter method for the Attacking status  attribute
   *
   * Gets the attacking status attribute and returns it
   * @return The attack status boolean if true then enemy is attacking
   * @author Xavier Hill Roy
   */
    bool getAttackingStatus();

    /**
     * @brief Method that increments the damage Clock
     *
     * Increments the da,age clock by 1.
     * @author Sam Near
     */
    void incClock();
    /**
     * @brief getter method for damage clock
     *
     * Gets the value of damage clock and returns it
     * @return Int with current value of damage clock
     * @author Sam Near
     */
    int getClock();

};

#endif //THEFIGHTINGMAIDEN_ENEMY_H