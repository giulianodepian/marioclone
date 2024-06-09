#ifndef _H_INTERACTIVEBLOCK
#define _H_INTERACTIVEBLOCK


#include "block.h"
#include <memory>

class BlockState;

class InteractiveBlock : public Block {
    public:
        InteractiveBlock(SDL_Renderer *renderer, float x, float y, int w, int h, std::vector<SDL_Texture*> entityTextures, int id, CollitionSystem* collisionSystem, uint8_t cantItems);
        void bounce();
        uint8_t getCantItems();
        void setCantItems(uint8_t cant);
        virtual void update();
        virtual void handleFromUpCollision(Entity* entity);
        virtual void handleFromSideCollision(Entity* entity, bool isRight);
        virtual void handleFromRightCollision(Entity* entity);
        virtual void handleFromLeftCollision(Entity* entity);
        virtual void handleFromDownCollision(Entity* entity);
        virtual void handleNoCollision();
        std::unique_ptr<BlockState> blockState;
    private:
        int originalY;
        int maxY;
        int speedY;
        uint8_t cantItems;
};

#endif