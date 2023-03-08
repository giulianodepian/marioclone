#include "idleState.h"
#include "movingState.h"
#include "jumpState.h"
#include "duckState.h"
#include "fallingState.h"
#include "player.h"
#include "global.h"
#include <cstdio>

PlayerState* FallingState::handleInput(Player* player) {
    //Not Used
    return NULL;
}

void FallingState::update(Player* player) {
    player->verticalMovement(player->getGravity());
    if (keyboardState[SDL_SCANCODE_RIGHT]) player->horizontalMovement(player->getXAcceleration());
    else if (keyboardState[SDL_SCANCODE_LEFT]) player->horizontalMovement(player->getXAcceleration() * -1);
    else player->stopMovement();
}

void FallingState::onEntry(Player* player) {
    player->setCurrentYSpeed(player->getFallStarterSpeed());
}

PlayerState* FallingState::handleFromUpCollision(Player* player) {
    return new IdleState();
}

PlayerState* FallingState::handleFromDownCollision(Player* player) {

}

PlayerState* FallingState::handleFromSideCollision(Player* player) {
    return NULL;
}

PlayerState* FallingState::handleNoCollision(Player* player) {
    return NULL;
}