#ifndef _H_ENTITY
#define _H_ENTITY

#include "global.h"
#include <SDL2/SDL.h>
#include <vector>

class Entity {
    public:
        virtual ~Entity() {};
        int getX();
        int getY();
        int getW();
        int getH();
        int getId();
        int getCurrentAnim();
        int getAnimSpeed();
        uint8_t getTexturesLenght();
        bool doWeFlip();
        void setFlip(bool flip);
        void setX(float x);
        void setY(float y);
        void setW(int w);
        void setH(int h);
        void setId(uint8_t id);
        void setCurrentAnim(int anim);
        void render();
        void screenMovement(float playerCurrentSpeed);
        // add with what it collides since how to react depends on the state
        virtual void handleFromUpCollision(Entity* entity) = 0;
        virtual void handleFromSideCollision(Entity* entity, bool isRight) = 0;
        virtual void handleFromRightCollision(Entity* entity) = 0;
        virtual void handleFromLeftCollision(Entity* entity) = 0;
        virtual void handleFromDownCollision(Entity* entity) = 0;
        virtual void handleNoCollision() = 0;
    protected:
        int id;
        float x;
        float y;
        int w;
        int h;
        int currentAnim;
        int animSpeed; //frames per animation
        bool flip;
        std::vector<SDL_Texture*> entityTextures;
        SDL_Renderer *renderer;
};

#endif