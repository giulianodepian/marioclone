#include "idleState.h"
#include "movingState.h"
#include "jumpState.h"
#include "duckState.h"
#include "fallingState.h"
#include "player.h"
#include "global.h"
#include <cstdio>

PlayerState* MovingState::handleInput(Player* player) {
    if (!keyboardState[SDL_SCANCODE_RIGHT] && !keyboardState[SDL_SCANCODE_LEFT]) {
        return new IdleState();
    }
    if (keyboardState[SDL_SCANCODE_RIGHT] && keyboardState[SDL_SCANCODE_LEFT]) {
        return new IdleState();
    }
    if (keyboardState[SDL_SCANCODE_Z]) {
        return new JumpState();
    }

    return NULL;
}

void MovingState::update(Player* player) {
    //Set Moving Graphic
    if (keyboardState[SDL_SCANCODE_RIGHT]) {
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
    else if (keyboardState[SDL_SCANCODE_LEFT]) {
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
    player->setCurrentYSpeed(0);
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
