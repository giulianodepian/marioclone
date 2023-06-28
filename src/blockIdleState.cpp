#include "blockIdleState.h"
#include "blockBouncingState.h"

void BlockIdleState::update(InteractiveBlock* block) {
    //Stay Still
}

void BlockIdleState::onEntry(InteractiveBlock* block) {
    //nothing
}

BlockState* BlockIdleState::handleFromDownCollision(InteractiveBlock* block, Entity* dstEntity) {
    return new BlockBouncingState();
}

BlockState* BlockIdleState::handleFromUpCollision(InteractiveBlock* block, Entity* dstEntity) {
    return NULL;
}

BlockState* BlockIdleState::handleFromSideCollision(InteractiveBlock* block, Entity* dstEntity) {
    return NULL;
}

BlockState* BlockIdleState::handleNoCollision(InteractiveBlock* block) {
    return NULL;
}