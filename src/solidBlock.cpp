#include "solidBlock.h"

SolidBlock::SolidBlock(SDL_Renderer *renderer, int x, int y, int w, int h, std::vector<SDL_Texture*> entityTextures, int id, CollitionSystem* collisionSystem)
: Block(renderer, x, y, w, h, entityTextures, id, collisionSystem) {

}

void SolidBlock::handleFromDownCollision(Entity* entity) {

}

void SolidBlock::handleFromUpCollision(Entity* entity) {
    
}

void SolidBlock::handleFromLeftCollision(Entity* entity) {
    
}

void SolidBlock::handleFromRightCollision(Entity* entity) {
    
}

void SolidBlock::handleFromSideCollision(Entity* entity, bool isRight) {
    
}

void SolidBlock::handleNoCollision() {
    
}

void SolidBlock::update() {

}