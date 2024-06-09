#ifndef _H_BLOCKIDLESTATE
#define _H_BLOCKIDLESTATE

#include "interactiveBlockState.h"

class BlockState;


class BlockIdleState : public BlockState {
        virtual void update(InteractiveBlock* block);
        virtual void onEntry(InteractiveBlock* block);
        virtual std::unique_ptr<BlockState> handleFromUpCollision(InteractiveBlock* block, Entity* dstEntity);
        virtual std::unique_ptr<BlockState> handleFromSideCollision(InteractiveBlock* block, Entity* dstEntity);
        virtual std::unique_ptr<BlockState> handleFromDownCollision(InteractiveBlock* block, Entity* dstEntity);
        virtual std::unique_ptr<BlockState> handleNoCollision(InteractiveBlock* block);
};

#endif