////
//// Created by Xavier HIll Roy on 2022-11-08.
////
//
//#include "ArmourTestCase.h"
//#include "Armour.h"
//#include "Player.h"
//
//int main(){
//    Armour *armour;
//    armour = new Armour();
//    // set armour protection to 10
//    armour->setProtectionValue(10);
//
//    Player * player;
//    player = new Player();
//    player->setHP(0); // set player hp to 0
//
//    // check no armour equipped
//    if (player->getArmourProtection() == 0){
//        std::cout<<"Armour Test 1 pass"<<std::endl;
//    }
//    else std::cout<<"Armour Test 1 Fail"<<std::endl;
//
//    // equipping armour
//    player->equipArmour(armour);
//    // player armour protection value = armour protection
//
//    if(player->getArmour().getProtectionValue() == player->getArmourProtection()){
//        std::cout<<"Armour Test 2 Pass: Armour Properly equipped"<<std::endl;
//    }else std::cout<<"Armour Test 2 FAILED: Not Properly equipped"<<std::endl;
//
//// check graphic change when armour equip
//    if (player->getPlayerSprite().getColor() == sf::Color::Green){
//        std::cout<<"Armour Test 3 Pass: Color change properly "<<std::endl;
//    }else  std::cout<<"Armour Test 3 Pass: Color not  change properly "<<std::endl;
//
//
//
//
//
//
//}
