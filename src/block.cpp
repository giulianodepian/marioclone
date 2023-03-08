#include "block.h"
#include <cstdio>

Block::Block(SDL_Renderer *renderer, int x, int y ,int w, int h, char* imageRoute, int id, CollitionSystem* collisionSystem) {
    Block::x = x;
    Block::y = y;
    Block::w = w;
    Block::h = h;
    Block::id = id;
    Block::collisionSystem = collisionSystem;
    Block::renderer = renderer;
    SDL_Surface* blockSurface = IMG_Load(imageRoute);
    entityTexture = SDL_CreateTextureFromSurface(renderer, blockSurface);
    if (!entityTexture) printf("ERROR TEXTURE NOT LOADED");
    SDL_FreeSurface(blockSurface);
}

Block::~Block(){
    SDL_DestroyTexture(entityTexture);
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