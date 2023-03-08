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
    //setGraphics
    player->stopMovement();
}

void IdleState::onEntry(Player* player) {
    //setGraphics
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