#include "blockBouncingState.h"
#include <cstdio>

void BlockBouncingState::update(InteractiveBlock* block) {
    block->bounce();
    if (block->getId() == Block_Question) {
        //Change glowin animation
        if(framesPassed%block->getAnimSpeed() == 0) {
            if (block->getCurrentAnim() + 1 < 3) block->setCurrentAnim(block->getCurrentAnim() + 1);
            else block->setCurrentAnim(0);
        }
    }
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