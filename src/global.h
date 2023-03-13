#ifndef _H_GLOBAL
#define _H_GLOBAL

#include <cstdint>

extern const uint8_t* keyboardState;

extern int screenW;
extern int screenH;
extern float deltaTime;
extern float lastUpdateTime;
extern int framesPassed;
enum entityId {
    Air = 0,
    Ground,
    PlayerEntity = 98,
};

#endif