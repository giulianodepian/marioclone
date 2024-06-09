#include "idleState.h"
#include "movingState.h"
#include "jumpState.h"
#include "duckState.h"
#include "fallingState.h"
#include "player.h"
#include "global.h"
#include <cstdio>

std::unique_ptr<PlayerState> FallingState::handleInput(Player* player) {
    return std::unique_ptr<PlayerState>();
}

void FallingState::update(Player* player) {
    player->verticalMovement(player->getGravity());
    if (player->getActiveActions()[RIGHT]) player->horizontalMovement(player->getXAcceleration());
    else if (player->getActiveActions()[LEFT]) player->horizontalMovement(player->getXAcceleration() * -1);
    else player->stopMovement();
}

void FallingState::onEntry(Player* player) {
    player->setCurrentYSpeed(player->getFallStarterSpeed());
}

std::unique_ptr<PlayerState> FallingState::handleFromDownCollision(Player* player) {
    return std::unique_ptr<PlayerState>(new IdleState);
}

std::unique_ptr<PlayerState> FallingState::handleFromUpCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}

std::unique_ptr<PlayerState> FallingState::handleFromSideCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}

std::unique_ptr<PlayerState> FallingState::handleNoCollision(Player* player) {
    return std::unique_ptr<PlayerState>();
}