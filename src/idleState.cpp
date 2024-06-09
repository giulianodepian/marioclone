#include "idleState.h"
#include "movingState.h"
#include "jumpState.h"
#include "duckState.h"
#include "fallingState.h"
#include "player.h"
#include "global.h"
#include <cstdio>

std::unique_ptr<PlayerState> IdleState::handleInput(Player* player) {
    if (player->getActiveActions()[JUMP]) {
        return std::unique_ptr<PlayerState>(new JumpState());
    }
    if (player->getActiveActions()[RIGHT] && !player->getActiveActions()[LEFT]) {
        return std::unique_ptr<PlayerState>(new MovingState());
    }
    if (player->getActiveActions()[LEFT] && !player->getActiveActions()[RIGHT]) {
        return std::unique_ptr<PlayerState>(new MovingState());
    }

    return NULL;
}

void IdleState::update(Player* player) {
    if (player->getCurrentXSpeed() != 0) {
        if (framesPassed%player->getAnimSpeed() == 0) {
            if (player->getCurrentAnim() == 3) {
                player->setCurrentAnim(1);
            } else {
                player->setCurrentAnim(player->getCurrentAnim() + 1);
            }
        } 
        if (player->getCurrentXSpeed() > 0) player->setFlip(false);
        else if (player->getCurrentXSpeed() < 0) player->setFlip(true);
    } else {
        player->setCurrentAnim(0);
    }
    player->stopMovement();
}

void IdleState::onEntry(Player* player) {
    player->setCurrentAnim(0);
    player->setCurrentYSpeed(0);
}

std::unique_ptr<PlayerState> IdleState::handleFromDownCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}

std::unique_ptr<PlayerState> IdleState::handleFromSideCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}

std::unique_ptr<PlayerState> IdleState::handleFromUpCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}

std::unique_ptr<PlayerState> IdleState::handleNoCollision(Player* player) {
    return std::unique_ptr<PlayerState>(new FallingState());
}