#include "block.h"
#include <cstdio>

Block::Block(SDL_Renderer *renderer, int x, int y ,int w, int h, std::vector<SDL_Texture*> entityTextures, int id, CollitionSystem* collisionSystem) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->id = id;
    this->collisionSystem = collisionSystem;
    this->renderer = renderer;
    this->entityTextures = entityTextures;
    flip = false;
    currentAnim = 0;
    animSpeed = 0;
}

Block::~Block(){

}