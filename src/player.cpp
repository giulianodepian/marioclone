#include "player.h"
#include "idleState.h"
#include "fallingState.h"
#include <cstdio>

Player::Player(SDL_Renderer *renderer, CollitionSystem* collisionSystem) {
    h = PLAYER_HEIGHT + (screenH - 611);
    w = PLAYER_WIDTH + (screenW - 800);
    x = 0;
    y = screenH / 2;
    fallStarterSpeed = PLAYER_BASE_FALL + (screenH - 611);
    id = PlayerEntity;
    isOnGround = false;
    currentXSpeed = 0;
    currentYSpeed = 0;
    flip = false;
    xAcceleration = PLAYER_ACCELERATION_BASE;
    gravity = PLAYER_BASE_GRAVITY;
    maxSpeedX = PLAYER_MAX_SPEED_BASE;
    maxSpeedY = PLAYER_MAX_SPEED_Y_BASE;
    playerState = new IdleState();
    this->renderer = renderer;
    this->collisionSystem = collisionSystem;
    loadMarioSprites("./media/marioIdle.png");
    loadMarioSprites("./media/marioRun1.png");
    loadMarioSprites("./media/marioRun2.png");
    loadMarioSprites("./media/marioRun3.png");
    loadMarioSprites("./media/marioJump.png");
    currentAnim = 0;
    animSpeed = 5;
}

void Player::loadMarioSprites(const char* spritePath) {
    SDL_Texture* tempTexture;
    SDL_Surface *tempSurface;
    tempSurface = IMG_Load(spritePath);
    tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    entityTextures.push_back(tempTexture);
    SDL_FreeSurface(tempSurface);
}

Player::~Player(){
    //Destroy Textures
}

int Player::getXAcceleration() {
    return xAcceleration;
}

int Player::getCurrentXSpeed() {
    return currentXSpeed;
}

int Player::getCurrentYSpeed() {
    return currentYSpeed;
}

PlayerState* Player::getMoveState() {
    return playerState;
}

int Player::getMaxSpeedY() {
    return maxSpeedY;
}

int Player::getFallStarterSpeed() {
    return fallStarterSpeed;
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

void Player::manageScreenEdgesCollition() {
    //Detect if collided with left side of screen
    if (x < 0) { 
        x = 0;
        currentXSpeed = 0;
    }
    //Detect if collided with right side of screen
    else if (x + w > screenW) {
        x = screenW - w;
        currentXSpeed = 0;
    }
}

void Player::handleFromUpCollision(Entity* entity) {
    PlayerState *newState;
    switch (entity->getId())
    {
    case Block_Brick:
    case Block_Ground:
        if (currentYSpeed >= 0) {
            isOnGround = true;
            y = (entity->getY() - 1) - h;
            currentYSpeed = 0;
            newState = playerState->handleFromUpCollision(this);
            if (newState != NULL) {
                delete playerState;
                playerState = newState;
                playerState->onEntry(this);
            }
        }
        break;
    
    default:
        break;
    }
}

void Player::handleFromDownCollision(Entity* entity) {
    PlayerState* newState;
    switch (entity->getId()) {
        case Block_Ground:
            if (currentYSpeed < 0) {
                y = entity->getY() + entity->getH();
                currentYSpeed = 0;
            }
            break;
        case Block_Brick:
            if (currentYSpeed < 0) {
                y = entity->getY() + entity->getH();
                currentYSpeed = 0;
                entity->handleFromDownCollision(this);
            }
        
        default:
            break;
    }

}

void Player::handleNoCollision() {

}

void Player::handleFromRightCollision(Entity* entity) {
    handleFromSideCollision(entity, true);
}

void Player::handleFromLeftCollision(Entity* entity) {
    handleFromSideCollision(entity, false);
}

void Player::handleFromSideCollision(Entity* entity, bool isRight) {
    PlayerState* newState;
    switch (entity->getId()) {
        case Block_Brick:
        case Block_Ground:
            if (isRight) x = entity->getX() - 1 - w;
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