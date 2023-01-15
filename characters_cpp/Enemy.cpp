//
// Created by Xavier HIll Roy on 2022-10-27.
//
#include "Enemy.h"
#include <iostream>

Enemy::Enemy(float posX,float posY) {
    // this->enemySprite.setOrigin(0.f,0.f);
    this->initTexture(); // loads image to use
    this->initSprite(); // initialising sprite


    // Movement x, y variables
    xMovementVelocity = 1.f;
    yMovementVelocity = 1.f;

    // Health variables
    hp = 5;
    damage = 1;
    attackingStatus = true;
    damageClock = 0;
    
    // Position setter function
    this->enemySprite.setPosition(posX, posY);
    
    // Update function
    update();
}

// Deconstructor function
Enemy::~Enemy() {

}

// Update
void Enemy::update() {
//    move(); // doing movement directly in the game class

}

// Drawing the enemy 
void Enemy::render(sf::RenderTarget *target) {
    target->draw(this->enemySprite);

}

// Moves enemy
void Enemy::move(float playerX, float playerY){
    // start pos 300, 500
    // only moves between (400 - 800 Y and 200-400 X)
    // right is Positive x
    // left is negative x
    // up is negative y
    //
    // when player to the left of the enemy
    if (playerX < this->enemySprite.getPosition().x){
        this->enemySprite.move(-1*xMovementVelocity,0.f);
        this->m_hitbox.left+= this->xMovementVelocity*-1;

    }
    // player to the right
    else{
        this->enemySprite.move(xMovementVelocity,0.f);
        this->m_hitbox.left+= this->xMovementVelocity;
    }

    if (playerY <this->enemySprite.getPosition().y){
        this->enemySprite.move(0.f,-1*yMovementVelocity);
        this->m_hitbox.top+= this->yMovementVelocity*-1;
    }
    else{
        this->enemySprite.move(0.f,yMovementVelocity);
        this->m_hitbox.top+= this->yMovementVelocity;
    }

}

void Enemy::initTexture() {
    // Loads texture from file
    // Selects which part of sprite to load
    if (!this->enemyTexture.loadFromFile(spritePath)){ //
        std::cout<<"failed::Enemy::initTexture:cant load texture file" <<std::endl;
    }
}

void Enemy::initSprite() {
    // Initialising player sprite
    // Sets texture to the sprite
    this->enemySprite.setTexture(this->enemyTexture);
    // First image is 31 pixels from left side, and 23 pixels from top
    // Enemy is 30 pixels by 41 pixels
    this->enemySprite.setTextureRect( sf::IntRect(31,23,30,41));

    // resize sprite
    this->enemySprite.setScale(2.f,2.f);
    // this->enemySprite.setColor(sf::Color::Red);
}

// Getter function for enemy sprite
sf::Sprite Enemy::getEnemySprite() {
    return this->enemySprite;
}

// Getter function for global hitbox
sf::FloatRect Enemy::getGlobalHitbox() const {
    // return this->enemySprite.getTransform().transformRect(this->m_hitbox);
    return this->m_hitbox;
}

// Getter function for hitbox
void Enemy::setHitbox(const sf::FloatRect &hitbox) {
    this->m_hitbox = hitbox;
}

// Decrements health 
bool Enemy::decrementHealth(int damage) {
    this->hp-= damage;
    if (this->hp <=0) return true;
    else return false;
}

void Enemy::dead() {

}

int Enemy::getHP() {
    return hp;
}

void Enemy::setAttackingStatus(bool val) {
    this->damageClock = 0;
    this->attackingStatus = val;
}

bool Enemy::getAttackingStatus() {
    return this->attackingStatus;
}

void Enemy::incClock() {
    this->damageClock++;
}

int Enemy::getClock() {
    return this->damageClock;
}