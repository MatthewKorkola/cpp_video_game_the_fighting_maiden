//
// Created by Matthew Korkola on 2022-11-16.
//

#include <iostream>
#include "FriendlyNPC.h"

// Constructor function
FriendlyNPC::FriendlyNPC() {
    initTexture();
    initSprite();
    dialogueNPC = "Buy now!";
    this->spriteNPC.setPosition(700.f,110.f);
}

// Deconstructor function
FriendlyNPC::~FriendlyNPC() {

}

// Update the NPC
void FriendlyNPC::update() {

}

// Render function to draw the armour
void FriendlyNPC::render(sf::RenderTarget *target) {
    target->draw(this->spriteNPC);
}

// getter for dialogue
std::string FriendlyNPC::getDialogue() {
    return this->dialogueNPC;
}

// Setter for Hitbox
void FriendlyNPC::setHitbox(const sf::FloatRect &hitbox) {
    this->m_hitboxNPC = hitbox;
}

// Overwrites the sf:: function getGlobalHitbox with this function and returns the hitbox
sf::FloatRect FriendlyNPC::getGlobalHitbox() const {
    //return this->armour.getTransform().transformRect(this->m_hitbox);
    return this->m_hitboxNPC;
}

// Texture function for the armour
void FriendlyNPC::initTexture() {
    // Loads texture from file
    // Select which part of sprite to load
    if (!this->textureNPC.loadFromFile(spritePath)){
        std::cout<<"failed LOL::Player::initTexture:cant load texture file" <<std::endl;
    }
}

void FriendlyNPC::initSprite() {
    // Initialising player sprite
    // Sets the texture to the sprite
    this->spriteNPC.setTexture(this->textureNPC);

    // First image in sprite sheet is 49 pixels from left side and 66 from top
    this->spriteNPC.setTextureRect(sf::IntRect(0,0,48,60));
    this->spriteNPC.scale(3.0f,3.0f);

    // Resize sprite
    // this->playerSprite.setScale(3.f,3.f);
}

// Getter function for NPCs
sf::Sprite FriendlyNPC::getNPCSprite() {
    return spriteNPC;
}

// Setter for NPC position
void FriendlyNPC::changeLocation(float x, float y) {
    this->spriteNPC.setPosition(x, y);
}

// Setter for dialogue.
void FriendlyNPC::changeDialogue(std::string newDialogue) {
    this->dialogueNPC = newDialogue;
}

// Setter for spritePath
void FriendlyNPC::changeSprite(std::string newSpritePath) {
    //this->spritePath = newSpritePath;
}


