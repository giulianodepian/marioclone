#ifndef _H_SOLIDBLOCK
#define _H_SOLIDBLOCK
#include "block.h"

class SolidBlock : public Block {
    public:
        SolidBlock(SDL_Renderer *renderer, float x, float y ,int w, int h, std::vector<SDL_Texture*> entityTextures, int id, CollitionSystem* collisionSystem);
        virtual void update();
        virtual void handleFromUpCollision(Entity* entity);
        virtual void handleFromSideCollision(Entity* entity, bool isRight);
        virtual void handleFromRightCollision(Entity* entity);
        virtual void handleFromLeftCollision(Entity* entity);
        virtual void handleFromDownCollision(Entity* entity);
        virtual void handleNoCollision();
};

#endif