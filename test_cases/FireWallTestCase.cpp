//
// Created by Matthew Korkola on 2022-11-28.
//

/*

#include "headers/FireWallTestCase.h"
#include "headers/Player.h"

// Test interaction with the fire wall.
int main() {


    // Make a player
    Player *player;

    // Initialize the player.
    player = Player::instance();


    // Initialize the fire wall. Simulate the player interacting
    // with the first segment of the fire wall at its starting position.
    sf::RectangleShape wallFire;
    sf::Vector2f wallFire1Position(900.f, 0.f);
    wallFire.setPosition(wallFire1Position);
    wallFire.setOutlineThickness(4);
    wallFire.setOutlineColor(sf::Color(208, 148, 0));
    wallFire.setSize(sf::Vector2f(100, 144));
    wallFire.setFillColor(sf::Color (164, 39, 13));

    // Test for collision.

    // The player and fire wall collide here.
    player->setHitbox({900, 0, 200, 300});
    bool warpCollisionTrue = player->getGlobalHitbox().intersects(wallFire.getGlobalBounds());

    // The player and fire wall do not collide here.
    player->setHitbox({500, 300, 200, 300});
    bool warpCollisionFalse = player->getGlobalHitbox().intersects(wallFire.getGlobalBounds());


    if (warpCollisionTrue && !warpCollisionFalse) {
        printf("Test Passed. Collision between the player and the fire wall works.");
    } else {
        printf("Test Failed");
    }

    delete player;
}

*/
