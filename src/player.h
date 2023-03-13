#ifndef _H_PLAYER
#define _H_PLAYER

#include "global.h"
#include "entity.h"
#include "collitionSystem.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class PlayerState;

#define PLAYER_WIDTH 47
#define PLAYER_HEIGHT 50
#define PLAYER_ACCELERATION_BASE 5
#define PLAYER_BASE_GRAVITY 5
#define PLAYER_MAX_SPEED_BASE 200
#define PLAYER_MAX_SPEED_Y_BASE 300
#define PLAYER_BASE_FALL 100

class Player : public Entity {
    public:
        Player(SDL_Renderer *renderer, CollitionSystem* collisionSystem);
        ~Player();
        void handleInput();
        void update();
        int getXAcceleration();
        int getGravity();
        int getCurrentXSpeed();
        int getMaxSpeedY();
        int getFallStarterSpeed();
        void setCurrentYSpeed(int currentYSpeed);
        PlayerState* getMoveState();
        void stopMovement();
        virtual void horizontalMovement(int acceleration);
        void verticalMovement(int acceleration);
        void onAirManager();
        void manageScreenEdgesCollition();
        virtual void detectCollition(Entity* entity);
        virtual void handleFromUpCollision(Entity* entity);
        virtual void handleFromSideCollision(Entity* entity, bool isRight);
        virtual void handleFromRightCollision(Entity* entity);
        virtual void handleFromLeftCollision(Entity* entity);
        virtual void handleFromDownCollision(Entity* entity);
        virtual void handleNoCollision();
    private:
        int xAcceleration;
        int currentYSpeed;
        int currentXSpeed;
        int gravity;
        int maxSpeedX;
        int maxSpeedY;
        int isOnGround;
        int fallStarterSpeed;
        void loadMarioSprites(SDL_Surface* surface);
        PlayerState* playerState;
        CollitionSystem* collisionSystem;
};

#endif