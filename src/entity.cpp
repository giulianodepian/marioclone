#include "entity.h"

int Entity::getX(){
    return x;
}
int Entity::getY(){
    return y;
}
int Entity::getW(){
    return w;
}
int Entity::getH(){
    return h;
}
int Entity::getId() {
    return id;
}
int Entity::getCurrentAnim() {
    return currentAnim;
}
int Entity::getAnimSpeed() {
    return animSpeed;
}
bool Entity::doWeFlip() {
    return flip;
}
void Entity::setX(int x) {
    this->x = x;
}
void Entity::setY(int y){
    this->y = y;
}
void Entity::setW(int w){
    this->w = w;
}
void Entity::setH(int h){
    this->h = h;
}
void Entity::setCurrentAnim(int anim) {
    currentAnim = anim;
}
void Entity::setFlip(bool flip) {
    this->flip = flip;
}

void Entity::render() {
    SDL_RendererFlip renderFlip;
    if (flip) renderFlip = SDL_FLIP_HORIZONTAL;
    else renderFlip = SDL_FLIP_NONE;
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_RenderCopyEx(renderer, entityTextures[currentAnim], NULL, &rect, 0.0, NULL, renderFlip);
}