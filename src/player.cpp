#include "player.h"
#include "idleState.h"
#include "fallingState.h"
#include <cstdio>

Player::Player(SDL_Renderer *renderer, CollitionSystem* collisionSystem) {
    h = PLAYER_HEIGHT + (screenH - 611);
    w = PLAYER_WIDTH + (screenW - 800);
    x = 0;
    y = screenH / 2;
    id = 98;
    isOnGround = false;
    currentXSpeed = 0;
    currentYSpeed = 0;
    xAcceleration = PLAYER_ACCELERATION_BASE;
    gravity = PLAYER_BASE_GRAVITY;
    maxSpeedX = PLAYER_MAX_SPEED_BASE;
    maxSpeedY = PLAYER_MAX_SPEED_Y_BASE;
    playerState = new IdleState();
    this->renderer = renderer;
    this->collisionSystem = collisionSystem;
    SDL_Surface *playerSurface = IMG_Load("./media/mario.png");
    entityTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
    if (!entityTexture) printf("ERROR TEXTURE NOT LOADED");
    SDL_FreeSurface(playerSurface);
}

Player::~Player(){
    SDL_DestroyTexture(entityTexture);
}

int Player::getXAcceleration() {
    return xAcceleration;
}

int Player::getCurrentXSpeed() {
    return currentXSpeed;
}

PlayerState* Player::getMoveState() {
    return playerState;
}

int Player::getMaxSpeedY() {
    return maxSpeedY;
}

void Player::setCurrentYSpeed(int currentYSpeed) {
    this->currentYSpeed = currentYSpeed;
}

void Player::stopMovement() {
    if (currentXSpeed < 0) currentXSpeed += xAcceleration;
    else if (currentXSpeed > 0) currentXSpeed -= xAcceleration;
    x += currentXSpeed * (deltaTime * 0.001);
}

void Player::horizontalMovement(int acceleration) {
    currentXSpeed += acceleration;
    if (currentXSpeed > maxSpeedX) currentXSpeed = maxSpeedX;
    else if (currentXSpeed < -maxSpeedX) currentXSpeed = -maxSpeedX;
    //(deltaTime * 0.001) Converts deltaTime miliseconds to seconds
    //Adds or substract 1 since that the min speed
    if (acceleration > 0) x += currentXSpeed * (deltaTime * 0.001) + 1;
    else x += currentXSpeed * (deltaTime * 0.001) - 1;
}

void Player::verticalMovement(int acceleration) {
    currentYSpeed += acceleration;
    if (currentYSpeed > maxSpeedY) currentYSpeed = maxSpeedY;
    y += currentYSpeed * (deltaTime * 0.001);
}

void Player::handleInput() {
    //newState != NULL if we have to change to a new state (change to state returned by handleInput)
    PlayerState *newState = playerState->handleInput(this);
    if (newState != NULL) {
        delete playerState;
        playerState = newState;
        //onEntry mostly controls graphics transitions
        playerState->onEntry(this);
    }
}

void Player::update() {
    playerState->update(this);
}

int Player::getGravity() {
    return gravity;
}

void Player::detectCollition(Entity* entity) {
    collisionSystem->detectCollition(this, entity);
}

void Player::handleFromUpCollision(Entity* entity) {
    PlayerState *newState;
    switch (entity->getId())
    {
    case Ground:
        isOnGround = true;
        y = (entity->getY() - 1) - h;
        newState = playerState->handleFromUpCollision(this);
        if (newState != NULL) {
            delete playerState;
            playerState = newState;
            playerState->onEntry(this);
        }
        break;
    
    default:
        break;
    }
}

void Player::handleFromDownCollision(Entity* entity) {

}

void Player::handleNoCollision() {

}

void Player::handleFromSideCollision(Entity* entity) {
    PlayerState* newState;
    switch (entity->getId()) {
        case Ground:
            if (currentXSpeed > 0) x = entity->getX() - 1 - w;
            else x = entity->getX() + entity->getW();
            currentXSpeed = 0;
            newState = playerState->handleFromSideCollision(this);
            if (newState != NULL) {
                delete playerState;
                playerState = newState;
                playerState->onEntry(this);
            }
        break;
        
        default:
            break;
    }
}

void Player::onAirManager() {
    if (!isOnGround) {
        PlayerState* newState = playerState->handleNoCollision(this);
        if (newState != NULL) {
            delete playerState;
            playerState = newState;
            playerState->onEntry(this);
        }
    } else {
        isOnGround = false;
    }
}