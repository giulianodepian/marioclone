#ifndef _H_INTERACTIVEBLOCK
#define _H_INTERACTIVEBLOCK


#include "block.h"

class BlockState;

class InteractiveBlock : public Block {
    public:
        InteractiveBlock(SDL_Renderer *renderer, int x, int y, int w, int h, std::vector<SDL_Texture*> entityTextures, int id, CollitionSystem* collisionSystem);
        void bounce();
        virtual void update();
        virtual void handleFromUpCollision(Entity* entity);
        virtual void handleFromSideCollision(Entity* entity, bool isRight);
        virtual void handleFromRightCollision(Entity* entity);
        virtual void handleFromLeftCollision(Entity* entity);
        virtual void handleFromDownCollision(Entity* entity);
        virtual void handleNoCollision();
        void startBouncing();
        BlockState* blockState;
    private:
        int originalY;
        int maxY;
        int speedY;
};

#endif