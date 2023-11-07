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
    switch (dstEntity->getId())
    {
    case PlayerEntity:
        //TODO: Change since Blocks with differents items will have different Ids
        if (block->getId() == Block_Question && block->getCantItems() <= 1 || 
            block->getId() == Block_Brick && block->getCantItems() == 1) {
            block->setId(Block_Empty);
            if (block->getCantItems() == 1) {
                //Give Item
            }
            return new BlockBouncingState();
        }
        if (block->getId() != Block_Empty) return new BlockBouncingState();
        break;
    
    default:
        break;
    }
    return NULL;
    
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