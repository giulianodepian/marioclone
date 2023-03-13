#include "idleState.h"
#include "movingState.h"
#include "jumpState.h"
#include "duckState.h"
#include "fallingState.h"
#include "player.h"
#include "global.h"
#include <cstdio>

PlayerState* IdleState::handleInput(Player* player) {
    if (keyboardState[SDL_SCANCODE_RIGHT] && !keyboardState[SDL_SCANCODE_LEFT]) {
        return new MovingState();
    }
    if (keyboardState[SDL_SCANCODE_LEFT] && !keyboardState[SDL_SCANCODE_RIGHT]) {
        return new MovingState();
    }
    if (keyboardState[SDL_SCANCODE_Z]) {
        return new JumpState();
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

PlayerState* IdleState::handleFromDownCollision(Player* player) {
    return NULL;
}

PlayerState* IdleState::handleFromSideCollision(Player* player) {
    return NULL;
}

PlayerState* IdleState::handleFromUpCollision(Player* player) {
    return NULL;
}

PlayerState* IdleState::handleNoCollision(Player* player) {
    return new FallingState();
}