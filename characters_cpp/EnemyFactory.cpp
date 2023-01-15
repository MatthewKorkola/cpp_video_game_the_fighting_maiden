//
// Created by Bryce Chevallier on 2022-11-22.
//

#include "EnemyFactory.h"

Enemy* EnemyFactory::makeEnemy(Enemy *enemy) {
    // Initialises enemy hit box
    enemy = new Enemy(300.f,50.f);
    // Enemy sprite
    // Location, width, height
    sf::Sprite enemySprite = enemy->getEnemySprite();
    float enemySpriteWidth = (float)enemy->getEnemySprite().getGlobalBounds().width;
    float enemySpriteHeight = (float)enemy->getEnemySprite().getGlobalBounds().height;
    float enemyLeft = (float)enemy->getEnemySprite().getPosition().x;
    float enemyTop = (float)enemy->getEnemySprite().getPosition().y;
    // Sets the hitbox of enemy
    enemy->setHitbox({enemyLeft, enemyTop, enemySpriteWidth, enemySpriteHeight});

    return enemy;
}