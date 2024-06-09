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

std::unique_ptr<BlockState> BlockBouncingState::handleFromDownCollision(InteractiveBlock* block, Entity* dstEntity) {
    return NULL;
}

std::unique_ptr<BlockState> BlockBouncingState::handleFromUpCollision(InteractiveBlock* block, Entity* dstEntity) {
    return NULL;
}

std::unique_ptr<BlockState> BlockBouncingState::handleFromSideCollision(InteractiveBlock* block, Entity* dstEntity) {
    return NULL;
}

std::unique_ptr<BlockState> BlockBouncingState::handleNoCollision(InteractiveBlock* block) {
    return NULL;
}

void BlockBouncingState::onEntry(InteractiveBlock* block) {
    if (block->getId() == Block_Empty) {
        block->setCurrentAnim(block->getTexturesLenght() - 1);
    }
}