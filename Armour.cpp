//
// Created by Xavier HIll Roy on 2022-11-07.
//
#include <iostream>
#include "Armour.h"

// Constructor function
Armour::Armour() {
    initTexture();
    initSprite();
    collected = false;
    protectionValue = 10;
    this->armour.setPosition(850.f,140.f);
}

// Deconstructor function
Armour::~Armour() {

}

// Render function to draw the armour
void Armour::render(sf::RenderTarget *target) {
    target->draw(this->armour);
}

// Protection value of the armour
int Armour::getProtectionValue() {
    return protectionValue;
}

// Update the armour
void Armour::update() {

}

// Setter for protection value
void Armour::setProtectionValue(int value) {
    this->protectionValue = value;
}
// Setter for Hitbox
void Armour::setHitbox(const sf::FloatRect &hitbox) {
    this->m_hitbox = hitbox;
}

// Overwrites the sf:: function getGlobalHitbox with this function and returns the hitbox
sf::FloatRect Armour::getGlobalHitbox() const {
    //return this->armour.getTransform().transformRect(this->m_hitbox);
    return this->m_hitbox;
}

// Texture function for the armour
void Armour::initTexture() {
    // Loads texture from file
    // Select which part of sprite to load
    if (!this->texture.loadFromFile(spritePath)){ 
        std::cout<<"failed LOL::Player::initTexture:cant load texture file" <<std::endl;
    }
}

void Armour::initSprite() {
    // Initialising player sprite
    // Sets the texture to the sprite
    this->armour.setTexture(this->texture);

    // First image in sprite sheet is 49 pixels from left side and 66 from top
    this->armour.setTextureRect(sf::IntRect(0,0,20,16));
    // Enlarge the sprite.
    armour.setScale(-3.f,3.f);

    // Resize sprite
    // this->playerSprite.setScale(3.f,3.f);
}

// Getter function for armour
sf::Sprite Armour::getArmourSprite() {
    return armour;
}

// Getter function for collected
bool Armour::getCollected() {
    return this->collected;
}

// Setter function for collected
void Armour::setCollected(bool status) {
    this->collected = status;
}