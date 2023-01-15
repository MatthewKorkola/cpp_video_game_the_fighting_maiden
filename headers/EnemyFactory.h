/**
 * @brief Factory design pattern for creation of enemies
 *
 * Calls make enemy to create enemy with facotry withod
 * @author Bryce Chevallier
 */
#ifndef THEFIGHTINGMAIDEN_ENEMYFACTORY_H
#define THEFIGHTINGMAIDEN_ENEMYFACTORY_H

#include "Enemy.h"


class EnemyFactory {
public:
    /**
     * @brief creates an enemy
     *
     * Intialises enemy
     * sets hit box
     * sets sprite
     *
     * @param enemy Takes in an shell of an enemy
     * @return an Enemy
     */
    Enemy* makeEnemy(Enemy *enemy);
};


#endif //THEFIGHTINGMAIDEN_ENEMYFACTORY_H
