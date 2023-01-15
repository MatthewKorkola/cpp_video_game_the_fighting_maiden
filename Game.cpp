//
// Created by Xavier HIll Roy on 2022-10-18.
//
#include "headers/Game.h"
#include "EnemyFactory.h"
#include <unistd.h>

// Initialising variables to null
void Game::initVariables() {
    this ->window = nullptr; // initialise to null pointer
    this ->pause = false;

}

// Initialising window
void Game::initWindow() {
    // Setting height
    this->videoMode.height = 720; 
    // Setting width
    this->videoMode.width = 1280; 
    this->window = new  sf::RenderWindow(this->videoMode, "The Fighting Maiden");
    // Make max frame rate 60
    this -> window->setFramerateLimit(60);
    // Turns off vsync
    this->window->setVerticalSyncEnabled(false);
}
sf::RenderWindow *Game:: getWindow(){
    return this ->window;
}
bool Game::getPause(){
    return this ->pause;
}
void Game::setPause(bool pause){
    this ->pause = pause;
}

// Constructor function
Game::Game() {
    // Makes window point to null pointer
    this->initVariables();

    // Creates window
    this->initWindow();

    // Draws background image
    this->initWorld();

    // Initialise player
    this-> initCharacter();

    // Call the title screen.
//    this->titleScreen();
    titleScreenState ->drawScreen(window, clock);

}

// Deconstructor function
Game::~Game() {
    delete this-> window; 
    delete this-> player;
    if (this->enemy!=NULL)
    delete this->enemy; 
    delete this->armour1;
    delete this->merchant;
    delete this->advisor;
    delete this->prophet;
}

// Game engine
void Game::run() {
    while (this->window->isOpen()){
        deltaTime = clock.restart().asSeconds();
        // Updates all inputs
        if(getPause()== false){
            this->update();
        }
        // Draws what has happened
        this->render();
    }

}

void Game::pollEvents() {
    /*
     * While there is an event e,
     * checks event  type and does corresponding action.
     * Poll events.
     * This is where we signal check.
     */
    while (this ->window->pollEvent(this->e)){ // returns if you can get an e, and places e data into var e
        // while we are getting an e from window save it into e var
        switch (this->e.type) { // checks e type
            // if someone closes window, it closes.
            case sf::Event::Closed:
                this->window->close();
                break;

        }
    }
}

// Updates the game logic (keyboard inputs etc..)
void Game::update() {
    this -> pollEvents(); // checks for any inputs or events
    this->updateMousePosition();
    this->player->update();
    this->enemy->incClock();

    if (this->enemy!=NULL){
        this->enemy->move(this->player->getPlayerSprite().getPosition().x,this->player->getPlayerSprite().getPosition().y);

    }

    // Make sure the player stays inside the window.
    stayInsideWindow();

    bool colliding = this->collisionDetection(this->player->getGlobalHitbox(), this->enemy->getGlobalHitbox());

    //if the enemy and the player are not colliding reset the AttackStatus
    if(!colliding){
        this->enemy->setAttackingStatus(true);

    }

    if (colliding && this->enemy->getHP()>0) {
        if (this->player->getAttackStatus() && !(this->player->getHasAttacked())) {

            this->player->setHasAttacked(true);


            if (this->enemy->decrementHealth(1)) { // if this method returns true it means enemy is dead
                //increase player score by 10 for killing enemy
                this->player->setScore(this->player->getScore() + 10);

            }

        } else if(this->enemy->getAttackingStatus()) {
            this->player->setHP(this->player->getHP() - 1); // reduce player health'
            this->player->move(-20.f, 1.f);

            //only allows enemy to do damage once every second per coll.
            this->enemy->setAttackingStatus(false);
            //this->player->move(-10.f, 1.f);
        }

    }
    bool armourCollison = this->collisionDetection(this->player->getGlobalHitbox(),this->armour1->getGlobalHitbox());
    if (armourCollison && !this->armour1->getCollected()){
        this->player->equipArmour(this->armour1);
        this->armour1->setCollected(true);
    }

    // Check for collision with the merchant.
    merchantCollision = this->collisionDetection(this->player->getGlobalHitbox(),this->merchant->getGlobalHitbox());
    // Check for collision with the advisor.
    advisorCollision = this->collisionDetection(this->player->getGlobalHitbox(),this->advisor->getGlobalHitbox());
    // Check for collision with the prophet.
    prophetCollision = this->collisionDetection(this->player->getGlobalHitbox(), this->prophet->getGlobalHitbox());

    // Check if the player is running.
    checkRunning();

    // checks for keyboard movement
    this->updateInput();
}

// visualising
void Game::render() {
    /*
     * Clears old frame
     * Renders object
     * Draws
     * Display objects
     * Renders game objects
     */

    // clear previous screen
    this ->window->clear();

    // draw background
    this->renderWorld();

    // Show the fire wall.
    fireWall();

    // Show the warp.
    warpToEnd();

    // Draw the health bar.
    drawHealthBar();

    // draw player
    this->player->render(this->window);

    // Draws enemy
    if (this->enemy->getHP()>0)
    this->enemy->render(this->window);
    // Finished drawing display to screen

    // draw armour
    if (!(this->armour1->getCollected()))
    {this ->armour1->render(this->window);}

    // Draws armour
    if (!(this->armour1->getCollected())){
        this ->armour1->render(this->window);
    }

    // Draw merchant
    this->merchant->render(this->window);

    if (merchantCollision) {
        if (!(this->armour1->getCollected())){
            // The merchant wants the player to buy his item.
            //merchant->changeDialogue("Buy Now!");
            merchantDialogue.setPosition(700.f,90.f);
            merchantDialogue.setString("Buy Now!");
        }
        else {
            // The item is bought, so change the dialogue.
            //merchant->changeDialogue("Come Again!");
            merchantDialogue.setPosition(650.f, 80.f);
            merchantDialogue.setString("Come Again!");
        }
        // Show the NPC dialogue.
        this->window->draw(merchantDialogue);
    }

    // Draw advisor
    this->advisor->render(this->window);

    if (advisorCollision) {
        if (this->enemy->getHP() > 0){
            // The advisor wants to help the player defeat his foes.
            //advisor->changeDialogue("Defeat all enemies!);
            advisorDialogue.setPosition(140.f,550.f);
            advisorDialogue.setString("Defeat all enemies!");
        }
        else {
            // Congratulate the player.
            //advisor->changeDialogue("My friend, well done");
            advisorDialogue.setPosition(150.f,560.f);
            advisorDialogue.setString("My friend, well done");
        }
        // Show the NPC dialogue.
        this->window->draw(advisorDialogue);

    }

    // Draw prophet
    this->prophet->render(this->window);

    if (prophetCollision) {
        if (this->enemy->getHP() > 0){
            // The prophet wants to warn the player about the fire wall.
            prophetDialogue.setPosition(30.f,330.f);
            prophetDialogue.setString("Beware the Fire!");
        }
        else {
            // Tell the player to seek the blue warp.
            //advisor->changeDialogue("My friend, well done");
            prophetDialogue.setPosition(5.f,330.f);
            prophetDialogue.setString("Seek the Blue Light!");
        }
        // Show the NPC dialogue.
        this->window->draw(prophetDialogue);

    }

    this -> window->display();

    // Check if the player wants to quit.
    quitOrContinue();

    // Check if the game is over.
    if (this->player->getHP() <= 0) {
        state ->drawScreen(window);
        exit(0);
    }

}

// Updates all inputs.
void Game::updateInput() {
    // This is keyboard movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // moving left
        this->player->move(-1.f, 0.f); // -1 is multiplied to movement speed to indicate which direction it should be moving
        this->player->animationState = MOVING_LEFT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ // moving right
        this->player->move(1.f, 0.f);
        this->player->animationState = MOVING_RIGHT; // Change animation state
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ // up
        this->player->move(0.f, -1.f);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ // moving left
        this->player->move(0.f, 1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)){

        //drawPauseState();
    }

    // Only attack if the cool down time has passed and the player is pressing k
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K) && this->player->getAttackStatus() == false){

        this->player->attackAnimation();
    }
    if (this->player->getAttackClock() > 100){
        this->player->UpdatePullWeaponOut();
    }

    if(this->enemy->getClock() > 100){
        this->enemy->setAttackingStatus(true);
    }
}
void Game::drawPauseState(){
    setPause(true);
    pauseState ->drawScreen(this ->window);
    while(getPause()) {// moving left

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U)){
            setPause(false);
        }
    }
}

// Initialising world
void Game::initWorld() {
    /*
     * Loads background picture
     */

    // Loads specific image based on world traversal
    if(!this->worldTexture.loadFromFile(worldSpritePath))
        std::cout<<"ERROR CANT LOAD BACKGROUND"<<std::endl;
    this->worldBackground.setTexture(this->worldTexture);
    this->worldBackground.setScale(5.0f,5.0f);
}

// Initialising character
void Game::initCharacter() {
    // initialises player player
    this->player = Player::instance();
    // initialise player animation

    //Initialises enemy hit box
    sf::Sprite playerSprite = this->player->getPlayerSprite();


    float  playerSpriteWidth = (float)this->player->getPlayerSprite().getGlobalBounds().width;
    float  playerSpriteHeight = (float)this->player->getPlayerSprite().getGlobalBounds().height;
    float playerLeft = (float)this->player->getPlayerSprite().getPosition().x;
    float playerTop = (float)this->player->getPlayerSprite().getPosition().y;

    this ->player->setHitbox({playerLeft, playerTop, playerSpriteWidth, playerSpriteHeight});

    this->enemy = factory.makeEnemy(this->enemy);

    // Armour*/
    this->armour1 = new Armour();
    // Sets the armour sprite
    // Location, width, height
    this->armour1->setHitbox({this->armour1->getArmourSprite().getPosition().x,
                              this->armour1->getArmourSprite().getPosition().y
                              ,this->armour1->getArmourSprite().getGlobalBounds().width,
                              this->armour1->getArmourSprite().getGlobalBounds().height
                              });

    // Merchant
    this->merchant = new FriendlyNPC;
    // Set the merchant sprite, location, width, and height.
    this->merchant->setHitbox({this->merchant->getNPCSprite().getPosition().x,
                             this->merchant->getNPCSprite().getPosition().y
                                    ,this->merchant->getNPCSprite().getGlobalBounds().width,
                             this->merchant->getNPCSprite().getGlobalBounds().height
                            });

    // Advisor
    this->advisor = new FriendlyNPC;
    // Set the merchant sprite, location, width, and height.
    this->advisor->changeLocation(250.f, 590.f);
    this->advisor->setHitbox({this->advisor->getNPCSprite().getPosition().x,
                               this->advisor->getNPCSprite().getPosition().y
                                      ,this->advisor->getNPCSprite().getGlobalBounds().width,
                               this->advisor->getNPCSprite().getGlobalBounds().height
                              });

    // Prophet
    this->prophet = new FriendlyNPC;
    // Set the merchant sprite, location, width, and height.
    this->prophet->changeLocation(110.f, 370.f);
    this->prophet->setHitbox({this->prophet->getNPCSprite().getPosition().x,
                              this->prophet->getNPCSprite().getPosition().y
                                     ,this->prophet->getNPCSprite().getGlobalBounds().width,
                              this->prophet->getNPCSprite().getGlobalBounds().height
                             });

    // Create the merchant dialogue.
    if (!merchantFont.loadFromFile("fonts/FFF_Tusj.ttf")) {
        throw("Font could not be loaded");
    }
    merchantDialogue.setFont(merchantFont);
    merchantDialogue.setString(merchant->getDialogue());
    merchantDialogue.setCharacterSize(30);
    merchantDialogue.setFillColor(sf::Color::Cyan);
    merchantDialogue.setStyle(sf::Text::Bold);
    merchantDialogue.setPosition(700.f, 90.f);

    // Create the advisor dialogue.
    if (!advisorFont.loadFromFile("fonts/FFF_Tusj.ttf")) {
        throw("Font could not be loaded");
    }
    advisorDialogue.setFont(advisorFont);
    advisorDialogue.setString(advisor->getDialogue());
    advisorDialogue.setCharacterSize(30);
    advisorDialogue.setFillColor(sf::Color(8, 98, 117));
    advisorDialogue.setStyle(sf::Text::Bold);
    advisorDialogue.setPosition(700.f, 90.f);

    // Create the prophet dialogue.
    if (!prophetFont.loadFromFile("fonts/FFF_Tusj.ttf")) {
        throw("Font could not be loaded");
    }
    prophetDialogue.setFont(prophetFont);
    prophetDialogue.setString(prophet->getDialogue());
    prophetDialogue.setCharacterSize(30);
    prophetDialogue.setFillColor(sf::Color::Blue);
    prophetDialogue.setStyle(sf::Text::Bold);
    prophetDialogue.setPosition(700.f, 90.f);

}

void Game::renderWorld() {
    // Draws background image
    this->window->draw(this->worldBackground);
}

void Game::updateMousePosition() {
    // Updates the mouse position relative to window
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

// Colliison detection
bool Game::collisionDetection(sf::FloatRect hitbox1, sf::FloatRect hitbox2) {
    const bool colliding = hitbox1.intersects(hitbox2);
    return colliding;
}

// Written by Matthew Korkola
void Game::drawHealthBar() {

    // Never let max HP go above 10.
    if (player->getHP() > 10) {
        player->setHP(10);
    }

    // Create an empty health bar.
    sf::RectangleShape emptyHealthBar;
    // Set the empty health bar in the top left corner of the screen.
    sf::Vector2f emptyHealthBarPosition(20.f, 20.f);
    emptyHealthBar.setPosition(emptyHealthBarPosition);
    emptyHealthBar.setFillColor(sf::Color::Transparent);
    emptyHealthBar.setOutlineColor(sf::Color::Black);
    emptyHealthBar.setOutlineThickness(5);
    emptyHealthBar.setSize(sf::Vector2f(300.f, 32.f));

    // Draw the empty health bar.
    this->window->draw(emptyHealthBar);

    // Create the health bar.
    sf::RectangleShape healthBar;

    // Set the health bar in the top left corner of the screen.
    sf::Vector2f healthBarPosition(20.f, 20.f);
    healthBar.setPosition(healthBarPosition);


    // The size of the health bar is dependent on the amount of health
    // left over. The lower the HP value, the smaller the health bar.
    switch(this->player->getHP()) {
        case 10:
            healthBar.setSize(sf::Vector2f(300.f, 32.f));
            break;
        case 9:
            healthBar.setSize(sf::Vector2f(270.f, 32.f));
            break;
        case 8:
            healthBar.setSize(sf::Vector2f(240.f, 32.f));
            break;
        case 7:
            healthBar.setSize(sf::Vector2f(210.f, 32.f));
            break;
        case 6:
            healthBar.setSize(sf::Vector2f(180.f, 32.f));
            break;
        case 5:
            healthBar.setSize(sf::Vector2f(150.f, 32.f));
            break;
        case 4:
            healthBar.setSize(sf::Vector2f(120.f, 32.f));
            break;
        case 3:
            healthBar.setSize(sf::Vector2f(90.f, 32.f));
            break;
        case 2:
            healthBar.setSize(sf::Vector2f(60.f, 32.f));
            break;
        case 1:
            healthBar.setSize(sf::Vector2f(30.f, 32.f));
            break;
        default:
            healthBar.setSize(sf::Vector2f(300.f, 32.f));
    }

    healthBar.setOutlineColor(sf::Color::Black);
    healthBar.setOutlineThickness(5);

    // The health bar colour represents how much HP the player has left.
    // Green: high
    // Yellow: medium
    // Red: low
    if (this->player->getHP() > 5) {
        healthBar.setFillColor(sf::Color::Green);
    }
    else if (this->player->getHP() > 2) {
        healthBar.setFillColor(sf::Color::Yellow);
    }
    else if (this->player->getHP() > 0) {
        healthBar.setFillColor(sf::Color::Red);
    }
    else {
        healthBar.setFillColor(sf::Color::Transparent);
    }

    // Draw the health bar.
    this->window->draw(healthBar);
}

// Written by Matthew Korkola
void Game::gameOver() {
    // If player HP reaches 0, the game is over.
    if (this->player->getHP() <= 0) {
        // Make the entire screen go dark.
        sf::RectangleShape gameOverScreen;
        sf::Vector2f gameOverScreenPosition(0.f, 0.f);
        gameOverScreen.setPosition(gameOverScreenPosition);
        gameOverScreen.setFillColor(sf::Color::Black);
        gameOverScreen.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
        this->window->draw(gameOverScreen);

        // Print "Game Over" to the screen.
        sf::Font font;
        if (!font.loadFromFile("fonts/FFF_Tusj.ttf")) {
            throw("Font could not be loaded");
        }
        sf::Text gameOverText;
        gameOverText.setFont(font);
        gameOverText.setString("Game Over");
        gameOverText.setCharacterSize(150);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setStyle(sf::Text::Bold);
        gameOverText.setPosition(220.f, 250.f);
        this->window->draw(gameOverText);
        // The window must be displayed again to see the game over screen.
        this -> window->display();
        sleep(3);
        // The game is over, so exit.
        this->window->close();

    }
}

// Written by Matthew Korkola
void Game::checkRunning() {
    // hold "M" to run.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
        this->player->setMovementSpeed(10.f);
    }
    else {
        this->player->setMovementSpeed(5.f);
    }
}

// Written by Matthew Korkola
void Game::quitOrContinue() {
    // Press "Y" to quit.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y)) {
        this->window->close();
    }
}

// Written by Matthew Korkola
void Game::fireWall() {
    // The fire wall is a hazard designed to
    // keep the player alert at all times.

    // Only create the fire wall once.
    // The length of the y direction of the window is 720 units.
    // So each fire wall segment should be 144 units in the y direction.
    if (!fireMake) {
        sf::Vector2f wallFire1Position(900.f, 0.f);
        wallFire1.setPosition(wallFire1Position);
        wallFire1.setOutlineThickness(4);
        wallFire1.setOutlineColor(sf::Color(208, 148, 0));
        wallFire1.setSize(sf::Vector2f(100, 144));

        sf::Vector2f wallFire2Position(900.f, 144.f);
        wallFire2.setPosition(wallFire2Position);
        wallFire2.setOutlineThickness(4);
        wallFire2.setOutlineColor(sf::Color(208, 148, 0));
        wallFire2.setSize(sf::Vector2f(100, 144));

        sf::Vector2f wallFire3Position(900.f, 288.f);
        wallFire3.setPosition(wallFire3Position);
        wallFire3.setOutlineThickness(4);
        wallFire3.setOutlineColor(sf::Color(208, 148, 0));
        wallFire3.setSize(sf::Vector2f(100, 144));

        sf::Vector2f wallFire4Position(900.f, 432.f);
        wallFire4.setPosition(wallFire4Position);
        wallFire4.setOutlineThickness(4);
        wallFire4.setOutlineColor(sf::Color(208, 148, 0));
        wallFire4.setSize(sf::Vector2f(100, 144));

        sf::Vector2f wallFire5Position(900.f, 576.f);
        wallFire5.setPosition(wallFire5Position);
        wallFire5.setOutlineThickness(4);
        wallFire5.setOutlineColor(sf::Color(208, 148, 0));
        wallFire5.setSize(sf::Vector2f(100, 144));
        fireMake = true;

    }

    // Alternate colours.
    fireTime = sf::seconds(0.6);
    if (fireClock.getElapsedTime() >= fireTime) {
        if (drawFire) {
            drawFire = false;
        }
        else {
            drawFire = true;
        }
        fireClock.restart();
    }

    if (drawFire) {
        wallFire1.setFillColor(sf::Color (164, 39, 13));
        wallFire2.setFillColor(sf::Color (164, 39, 13));
        wallFire3.setFillColor(sf::Color (164, 39, 13));
        wallFire4.setFillColor(sf::Color (164, 39, 13));
        wallFire5.setFillColor(sf::Color (164, 39, 13));
    }
    else {
        wallFire1.setFillColor(sf::Color (142, 44, 12));
        wallFire2.setFillColor(sf::Color (142, 44, 12));
        wallFire3.setFillColor(sf::Color (142, 44, 12));
        wallFire4.setFillColor(sf::Color (142, 44, 12));
        wallFire5.setFillColor(sf::Color (142, 44, 12));
    }

    // Keep fire wall 1, 3, and 5 synchronized.
    // Keep fire wall 2 and 4 synchronized.
    activateFireTime = sf::seconds(1);
    if (activateFireClock.getElapsedTime() >= activateFireTime) {
        if (activateDrawFire) {
            activateDrawFire = false;
        }
        else {
            activateDrawFire = true;
        }
        activateFireClock.restart();
    }

    // Draw the fire wall.
    if (activateDrawFire) {
        this->window->draw(wallFire1);
        this->window->draw(wallFire3);
        this->window->draw(wallFire5);
    }
    else {
        this->window->draw(wallFire2);
        this->window->draw(wallFire4);
    }

    // Left or Right?
    // Also account for if the player is in fullscreen mode.
    if (wallFire1.getPosition().x >= this->window->getSize().x || wallFire1.getPosition().x >= 1280 || wallFire1.getPosition().x <= 0) {
        movementValue1 *= movementDirection1;
    }
    wallFire1.move(movementValue1, 0);

    if (wallFire2.getPosition().x >= this->window->getSize().x || wallFire2.getPosition().x >= 1280 || wallFire2.getPosition().x <= 0) {
        movementValue2 *= movementDirection2;
    }
    wallFire2.move(movementValue2, 0);

    if (wallFire3.getPosition().x >= this->window->getSize().x || wallFire3.getPosition().x >= 1280 || wallFire3.getPosition().x <= 0) {
        movementValue3 *= movementDirection3;
    }
    wallFire3.move(movementValue3, 0);

    if (wallFire4.getPosition().x >= this->window->getSize().x || wallFire4.getPosition().x >= 1280 || wallFire4.getPosition().x <= 0) {
        movementValue4 *= movementDirection4;
    }
    wallFire4.move(movementValue4, 0);

    if (wallFire5.getPosition().x >= this->window->getSize().x || wallFire5.getPosition().x >= 1280 || wallFire5.getPosition().x <= 0) {
        movementValue5 *= movementDirection5;
    }
    wallFire5.move(movementValue5, 0);

    // Check for collision with the player.
    // Check if the player intersects with the warp
    fire1Collision = this->collisionDetection(this->player->getGlobalHitbox(), wallFire1.getGlobalBounds());
    fire2Collision = this->collisionDetection(this->player->getGlobalHitbox(), wallFire2.getGlobalBounds());
    fire3Collision = this->collisionDetection(this->player->getGlobalHitbox(), wallFire3.getGlobalBounds());
    fire4Collision = this->collisionDetection(this->player->getGlobalHitbox(), wallFire4.getGlobalBounds());
    fire5Collision = this->collisionDetection(this->player->getGlobalHitbox(), wallFire5.getGlobalBounds());

    if (fire1Collision && activateDrawFire) {
        // Decrement player health by 2.
        // Give the player knockback.
        this->player->setHP(this->player->getHP() - 1);
        this->player->move(-20.f, 1.f);
    }

    if (fire2Collision && !activateDrawFire) {
        // Decrement player health by 2.
        // Give the player knockback.
        this->player->setHP(this->player->getHP() - 1);
        this->player->move(-20.f, 1.f);
    }

    if (fire3Collision && activateDrawFire) {
        // Decrement player health by 2.
        // Give the player knockback.
        this->player->setHP(this->player->getHP() - 1);
        this->player->move(-20.f, 1.f);
    }

    if (fire4Collision && !activateDrawFire) {
        // Decrement player health by 2.
        // Give the player knockback.
        this->player->setHP(this->player->getHP() - 1);
        this->player->move(-20.f, 1.f);
    }

    if (fire5Collision && activateDrawFire) {
        // Decrement player health by 2.
        // Give the player knockback.
        this->player->setHP(this->player->getHP() - 1);
        this->player->move(-20.f, 1.f);
    }
}

// Written by Matthew Korkola
void Game::titleScreen() {
    // Load font
    sf::Font font;
    if (!font.loadFromFile("fonts/FFF_Tusj.ttf")) {
        throw("Font could not be loaded");
    }
    // Create the title screen.
    sf::RectangleShape titleScreen;
    sf::Vector2f titleScreenPosition(0.f, 0.f);
    titleScreen.setPosition(titleScreenPosition);
    titleScreen.setFillColor(sf::Color (0, 50, 115));
    titleScreen.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

    // The title text is "The Fighting Maiden" and "Press C to Continue"
    sf::Text the;
    the.setFont(font);
    the.setString("The");
    the.setCharacterSize(125);
    the.setFillColor(sf::Color (220, 0, 0));
    the.setPosition(200.f, 10.f);

    sf::Text fighting;
    fighting.setFont(font);
    fighting.setString("Fighting");
    fighting.setCharacterSize(225);
    fighting.setFillColor(sf::Color::Red);
    fighting.setStyle(sf::Text::Bold);
    fighting.setPosition(15.f, 150.f);

    sf::Text maiden;
    maiden.setFont(font);
    maiden.setString("Maiden");
    maiden.setCharacterSize(175);
    maiden.setFillColor(sf::Color (0, 255, 100));
    maiden.setPosition(600.f, 430.f);

    sf::Text play;
    play.setFont(font);
    play.setString("Press C to Continue");
    play.setCharacterSize(70);
    play.setFillColor(sf::Color::Black);
    play.setPosition(300.f, 620.f);

    // Prepare to make "Press C to continue" flash.
    bool drawPlay = false;
    sf::Clock clock1;
    sf::Time textTime;
    textTime = sf::seconds(1);
    clock.restart();

    do {
        // Draw the title screen.
        this -> window -> clear();
        this->window->draw(titleScreen);
        this->window->draw(the);
        this->window->draw(fighting);
        this->window->draw(maiden);
        if (clock.getElapsedTime() >= textTime) {
            if (drawPlay) {
                drawPlay = false;
            }
            else {
                drawPlay = true;
            }
            clock.restart();
        }

        // Make "Press C to continue" flash.
        if (drawPlay) {
            this->window->draw(play);
        }

        // The window must be displayed again to see the title screen.
        this -> window->display();
    }
    // Start the game when the player presses the "C".
    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C));
}

// Written by Matthew Korkola
void Game::warpToEnd() {
    // Make the warp change colours.
    warpTime = sf::seconds(0.9);
    if (warpClock.getElapsedTime() >= warpTime) {
        if (drawWarp) {
            drawWarp = false;
        }
        else {
            drawWarp = true;
        }
        warpClock.restart();
    }

    // Create a circle that represents a warp to the credits.
    sf::CircleShape warp(30);
    warp.setOutlineThickness(8);
    warp.setOutlineColor(sf::Color(0, 0, 180));
    warp.setPosition(1190, 630);

    // Victory condition: all enemies are defeated.
    // So neither draw nor give collision to the warp
    // until all enemies are defeated.

    if (drawWarp) {
        // This circle is lighter.
        warp.setFillColor(sf::Color(0, 0, 255));
        if (this->enemy->getHP() <= 0) {
            this->window->draw(warp);
        }
    }
    else {
        // This circle is darker.
        warp.setFillColor(sf::Color(0, 0, 120));
        if (this->enemy->getHP() <= 0) {
            this->window->draw(warp);
        }
    }

    // Check if the player intersects with the warp
    bool warpCollision = this->collisionDetection(this->player->getGlobalHitbox(), warp.getGlobalBounds());
    if (warpCollision && this->enemy->getHP() <= 0) {

        // Create the ending graphics and end the game.

        // Draw the title screen.
        sf::RectangleShape endScreen;
        sf::Vector2f endScreenPosition(0.f, 0.f);
        endScreen.setPosition(endScreenPosition);
        endScreen.setFillColor(sf::Color(21, 51, 48));
        endScreen.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
        this->window->draw(endScreen);

        // Print "Congratulations!" and "The End" to the screen.
        sf::Font font;
        if (!font.loadFromFile("fonts/FFF_Tusj.ttf")) {
            throw("Font could not be loaded");
        }
        sf::Text congratulations;
        congratulations.setFont(font);
        congratulations.setString("Congratulations!");
        congratulations.setCharacterSize(150);
        congratulations.setFillColor(sf::Color(222, 144, 31));
        congratulations.setPosition(30.f, 50.f);
        this->window->draw(congratulations);

        sf::Text theEnd;
        theEnd.setFont(font);
        theEnd.setString("The End");
        theEnd.setCharacterSize(300);
        theEnd.setFillColor(sf::Color(222, 144, 31));
        theEnd.setStyle(sf::Text::Bold);
        theEnd.setPosition(10.f, 280.f);
        this->window->draw(theEnd);
        // The window must be displayed again to see the game over screen.
        this -> window->display();
        sleep(5);
        // The game is over, so exit.
        this->window->close();
    }
}

// Written by Matthew Korkola
void Game::stayInsideWindow() {
    // The player has moved west of the screen, so move east.
    if (this->player->getGlobalHitbox().left < 0) {
        this->player->move(10.f, 0.f);
    }

    // The player has moved east of the screen, so move west.
    // Account for fullscreen mode.
    if (this->player->getGlobalHitbox().left > this->window->getSize().x || this->player->getGlobalHitbox().left > 1280) {
        this->player->move(-10.f, 0.f);
    }

    // The player has moved north of the screen, so move south.
    if (this->player->getGlobalHitbox().top < 0) {
        this->player->move(0.f, 10.f);
    }

    // The player has moved south of the screen, so move north.
    // Account for fullscreen mode.
    if (this->player->getGlobalHitbox().top > this->window->getSize().y || this->player->getGlobalHitbox().top > 720) {
        this->player->move(0.f, -10.f);
    }
}

const Game* Game::_instance = NULL;
Game Game::instance() {
    if(_instance == NULL){
        _instance = new Game();
    }
}
