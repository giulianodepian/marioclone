#include "idleState.h"
#include "movingState.h"
#include "jumpState.h"
#include "duckState.h"
#include "fallingState.h"
#include "player.h"
#include "global.h"
#include <cstdio>

PlayerState* MovingState::handleInput(Player* player) {
    if (!player->getActiveActions()[RIGHT] && !player->getActiveActions()[LEFT]) {
        return new IdleState();
    }
    if (player->getActiveActions()[RIGHT] && player->getActiveActions()[LEFT]) {
        return new IdleState();
    }
    if (player->getActiveActions()[JUMP]) {
        return new JumpState();
    }

    return NULL;
}

void MovingState::update(Player* player) {
    //Set Moving Graphic
    if (player->getActiveActions()[RIGHT]) {
        if (framesPassed%player->getAnimSpeed() == 0) {
            if (player->getCurrentAnim() == 3) {
                player->setCurrentAnim(1);
            } else {
                player->setCurrentAnim(player->getCurrentAnim() + 1);
            } 
        }
        player->setFlip(false);
        player->horizontalMovement(player->getXAcceleration());
    }
    else if (player->getActiveActions()[LEFT]) {
        if (framesPassed%player->getAnimSpeed() == 0) {
            if (player->getCurrentAnim() == 3) {
                player->setCurrentAnim(1);
            } else {
                player->setCurrentAnim(player->getCurrentAnim() + 1);
            } 
        }
        player->setFlip(true);
        player->horizontalMovement(player->getXAcceleration() * -1);
    }
}

void MovingState::onEntry(Player* player) {
    player->setCurrentAnim(3);
    //player->setCurrentYSpeed(0);
}

PlayerState* MovingState::handleFromDownCollision(Player* player) {
    return NULL;
}

PlayerState* MovingState::handleFromSideCollision(Player* player) {
    return new IdleState();
}

PlayerState* MovingState::handleFromUpCollision(Player* player) {
    return NULL;
}

PlayerState* MovingState::handleNoCollision(Player* player) {
    return new FallingState();
}
