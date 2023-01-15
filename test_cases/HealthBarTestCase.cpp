//
// Created by matth on 2022-11-28.
//

/*

#include "headers/HealthBarTestCase.h"
#include "headers/Player.h"

// Test interaction with the health bar.
int main(){

    // Make a player
    Player *player;

    // Initialize the player.
    player = Player::instance();

    // Create the health bar.
    sf::RectangleShape healthBar;

    // Set the health bar in the top left corner of the screen.
    sf::Vector2f healthBarPosition(20.f, 20.f);
    healthBar.setPosition(healthBarPosition);

    // Test that the health bar works properly by looping through every
    // possible size of the health bar (while decreasing the value of the player's health).
    // Note that the player starts with 10 health. If every condition is entered, then
    // the health bar works properly.

    bool HP10 = false;
    bool HP9 = false;
    bool HP8 = false;
    bool HP7 = false;
    bool HP6 = false;
    bool HP5 = false;
    bool HP4 = false;
    bool HP3 = false;
    bool HP2 = false;
    bool HP1 = false;
    bool HP0 = false;

    while (player->getHP() >= 0) {

        // The size of the health bar is dependent on the amount of health
        // left over. The lower the HP value, the smaller the health bar.
        switch(player->getHP()) {
            case 10:
                healthBar.setSize(sf::Vector2f(300.f, 32.f));
                HP10 = true;
                break;
            case 9:
                healthBar.setSize(sf::Vector2f(270.f, 32.f));
                HP9 = true;
                break;
            case 8:
                healthBar.setSize(sf::Vector2f(240.f, 32.f));
                HP8 = true;
                break;
            case 7:
                healthBar.setSize(sf::Vector2f(210.f, 32.f));
                HP7 = true;
                break;
            case 6:
                healthBar.setSize(sf::Vector2f(180.f, 32.f));
                HP6 = true;
                break;
            case 5:
                healthBar.setSize(sf::Vector2f(150.f, 32.f));
                HP5 = true;
                break;
            case 4:
                healthBar.setSize(sf::Vector2f(120.f, 32.f));
                HP4 = true;
                break;
            case 3:
                healthBar.setSize(sf::Vector2f(90.f, 32.f));
                HP3 = true;
                break;
            case 2:
                healthBar.setSize(sf::Vector2f(60.f, 32.f));
                HP2 = true;
                break;
            case 1:
                healthBar.setSize(sf::Vector2f(30.f, 32.f));
                HP1 = true;
                break;
            default:
                healthBar.setSize(sf::Vector2f(300.f, 32.f));
                HP0 = true;
        }

        // Decrement the player's health.
        player->setHP(player->getHP() - 1);

    }

    // Test that every size of the health bar has been reached.

    if(HP10 && HP9 && HP8 && HP7 && HP6 && HP5 && HP4 && HP3 && HP2 && HP1 && HP0){
        printf("Test Passed. The health bar works correctly.");
    } else{
        printf("Test Failed");
    }

    delete player;
}

*/