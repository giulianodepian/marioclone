#ifndef _H_BLOCK
#define _H_BLOCK

#include "global.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "entity.h"
#include "collitionSystem.h"

#define BLOCK_BASE_WIDTH 50
#define BLOCK_BASE_HEIGHT 47

class Block : public Entity {
    public:
        Block(SDL_Renderer *renderer, float x, float y, int w, int h, std::vector<SDL_Texture*> entityTextures, int id, CollitionSystem* collisionSystem);
        ~Block();
        virtual void update()= 0;
        virtual void handleFromUpCollision(Entity* entity)= 0;
        virtual void handleFromSideCollision(Entity* entity, bool isRight)= 0;
        virtual void handleFromRightCollision(Entity* entity)= 0;
        virtual void handleFromLeftCollision(Entity* entity)= 0;
        virtual void handleFromDownCollision(Entity* entity)= 0;
        virtual void handleNoCollision() = 0;
    protected:
        CollitionSystem* collisionSystem;
};

#endif