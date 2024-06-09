#ifndef _H_INTERACTIVEBLOCKSTATE
#define _H_INTERACTIVEBLOCKSTATE
#include "global.h"
#include <SDL2/SDL.h>
#include "interactiveBlock.h"
#include <memory>

class InteractiveBlock;

class BlockState {
    public:
        virtual ~BlockState() {};
        virtual void update(InteractiveBlock* block) = 0;
        virtual void onEntry(InteractiveBlock* block) = 0;
        virtual std::unique_ptr<BlockState> handleFromUpCollision(InteractiveBlock* block, Entity* dstEntity) = 0;
        virtual std::unique_ptr<BlockState> handleFromSideCollision(InteractiveBlock* block, Entity* dstEntity) = 0;
        virtual std::unique_ptr<BlockState> handleFromDownCollision(InteractiveBlock* block, Entity* dstEntity) = 0;
        virtual std::unique_ptr<BlockState> handleNoCollision(InteractiveBlock* block) = 0;
};

#endif