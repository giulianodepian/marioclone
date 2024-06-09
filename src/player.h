#ifndef _H_PLAYER
#define _H_PLAYER

#include "global.h"
#include "entity.h"
#include "collitionSystem.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "inputSystem.h"
#include <map>
#include <memory>
class PlayerState;
class InputSystem;

#define PLAYER_WIDTH 47
#define PLAYER_HEIGHT 50
#define PLAYER_ACCELERATION_BASE 5
#define PLAYER_BASE_GRAVITY 5
#define PLAYER_MAX_SPEED_BASE 200
#define PLAYER_MAX_SPEED_Y_BASE 300
#define PLAYER_BASE_FALL 100

enum PlayerActions {
    LEFT,
    RIGHT,
    DOWN,
    JUMP,
    RUN
};

class Player : public Entity {
    public:
        Player(SDL_Renderer *renderer, CollitionSystem* collisionSystem);
        ~Player();
        void handleInput();
        void update();
        float getXAcceleration();
        int getGravity();
        float getCurrentXSpeed();
        float getCurrentYSpeed();
        int getMaxSpeedY();
        int getFallStarterSpeed();
        void setCurrentYSpeed(int currentYSpeed);
        void stopMovement();
        void horizontalMovement(float acceleration);
        void verticalMovement(float acceleration);
        void onAirManager();
        void manageScreenEdgesCollition();
        void detectCollition(Entity* entity);
        std::map<uint8_t, bool> getActiveActions();
        virtual void handleFromUpCollision(Entity* entity);
        virtual void handleFromSideCollision(Entity* entity, bool isRight);
        virtual void handleFromRightCollision(Entity* entity);
        virtual void handleFromLeftCollision(Entity* entity);
        virtual void handleFromDownCollision(Entity* entity);
        virtual void handleNoCollision();
    private:
        float xAcceleration;
        float currentYSpeed;
        float currentXSpeed;
        int gravity;
        int maxSpeedX;
        int maxSpeedY;
        int isOnGround;
        int fallStarterSpeed;
        void loadMarioSprites(const char* spritePath);
        void loadMarioInputs();
        std::unique_ptr<PlayerState> playerState;
        CollitionSystem* collisionSystem;
        InputSystem inputSystem;
};

#endif