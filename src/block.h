#ifndef _H_BLOCK
#define _H_BLOCK

#include "global.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "collitionSystem.h"

#define BLOCK_BASE_WIDTH 50
#define BLOCK_BASE_HEIGHT 47

class Block : public Entity {
    public:
        Block(SDL_Renderer *renderer, int x, int y, int w, int h, char* imageRoute, int id, CollitionSystem* collisionSystem);
        ~Block();
        void screenMovement(int playerCurrentSpeed);
        virtual void horizontalMovement(int speed);
        virtual void detectCollition(Entity* entity);
        virtual void handleFromUpCollision(Entity* entity);
        virtual void handleFromSideCollision(Entity* entity, bool isRight);
        virtual void handleFromRightCollision(Entity* entity);
        virtual void handleFromLeftCollision(Entity* entity);
        virtual void handleFromDownCollision(Entity* entity);
        virtual void handleNoCollision();
    private:
        CollitionSystem* collisionSystem;
};

#endif