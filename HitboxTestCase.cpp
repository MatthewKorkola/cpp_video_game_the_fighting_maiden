////Created by snear2 on 11/8/2022.
//
//#include "HitboxTestCase.h"
//#include "headers/Enemy.h"
//#include "headers/Player.h"
//
//
//int main(){
//    //create 3 different enemies, 2 of them will be colliding and 1 won't
//
//    Enemy *enemy1;
//    Enemy *enemy2;
//    Enemy *enemy3;
//
//    enemy1 = new Enemy(300.f,500.f);
//    enemy2 = new Enemy(300.f,500.f);
//    enemy3 = new Enemy(800.f,600.f);
//
//    enemy1->setHitbox({300,500,100,100});
//    enemy2->setHitbox({300,500,100,100});
//    enemy3->setHitbox({1000,1000,100,100});
//
//
//    bool collidingTrue = enemy1->getGlobalHitbox().intersects(enemy2->getGlobalHitbox());
//    bool collidingFalse = enemy1->getGlobalHitbox().intersects(enemy3->getGlobalHitbox());
//
//
//    if(collidingTrue && !collidingFalse){
//        printf("Test Passed");
//    }else{
//        printf("Test Failed");
//    }
//}
