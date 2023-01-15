//
// Created by Matthew Korkola on 2022-11-28.
//

/*

#include "headers/InteractWithNPCTestCase.h"
#include "headers/FriendlyNPC.h"
#include "headers/Player.h"

// Test interaction with NPCs.
int main(){


    // Make a player and two NPCs.
    FriendlyNPC *npcInteract;
    FriendlyNPC *npcNotInteract;
    Player *player;

    // Initialize the player and NPCs.
    player = Player::instance();

    npcInteract = new FriendlyNPC;
    npcInteract->setHitbox({npcInteract->getNPCSprite().getPosition().x,
                            npcInteract->getNPCSprite().getPosition().y
                                      ,npcInteract->getNPCSprite().getGlobalBounds().width,
                            npcInteract->getNPCSprite().getGlobalBounds().height
                              });

    npcNotInteract = new FriendlyNPC;
    npcNotInteract->setHitbox({npcNotInteract->getNPCSprite().getPosition().x,
                               npcNotInteract->getNPCSprite().getPosition().y
                                   ,npcNotInteract->getNPCSprite().getGlobalBounds().width,
                               npcNotInteract->getNPCSprite().getGlobalBounds().height
                           });

    // Since the player and npcInteract are set to the same coordinates, they are interacting.
    // Since the player and npcNotInteract are not set to the same coordinates, they are not interacting.
    player->setHitbox({400,600,200,300});
    npcInteract->setHitbox({400,600,200,300});
    npcNotInteract->setHitbox({300,500,100,200});


    // Test for collision.
    bool playerAndNPCInteractionTrue = player->getGlobalHitbox().intersects(npcInteract->getGlobalHitbox());
    bool playerAndNPCInteractionFalse = player->getGlobalHitbox().intersects(npcNotInteract->getGlobalHitbox());


    if(playerAndNPCInteractionTrue && !playerAndNPCInteractionFalse){
        printf("Test Passed. Collision between the player and NPC works.");
    }else{
        printf("Test Failed");
    }

    delete player;
    delete npcInteract;
    delete npcNotInteract;
}

*/