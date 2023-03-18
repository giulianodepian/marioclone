#include "blockIdleState.h"
#include "blockBouncingState.h"

void BlockIdleState::update(InteractiveBlock* block) {
    //Stay Still
}

void BlockIdleState::onEntry(InteractiveBlock* block) {
    //nothing
}

BlockState* BlockIdleState::handleFromDownCollision(InteractiveBlock* block) {
    return new BlockBouncingState();
}

BlockState* BlockIdleState::handleFromUpCollision(InteractiveBlock* block) {
    return NULL;
}

BlockState* BlockIdleState::handleFromSideCollision(InteractiveBlock* block) {
    return NULL;
}

BlockState* BlockIdleState::handleNoCollision(InteractiveBlock* block) {
    return NULL;
}