#ifndef _H_INTERACTIVEBLOCKSTATE
#define _H_INTERACTIVEBLOCKSTATE
#include "global.h"
#include <SDL2/SDL.h>
#include "interactiveBlock.h"

class InteractiveBlock;

class BlockState {
    public:
        virtual ~BlockState() {};
        virtual void update(InteractiveBlock* block) = 0;
        virtual void onEntry(InteractiveBlock* block) = 0;
        virtual BlockState* handleFromUpCollision(InteractiveBlock* block, Entity* dstEntity) = 0;
        virtual BlockState* handleFromSideCollision(InteractiveBlock* block, Entity* dstEntity) = 0;
        virtual BlockState* handleFromDownCollision(InteractiveBlock* block, Entity* dstEntity) = 0;
        virtual BlockState* handleNoCollision(InteractiveBlock* block) = 0;
};

#endif