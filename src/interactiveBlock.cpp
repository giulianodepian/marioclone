#include "interactiveBlock.h"
#include "blockIdleState.h"
#include "blockBouncingState.h"
#include <cstdio>

InteractiveBlock::InteractiveBlock(SDL_Renderer *renderer, int x, int y, int w, int h, std::vector<SDL_Texture*> entityTextures, int id, CollitionSystem* collisionSystem)
: Block(renderer, x, y, w, h, entityTextures, id, collisionSystem) 
{
    originalY = y;
    maxY = y - (this->h / 2);
    speedY = -200;
    blockState = new BlockIdleState();
}

void InteractiveBlock::handleFromDownCollision(Entity* entity) {

}

void InteractiveBlock::startBouncing(){
    delete blockState;
    blockState = new BlockBouncingState(); 
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
        delete blockState;
        blockState = new BlockIdleState();
    }
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