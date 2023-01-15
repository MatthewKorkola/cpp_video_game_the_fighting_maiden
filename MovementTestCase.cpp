////
//// Created by Xavier HIll Roy on 2022-11-08.
////
//
//
//#include "headers/Player.h"
//
//int main(){
//    Player *player;
//    player = new Player();
//    int newX, newY;
//    int xOrigin = player->getPlayerSprite().getPosition().x;
//    int yOrigin = player->getPlayerSprite().getPosition().y;
//
//    std::cout<<"Player original X coordinate: "<<xOrigin<<std::endl;
//    std::cout<<"Player original Y coordinate: "<<yOrigin<<std::endl;
//
//    // move left test case simulates presssing A on keyboard
//    player->move(-1.f,0.f); // moving player left
//    newX = player->getPlayerSprite().getPosition().x;
//    if (xOrigin>newX){
//        std::cout<<"Moved Left Pass"<<std::endl;
//    }else std::cout<<"Moved Left Failed"<<std::endl;
//
//    // set new x coordinate as origin (reseting test)
//    xOrigin = player->getPlayerSprite().getPosition().x;
//
//    // PLAYER MOVING RIGHT
//    player->move(1.f,0.f); // Player Moving right
//    newX = player->getPlayerSprite().getPosition().x;
//
//    if (xOrigin<newX){
//        std::cout<<"Moved Right Pass"<<std::endl;
//    }else std::cout<<"Moved Right Failed"<<std::endl;
//
//    xOrigin = player->getPlayerSprite().getPosition().x;
//
//    // moving up
//
//    player->move(0.f,-1.f); // move player up
//    newY =  player->getPlayerSprite().getPosition().y;
//
//    if (yOrigin>newY){
//        std::cout<<"Moved Up Pass"<<std::endl;
//    }else std::cout<<"Moved Up Failed"<<std::endl;
//
//    yOrigin = newY; // resetting y coordinate
//
//    //test down movement
//    player->move(0.f,1.f); // move player up
//    newY =  player->getPlayerSprite().getPosition().y;
//
//    if (yOrigin<newY){
//        std::cout<<"Moved down Pass"<<std::endl;
//    }else std::cout<<"Moved down Failed"<<std::endl;
//}