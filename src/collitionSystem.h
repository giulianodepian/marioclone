#ifndef _H_COLLITIONSYSTEM
#define _H_COLLITIONSYSTEM

#include "entity.h"

class CollitionSystem {
    public:
        void detectCollition(Entity* entitySrc, Entity* entityDst);
        static CollitionSystem* instance();
    private:
        CollitionSystem();
};

#endif