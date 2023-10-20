#include "jumpState.h"
#include "idleState.h"
#include "movingState.h"
#include "jumpState.h"
#include "duckState.h"
#include "fallingState.h"
#include "player.h"
#include "global.h"
#include <cstdio>

PlayerState* JumpState::handleInput(Player* player) {
    return NULL;
}

void JumpState::update(Player* player) {
    player->verticalMovement(player->getGravity());
    if (keyboardState[SDL_SCANCODE_RIGHT]) {
        player->setFlip(false);
        player->horizontalMovement(player->getXAcceleration());
    }
    else if (keyboardState[SDL_SCANCODE_LEFT]) {
        player->setFlip(true);
        player->horizontalMovement(player->getXAcceleration() * -1);
    }
    else player->stopMovement();
}

void JumpState::onEntry(Player* player) {
    player->setCurrentAnim(4);
    player->setCurrentYSpeed(player->getMaxSpeedY() * -1);
}

PlayerState* JumpState::handleFromUpCollision(Player* player) {
    return NULL;
}

PlayerState* JumpState::handleFromSideCollision(Player* player) {
    return NULL;
}

PlayerState* JumpState::handleFromDownCollision(Player* player) {
    if (player->getCurrentXSpeed() != 0) return new MovingState();
    else return new IdleState(); 
}

PlayerState* JumpState::handleNoCollision(Player* player) {
    return NULL;
}