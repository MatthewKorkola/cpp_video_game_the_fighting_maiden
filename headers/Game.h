/**
 * @brief Game Engine class
 *
 * Actual running of the game, has a game loop, updates display based on input from user and game logic
 * @author Xavier Hill Roy
 * @author Sam Near
 * @author Matthew Korkola
 * @author Bryce Chevallier
 * @author Yakup Tezcan
 */
#ifndef THEFIGHTINGMAIDEN_GAME_H
#define THEFIGHTINGMAIDEN_GAME_H
#include "Player.h"
#include "Enemy.h"
#include "Armour.h"
#include "FriendlyNPC.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "EnemyFactory.h"
#include "GameOverState.h"
#include "PauseState.h"
#include "TitleScreenState.h"

class Game {
private:
    // This will change if we decide to use tiles
    // We might need to use arrays for tiles
    const std::string worldSpritePath = "textures/back.jpeg";

    // Window
    sf::RenderWindow *window; // pointer so we can close it dynamically allocate
    sf::VideoMode videoMode;

    // Event
    sf:: Event e;

    // Player
    Player *player;
    bool pause;
    GameOverState *state;
    PauseState *pauseState;
    TitleScreenState *titleScreenState;

    // Enemy
    Enemy *enemy;
    EnemyFactory factory;

    // Armour
    Armour *armour1;

    // FriendlyNPC
    FriendlyNPC *merchant;
    sf::Font merchantFont;
    sf::Text merchantDialogue;
    bool merchantCollision;
    FriendlyNPC *advisor;
    sf::Font advisorFont;
    sf::Text advisorDialogue;
    bool advisorCollision;
    FriendlyNPC *prophet;
    sf::Font prophetFont;
    sf::Text prophetDialogue;
    bool prophetCollision;

    // World
    sf::Texture worldTexture;
    sf::Sprite worldBackground;

    //Game position
    sf::Vector2i mousePosWindow;

    // delta time
    float deltaTime;
    sf::Clock clock;

    // Determine which warp colour should be used.
    sf::Clock warpClock;
    sf::Time warpTime;
    bool drawWarp = true;

    // only make the fire wall once.
    sf::RectangleShape wallFire1;
    sf::RectangleShape wallFire2;
    sf::RectangleShape wallFire3;
    sf::RectangleShape wallFire4;
    sf::RectangleShape wallFire5;
    float movementValue1 = 3.f;
    float movementValue2 = 3.f;
    float movementValue3 = 3.f;
    float movementValue4 = 3.f;
    float movementValue5 = 3.f;
    int movementDirection1 = -1;
    int movementDirection2 = -1;
    int movementDirection3 = -1;
    int movementDirection4 = -1;
    int movementDirection5 = -1;
    bool fireMake = false;
    // Check for collision with the player.
    bool fire1Collision;
    bool fire2Collision;
    bool fire3Collision;
    bool fire4Collision;
    bool fire5Collision;
    // change the firewall colours.
    sf::Clock fireClock;
    sf::Time fireTime;
    bool drawFire = true;
    // Keep fire wall 1, 3, and 5 synchronized.
    // Keep fire wall 2 and 4 synchronized.
    sf::Clock activateFireClock;
    sf::Time activateFireTime;
    bool activateDrawFire = true;

    // Functions for the world
    /**
     * @brief Initialises game variables ( pause and window)
     *
     * sets window attribute to a null pointer, (this is to ensure initialisation)
     * sets pause to false
     * @author Xavier Hill Roy
     * @author
     */
    void initVariables();
    /**
     * @brief Intialises the game window
     *
     * Sets width, height, fps liimit, and turns off vsync
     * @author  Xavier Hill Roy
     */
    void initWindow();
    /**
     * @brief Initialises all the characters of the world
     *
     * Gets instance of player, set player hitbox
     * Creates enemy using factoryu pattern
     * Creates instance of armour and creates hitbox
     * Creates NPC's, sets their location, hitbox and dialogue
     *
     * @author  Xavier Hill Roy
     * @author Matthew Korkola
     * @author Sam Near
     * @author Bryce Chevallier
     */
    void initCharacter();
    /**
     * @brief Loads backfround image in
     *
     * Gets background image, loads it in as a texture, sets it as the worlds background and scales the texture.
     * @author Xavier Hill Roy
     */
    void initWorld();
    /**
     * @brief Gets the mouse positon
     *
     * Gets mouse position relative to the window
     * @author Xavier Hill Roy
     */
    void updateMousePosition();
    static const Game *_instance;
protected:

public:
    // Constructor and destructor
    /**
     * @brief
     *
     * @author
     */
    Game();
    /**
     * @brief
     *
     * @return
     * @author Sam Near
     */
    static Game instance();
    /**
     * @brief Game destructor
     *
     *Destroys the game object
     * @author Xavier Hill Roy
     */
    virtual ~Game();
    /**
     * @brief Getter method for display window
     *
     * Getter method for the display window, returns the display window attribute
     * @return Render Window Object
     * @author Xavier Hill Roy
     */
    sf::RenderWindow *getWindow();
    /**
     * @brief getter method for pause
     *
     * Getter method for the pause attribute of the game, if if pause boolean is true you are in the pause state
     * @return A boolean which represents pause,
     * @author Yakup Tezcan
     */
    bool getPause();
    /**
     * @brief Setter method for pause
     *
     * setter method for the pause boolean, set true if the state is in pause
     * @param pause Boolean that returns
     * @author Yakup Tezcan
     */
    void setPause(bool pause);
    /**
     * @brief Draws the pause screen
     *
     * while the pause state is set to true the pause screen is drawn, when U is pressed the pause state is set to false
     * @author Yakup Tezcan
     */
    void drawPauseState();

    // Functions
    /**
     * @brief Game Engine
     *
     * resets delta time
     * Updates thhe logic by calling the update function
     * WHile the window is open render events
     *
     * @author Xavier Hill Roy
     * @author Yakup Tezcan
     */
    void run();
    /**
     * @brief Polls events
     *
     * WHile there is an event, do the apropriate action
     * checks if window is closed and if so close the code
     *
     * @author Xavier Hill Roy
     */
    void pollEvents();
    /**
     * @brief Watches for keyboard inputs and does appropriate actions based on what key is pressed
     *
     * WASD controls movement, P to pause the game (when P is pressed paused state is drawn)
     * @author Xavier Hill Roy
     * @author Yakup Tezcan
     */
    void updateInput();
    /**
     * @brief Wrapper function for all logic that needs to be updated
     *
     * Calls poll events
     * Updates Mouse position
     * Updates player logic
     * UPdates the damage clock for enemy
     * @author Xavier Hill Roy
     */
    void update();
    /**
     * @brief Draws all the needed things to be displayed
     *
     * Clears previous screen
     * Renders all appropriate things
     *
     * @author Xavier Hill Roy
     * @author Matthew Korkola
     */
    void render();
    /**
     * @brief Draws the world
     *
     * Renders the background on the window
     * @author Xavier Hill Roy
     */
    void renderWorld();
    /**
     * @brief Checks if 2 hitboxes are colliding
     *
     *Checks if the 2 hitboxes are intersecting if they are return true else return false
     * @param hitbox1 Float rectangle representing Hitbox
     * @param hitbox2 Float rectangle representing Hitbox
     * @return Boolean indicating 2 hitboxes colliding if true
     * @author Sam Near
     */
    bool collisionDetection(sf::FloatRect hitbox1, sf::FloatRect hitbox2);
    /**
     * @brief Method that draws the player health bar
     *
     * Ensures the players max health is 10
     * Draws a new rectangle based on the hp level of the player
     * draws the health bar
     *
     * @author Matthew Korkola
     */
    void drawHealthBar();
    void gameOver();
    /**
     * @brief IF M is being pressed increase movement speed
     *
     * IF M is being pressed increase movement speed to 10, if M is not pressed then set back to 5.f
     *
     * @author Matthew Korkola
     */
    void checkRunning();
    /**
     * @brief Closes game if you press ym
     *
     * WHen input of y is pressed the game closes
     * @author Matthew Korkola
     */
    void quitOrContinue();
    /**
     * @brief Creates Moving fire wall
     *
     * Generates fires wall
     * ALternates between colours
     * MAkes the fire flicker
     * If fire wall gets to edge of screen switches direction
     * COllision detection with knockback
     *
     * @author Matthew Korkola
     */
    void fireWall();
    /**
     * @brief Draws the title screen
     *
     * Loads fonts, draws the title screen to the window, when C is pressed the game starts
     *
     * @author Matthew Korkola
     */
    void titleScreen();
    /**
     * @brief Draws a blue warp that takes player to end credits
     *
     * OSciliates between colors using SF clock
     * Creates circle
     * Only draws + gives collision when enemy is defeeated
     * CHecks collision with warp
     * Draws victory screen
     * @author Matthew Korkola
     */
    void warpToEnd();
    /**
     * @brief Ensures player stays inside window
     *
     * Collision detection that ensures player does not cross outside the window, if he crosses outside window push back into window
     *
     * @author Matthew Korkola
     */
    void stayInsideWindow();

    Animation *animation;
};
#endif //THEFIGHTINGMAIDEN_GAME_H