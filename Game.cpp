//
// Created by Xavier HIll Roy on 2022-10-18.
//
#include "headers/Game.h"

// Initialising variables to null
void Game::initVariables() {
    this ->window = nullptr; // initialise to null pointer

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
}

// Deconstructor function
Game::~Game() {
    delete this-> window; 
    delete this-> player; 
    if (this->enemy!=NULL)
    delete this->enemy; 
    delete this->armour1;
}

// Game engine
void Game::run() {
    while (this->window->isOpen()){
        // Updates all inputs
        this->update();
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
//            case sf::Event::KeyPressed:
//            break;
//            case sf::Event::KeyReleased:
//                sf::Keyboard::Key::K
        }
    }
}

// Updates the game logic (keyboard inputs etc..)
void Game::update() {
    this -> pollEvents(); // checks for any inputs or events
    this->updateMousePosition();
    this->player->update();
    if (this->enemy!=NULL){
        this->enemy->update();
    }
//    std::cout << "player position: " << this->player->getPlayerSprite().getPosition().x << ": ";
//    std::cout << this->player->getPlayerSprite().getPosition().y << std::endl;
//    std::cout << "enemy position: " << this->enemy->getEnemySprite().getPosition().x << ": ";
//    std::cout << this->enemy->getEnemySprite().getPosition().y << std::endl;

//// ENEMY COLLISIONS

    bool colliding = this->collisionDetection(this->player->getGlobalHitbox(), this->enemy->getGlobalHitbox());

    if (colliding &&this->enemy->getHP()>0) {
        if (this->player->getAttackStatus() && !(this->player->getHasAttacked())) {
            std::cout << this->enemy->getHP() << std::endl;
            this->player->setHasAttacked(true);

            if (this->enemy->decrementHealth(1)) { // if this method returns true it means enemy is dead
                std::cout<<"DEAD ENEMY"<<std::endl;
            }
        } else {
            this->player->setHP(this->player->getHP() - 1); // reduce player health'
            std::cout << "PLAYER HEALTH :" << this->player->getHP() << std::endl;

            this->player->move(-10.f, 1.f);
        }

//        std::cout << "COLLISION" << std::endl;
//        std::cout << "Player is Colliding with Enemy" << std::endl;
    }
    bool armourCollison = this->collisionDetection(this->player->getGlobalHitbox(),this->armour1->getGlobalHitbox());
    if (armourCollison && !this->armour1->getCollected()){
        this->player->equipArmour(this->armour1);
        this->armour1->setCollected(true);
    }
    this->updateInput(); // checks for keyboard movement
}

// visualising
void Game::render() {
    /*
     * Clears old frame
     * Renders object
     * Draws
     * Displas objects
     * Renders game objects
     */

    this ->window->clear(); // clear preven screen

    // draws background
//    this->renderWorld();

    // Draws player
    // draw background
    this->renderWorld();
    // draw player
    this->player->render(this->window);

    // Draws enemy
    if (this->enemy->getHP()>0)
    this->enemy->render(this->window);
    // Finished drawing display to screen
    //


    // draw armour
    if (!(this->armour1->getCollected()))
    {this ->armour1->render(this->window);}

    // Draws armour
    if (!(this->armour1->getCollected())){
        this ->armour1->render(this->window);
    }
    this -> window->display();
}

// Updates all inputs.
void Game::updateInput() {
    // This is keyboard movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // moving left
        this->player->move(-1.f, 0.f); // -1 is multiplied to movement speed to indicate which direction it should be moving
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ // moving left
        this->player->move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ // moving left
        this->player->move(0.f, -1.f);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ // moving left
        this->player->move(0.f, 1.f);
    }

    // ATTACK
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)){

        this->player->attackAnimation();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L)){
        this->player->UpdatePullWeaponOut();
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
}

// Initialising character
void Game::initCharacter() {
    // initialises player player
    this->player = new Player();

    //Initialises enemy hit box
    //std::cout << this->player->getPlayerSprite().getTexture()->getSize().x << std::endl;
    sf::Sprite playerSprite = this->player->getPlayerSprite();
    
    float  playerSpriteWidth = (float)this->player->getPlayerSprite().getGlobalBounds().width;
    float  playerSpriteHeight = (float)this->player->getPlayerSprite().getGlobalBounds().height;
    float playerLeft = (float)this->player->getPlayerSprite().getPosition().x;
    float playerTop = (float)this->player->getPlayerSprite().getPosition().y;

    this ->player->setHitbox({playerLeft, playerTop, playerSpriteWidth, playerSpriteHeight});

    // Initialises enemy hit box
    this ->enemy = new Enemy(300.f,50.f);
    // Enemy sprite
    // Location, width, height
    sf::Sprite enemySprite = this->enemy->getEnemySprite();
    float enemySpriteWidth = (float)this->enemy->getEnemySprite().getGlobalBounds().width;
    float enemySpriteHeight = (float)this->enemy->getEnemySprite().getGlobalBounds().height;
    float enemyLeft = (float)this->enemy->getEnemySprite().getPosition().x;
    float enemyTop = (float)this->enemy->getEnemySprite().getPosition().y;
    // Sets the hitbox of enemy
    this ->enemy->setHitbox({enemyLeft, enemyTop, enemySpriteWidth, enemySpriteHeight});
    // Armour
    this->armour1 = new Armour();
    // Sets the armour sprite
    // Location, width, height
    this->armour1->setHitbox({this->armour1->getArmourSprite().getPosition().x,
                              this->armour1->getArmourSprite().getPosition().y
                              ,this->armour1->getArmourSprite().getGlobalBounds().width,
                              this->armour1->getArmourSprite().getGlobalBounds().height
                              });
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