#include "blockIdleState.h"
#include "blockBouncingState.h"

void BlockIdleState::update(InteractiveBlock* block) {
    if (block->getId() == Block_Question) {
        //Change glowin animation
        if(framesPassed%block->getAnimSpeed() == 0) {
            if (block->getCurrentAnim() + 1 < 3) block->setCurrentAnim(block->getCurrentAnim() + 1);
            else block->setCurrentAnim(0);
        }
    }
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