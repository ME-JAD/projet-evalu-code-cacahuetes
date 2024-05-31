#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sprite.h"

#ifndef CODE_CACAHUETES_SHREK_H
#define CODE_CACAHUETES_SHREK_H

#define SPRITE_WIDTH 5
#define SPRITE_HEIGHT 5
#define SPRITE_COUNT 3

typedef struct Shrek {
    unsigned int positionX;
    unsigned int positionY;
    unsigned int currentSpriteIndex;
    unsigned int speed;
    time_t boostStartTime;
    Sprite images[SPRITE_COUNT];
} Shrek;

Shrek *createShrek();

#endif //CODE_CACAHUETES_SHREK_H