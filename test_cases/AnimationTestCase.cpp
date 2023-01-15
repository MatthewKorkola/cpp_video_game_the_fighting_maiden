/*
//
// Created by Bryce Chevallier on 2022-11-28.
//


#include "headers/AnimationTestCase.h"

int main(){

    //Create player
    Player *player;
    player = Player::instance();

    int currentFrame;
    currentFrame = player->getCurrentFrame().left;

    std::cout<<"The current frame: "<<currentFrame<<std::endl;

    //Simulate animation timer
    usleep(100000);

    //Simulate updating the animation
    player->updateAnimation();

    int newFrame;
    newFrame = player->getCurrentFrame().left;

    std::cout<<"The new current frame: "<<player->getCurrentFrame().left<<std::endl;

    if (newFrame>currentFrame){
        std::cout<<"Animation Test Passed: The frame moved when animation updated"<<std::endl;
    }else std::cout<<"Animation Test Failed: The frame failed to move with animation"<<std::endl;

    //Test the attack animation

    //Call an attack animation
    player->attackAnimation();

    if (player->getPlayerSprite().getTextureRect().left==1262.f){
        std::cout<<"Attack Animation Test Passed: Proper attack animation displayed"<<std::endl;
    }else std::cout<<"Animation Test Failed: Attack animation not produced"<<std::endl;
}
*/

