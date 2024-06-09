#include "interactiveBlock.h"
#include "blockIdleState.h"
#include <cstdio>

InteractiveBlock::InteractiveBlock(SDL_Renderer *renderer, float x, float y, int w, int h, std::vector<SDL_Texture*> entityTextures, int id, CollitionSystem* collisionSystem,  uint8_t cantItems)
: Block(renderer, x, y, w, h, entityTextures, id, collisionSystem) 
{
    originalY = y;
    maxY = y - (this->h / 2);
    speedY = -200;
    blockState = std::unique_ptr<BlockState>(new BlockIdleState());
    animSpeed = 20;
    this->cantItems = cantItems;
}

void InteractiveBlock::handleFromDownCollision(Entity* entity) {
    std::unique_ptr<BlockState> newState;
    newState = blockState->handleFromDownCollision(this, entity);
    if (newState != NULL) {
        blockState = std::move(newState);
        blockState->onEntry(this);
    }
}

void InteractiveBlock::update() {
    blockState->update(this);
}

void InteractiveBlock::bounce() {
    y += speedY * (deltaTime * 0.001);
    if (speedY < 0 && y <= maxY) {
        y = maxY;
        speedY = 200;
    } else if (speedY > 0 && y >= originalY) {
        y = originalY;
        speedY = -200;
        blockState = std::unique_ptr<BlockState>(new BlockIdleState());
    }
}

uint8_t InteractiveBlock::getCantItems() {
    return cantItems;
}

void InteractiveBlock::setCantItems(uint8_t cant) {
    cantItems = cant;
}

void InteractiveBlock::handleFromUpCollision(Entity* entity) {

}

void InteractiveBlock::handleFromLeftCollision(Entity* entity) {
    
}

void InteractiveBlock::handleFromRightCollision(Entity* entity) {
    
}

void InteractiveBlock::handleFromSideCollision(Entity* entity, bool isRight) {

}

void InteractiveBlock::handleNoCollision() {
    
}