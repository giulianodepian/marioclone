#include "block.h"
#include <cstdio>

Block::Block(SDL_Renderer *renderer, int x, int y ,int w, int h, std::vector<SDL_Texture*> entityTextures, int id, CollitionSystem* collisionSystem) {
    Block::x = x;
    Block::y = y;
    Block::w = w;
    Block::h = h;
    Block::id = id;
    Block::collisionSystem = collisionSystem;
    Block::renderer = renderer;
    Block::entityTextures = entityTextures;
    currentAnim = 0;
    animSpeed = 0;
}

Block::~Block(){

}

void Block::screenMovement(int playerCurrentSpeed) {
    x += playerCurrentSpeed - 1;
}

void Block::horizontalMovement(int speed) {
    //Not used
}

void Block::detectCollition(Entity* entity) {

}

void Block::handleFromUpCollision(Entity* entity) {
    
}

void Block::handleFromDownCollision(Entity* entity) {

}

void Block::handleFromSideCollision(Entity* entity, bool isRight) {
    
}

void Block::handleFromRightCollision(Entity* entity) {
    
}

void Block::handleFromLeftCollision(Entity* entity) {
    
}

void Block::handleNoCollision() {
    
}