//Created by snear2 on 11/8/2022.

#include "headers/Enemy.h"
#include "headers/Player.h"


int main(){
    //create 3 different enemies, 2 of them will be colliding and 1 won't

    Enemy *enemy1;
    Player *player1;

    enemy1 = new Enemy(300.f,500.f);
    player1 = new Player();

    enemy1->setHitbox({300,500,100,100});
    player1->setHitbox({300,500,100,100});

    int OGhealth = 10;
    player1->setHP(OGhealth);

    bool collidingTrue = enemy1->getGlobalHitbox().intersects(player1->getGlobalHitbox());


    if(collidingTrue){
        player1->setHP(player1->getHP()-1);
    }

    if(player1->getHP()<OGhealth){
        printf("Test Passed");
    }
}


