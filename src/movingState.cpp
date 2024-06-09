#include "idleState.h"
#include "movingState.h"
#include "jumpState.h"
#include "duckState.h"
#include "fallingState.h"
#include "player.h"
#include "global.h"
#include <cstdio>

std::unique_ptr<PlayerState> MovingState::handleInput(Player* player) {
    if (!player->getActiveActions()[RIGHT] && !player->getActiveActions()[LEFT]) {
        return std::unique_ptr<PlayerState>(new IdleState());
    }
    if (player->getActiveActions()[RIGHT] && player->getActiveActions()[LEFT]) {
        return std::unique_ptr<PlayerState>(new IdleState());
    }
    if (player->getActiveActions()[JUMP]) {
        return std::unique_ptr<PlayerState>(new JumpState());
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

std::unique_ptr<PlayerState> MovingState::handleFromDownCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}

std::unique_ptr<PlayerState> MovingState::handleFromSideCollision(Player* player) {
    return std::unique_ptr<PlayerState>(new IdleState());
}

std::unique_ptr<PlayerState> MovingState::handleFromUpCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}

std::unique_ptr<PlayerState> MovingState::handleNoCollision(Player* player) {
    return std::unique_ptr<PlayerState>(new FallingState());
}
