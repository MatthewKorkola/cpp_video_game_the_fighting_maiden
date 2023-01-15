//
// Created by Xavier HIll Roy on 2022-10-18.
//
#include <unistd.h>
#include "headers/Player.h"

// Constructor
Player::Player() {
    // this->playerSprite.setOrigin(0.f,0.f);
    // Initialising variables

    // Number of pixels traversed
    this-> movementSpeed = 5.f; 

    // Loads image to use
    this->initTexture();

    // Initialising sprite
    this->initSprite(); 

    // Attack variables
    this->isAttacking = false;
    this->hasAttacked = false;
    this->hp = 100;

    // No armour at first
    armour = nullptr;
    armourProtection = 0;
}

// Deconstructor
Player::~Player() {

}

// Sets the hit box of the player
void Player::setHitbox(const sf::FloatRect &hitbox) {
    this->m_hitbox = hitbox;
}

// Overwrites the sf:: function getGlobalHitbox with this function and returns the hitbox
sf::FloatRect Player::getGlobalHitbox() const {
    // return this->playerSprite.getTransform().transformRect(this->m_hitbox);
    return this->m_hitbox;
}

void Player::update() {
}

// Drawing player
void Player::render(sf:: RenderTarget *target) {
    target->draw(this->playerSprite);

}

// Initialising texture
void Player::initTexture() {
    // Loads texture from file
    // selects which part of sprite to load
    if (!this->texture.loadFromFile(spritePath)){ 
        std::cout<<"failed LOL::Player::initTexture:cant load texture file" <<std::endl;
    }
}

// Initialising sprite
void Player::initSprite() {
    // Initialising player sprite
    // Sets texture to the sprite
    this->playerSprite.setTexture(this->texture);
    currentFrame = sf::IntRect(49,66,16,31);

    // First image in sprite sheet is 49 pixels from left side and 66 from top
    this->playerSprite.setTextureRect(currentFrame);

    // Resizes sprite
    this->playerSprite.setScale(3.f,3.f);
}

// Moves the player
void Player::move(const float dirX, const float dirY) { // this way all objects have their own move method
    this->playerSprite.move(this->movementSpeed*dirX,this->movementSpeed*dirY);// if give 0 no moves if give 1 moves up or right, if -1 move left or down
    this->m_hitbox.left+= this->movementSpeed*dirX;
    this->m_hitbox.top += this->movementSpeed*dirY;
}

// Accessor methods
sf::Texture Player::getPlayerTexture() {
    return this->texture;
}

// Accessor methods
sf::Sprite Player::getPlayerSprite() {
    return this->playerSprite;
}

// Attack animation
void Player::attackAnimation(){
    this->attackFrame=  sf::IntRect(1262,867,42,32);
    this->playerSprite.setTextureRect(attackFrame);
    this->isAttacking = true;
}

// Player attack update
void Player::UpdatePullWeaponOut() {
    this->playerSprite.setTextureRect(currentFrame);
    this->isAttacking = false;
    this->hasAttacked = false;
}

// Attack status
bool Player::getAttackStatus() {
    return this->isAttacking;
}

// If the player has attacked
bool Player::getHasAttacked() {
    return hasAttacked;
}

// Sets the attack status
void Player::setHasAttacked(bool attack) {
    this->hasAttacked = attack;
}

// Sets the player HP
void Player::setHP(int hp) {
    this->hp = hp;
}

// Getter fpr HP
int Player::getHP(){
    return hp;
}

// Equiping the armour
void Player::equipArmour(Armour *armour) {
    // Colors the player in green
    this->playerSprite.setColor(sf::Color::Green);

    // Adds protection
    this->armourProtection = armour->getProtectionValue(); 
    this->setHP(this->getHP()+armour->getProtectionValue());
    setArmour(armour);
}

// Sets the armour protection of the player
void Player::setArmourProtection(int protection) {
        this->armourProtection =protection;
}

// Sets the armour 
void Player::setArmour(Armour *armour) {
    this->armour = armour;
}

// Getter for armour protection
int Player::getArmourProtection() {
    return armourProtection;
}

// Getter for armour
Armour Player::getArmour() {
    return *armour;
}