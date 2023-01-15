//
// Created by Xavier HIll Roy on 2022-10-27.
//
#include "headers/Enemy.h"
#include <iostream>

Enemy::Enemy(float posX,float posY) {
    // this->enemySprite.setOrigin(0.f,0.f);
    this->initTexture(); // loads image to use
    this->initSprite(); // initialising sprite

    // Movement x, y variables
    xMovementVelocity = 1.f;
    yMovementVelocity = 1.f;

    // Health variables
    hp = 2;
    damage = 1;
    
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
    move();

}

// Drawing the enemy 
void Enemy::render(sf::RenderTarget *target) {
    target->draw(this->enemySprite);

}

// Moves enemy
void Enemy::move(){
    // start pos 300, 500
    // only moves between (400 - 800 Y and 200-400 X)
    if (this->enemySprite.getPosition().x < 200 || this->enemySprite.getPosition().x>400){
       this->xMovementVelocity*=-1;
    }
    this->m_hitbox.left+= this->xMovementVelocity;
    this->enemySprite.move(xMovementVelocity,0);
}

void Enemy::initTexture() {
    // Loads texture from file
    // Selects which part of sprite to load
    if (!this->enemyTexture.loadFromFile(spritePath)){ //
        std::cout<<"failed LOL::Enemy::initTexture:cant load texture file" <<std::endl;
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