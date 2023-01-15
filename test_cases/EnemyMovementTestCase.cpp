//
// Created by Bryce Chevallier on 2022-11-27.
//

/*

#include "EnemyMovementTestCase.h"

int main(){
    EnemyFactory *factory;
    Enemy *enemy;
    enemy = factory->makeEnemy(enemy);

    int newX, newY;
    int xOrigin = enemy->getEnemySprite().getPosition().x;
    int yOrigin = enemy->getEnemySprite().getPosition().y;

    std::cout<<"Enemy original X coordinate: "<<xOrigin<<std::endl;
    std::cout<<"Enemy original Y coordinate: "<<yOrigin<<std::endl;

    // move left test case by simulating player to the left of enemy
    enemy->move(-1.f,0.f); // player to the left moves enemy left
    newX = enemy->getEnemySprite().getPosition().x;
    if (xOrigin>newX){
        std::cout<<"Moved Left Pass"<<std::endl;
    }else std::cout<<"Moved Left Failed"<<std::endl;

    // set new x coordinate as origin (reseting test)
    xOrigin = enemy->getEnemySprite().getPosition().x;

    // move right test case by simulating enemy to the right of enemy
    enemy->move(301.f,0.f); // Player Moving right
    newX = enemy->getEnemySprite().getPosition().x;

    if (xOrigin<newX){
        std::cout<<"Moved Right Pass"<<std::endl;
    }else std::cout<<"Moved Right Failed"<<std::endl;

    xOrigin = enemy->getEnemySprite().getPosition().x;

    // move up test case by simulating player above the enemy

    enemy->move(0.f,-1.f); // move player up
    newY =  enemy->getEnemySprite().getPosition().y;

    if (yOrigin>newY){
        std::cout<<"Moved Up Pass"<<std::endl;
    }else std::cout<<"Moved Up Failed"<<std::endl;

    yOrigin = newY; // resetting y coordinate

    //move down test case by simulating player below the enemy
    enemy->move(0.f,51.f); // move player up
    newY =  enemy->getEnemySprite().getPosition().y;

    if (yOrigin<newY){
        std::cout<<"Moved down Pass"<<std::endl;
    }else std::cout<<"Moved down Failed"<<std::endl;
}
*/
