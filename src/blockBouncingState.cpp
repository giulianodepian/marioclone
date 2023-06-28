#include "blockBouncingState.h"
#include <cstdio>

void BlockBouncingState::update(InteractiveBlock* block) {
    block->bounce();
}

BlockState* BlockBouncingState::handleFromDownCollision(InteractiveBlock* block, Entity* dstEntity) {
    return NULL;
}

BlockState* BlockBouncingState::handleFromUpCollision(InteractiveBlock* block, Entity* dstEntity) {
    return NULL;
}

BlockState* BlockBouncingState::handleFromSideCollision(InteractiveBlock* block, Entity* dstEntity) {
    return NULL;
}

BlockState* BlockBouncingState::handleNoCollision(InteractiveBlock* block) {
    return NULL;
}

void BlockBouncingState::onEntry(InteractiveBlock* block) {
    //nothing
}