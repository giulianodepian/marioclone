#ifndef _H_GLOBAL
#define _H_GLOBAL

#include <cstdint>

extern const uint8_t* keyboardState;

extern int screenW;
extern int screenH;
extern float deltaTime;
extern float lastUpdateTime;

enum entityId {
    Air = 0,
    Ground,
};

#endif