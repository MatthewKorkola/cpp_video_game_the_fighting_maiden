//
// Created by Matthew Korkola on 2022-11-28.
//

/*

#include "headers/BlueWarpTestCase.h"
#include "headers/Player.h"

// Test interaction with the blue warp.
int main(){


    // Make a player
    Player *player;

    // Initialize the player.
    player = Player::instance();


    // Create a circle that represents a warp to the credits.
    sf::CircleShape warp(30);
    warp.setOutlineThickness(8);
    warp.setOutlineColor(sf::Color(0, 0, 180));
    // The warp is set at this particular location.
    warp.setPosition(1190, 630);
    warp.setFillColor(sf::Color(0, 0, 255));

    // Test for collision.

    // The player and blue warp collide here.
    player->setHitbox({1190,630,200,300});
    bool warpCollisionTrue = player->getGlobalHitbox().intersects(warp.getGlobalBounds());

    // The player and blue warp do not collide here.
    player->setHitbox({790,230,200,300});
    bool warpCollisionFalse = player->getGlobalHitbox().intersects(warp.getGlobalBounds());


    if(warpCollisionTrue && !warpCollisionFalse){
        printf("Test Passed. Collision between the player and the blue warp works.");
    }else{
        printf("Test Failed");
    }

    delete player;
}

 */