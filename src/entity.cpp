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
SDL_Texture* Entity::getGraphic(){
    return currentTexture;
}
void Entity::render() {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_RenderCopy(renderer, currentTexture, NULL, &rect);
}