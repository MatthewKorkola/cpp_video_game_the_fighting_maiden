//
// Created by Matthew Korkola on 2022-11-28.
//

/*

#include "headers/RunningStateTestCase.h"
#include "headers/Player.h"

// Test the running feature.
int main(){
    Player *player;
    player = Player::instance();

    // The setMovementSpeed function simulates the user pressing the run button.
    // The default walking speed is 5.0f. If the running speed can be doubled to
    // 10.f (which is the running speed), then the running feature works correctly.
    float walkingSpeed = player->getMovementSpeed();
    float runningSpeed = walkingSpeed * 2;

    player->setMovementSpeed(runningSpeed);

    float testRunningSpeed = 10.f;

    if (runningSpeed == testRunningSpeed) {
        std::cout << "Test passed. The running feature works correctly.";
    }
    else {
        std::cout << "Test failed. The running feature does not work correctly";
    }
    delete player;
}

 */