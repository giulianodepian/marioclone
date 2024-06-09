#include "jumpState.h"
#include "idleState.h"
#include "movingState.h"
#include "jumpState.h"
#include "duckState.h"
#include "fallingState.h"
#include "player.h"
#include "global.h"
#include <cstddef>
#include <cstdio>

std::unique_ptr<PlayerState> JumpState::handleInput(Player* player) {
    return std::unique_ptr<PlayerState>();
}

void JumpState::update(Player* player) {
    player->verticalMovement(player->getGravity());
    if (player->getActiveActions()[RIGHT]) {
        player->setFlip(false);
        player->horizontalMovement(player->getXAcceleration());
    }
    else if (player->getActiveActions()[LEFT]) {
        player->setFlip(true);
        player->horizontalMovement(player->getXAcceleration() * -1);
    }
    else player->stopMovement();
}

void JumpState::onEntry(Player* player) {
    player->setCurrentAnim(4);
    player->setCurrentYSpeed(player->getMaxSpeedY() * -1);
}

std::unique_ptr<PlayerState> JumpState::handleFromUpCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}

std::unique_ptr<PlayerState> JumpState::handleFromSideCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}

std::unique_ptr<PlayerState> JumpState::handleFromDownCollision(Player* player) {
    if (player->getCurrentXSpeed() != 0) return std::unique_ptr<MovingState>(new MovingState());
    else return std::unique_ptr<IdleState>(new IdleState()); 
}

std::unique_ptr<PlayerState> JumpState::handleNoCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}