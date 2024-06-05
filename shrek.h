#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sprite.h"

#ifndef CODE_CACAHUETES_SHREK_H
#define CODE_CACAHUETES_SHREK_H

#define SHREK_SPRITE_COUNT 3

typedef struct Shrek {
    unsigned int positionX;
    unsigned int positionY;
    unsigned int currentSpriteIndex;
    unsigned int speed;
    char direction;
    time_t boostStartTime;
    Sprite images[SHREK_SPRITE_COUNT];
} Shrek;

Shrek *createShrek();

#endif //CODE_CACAHUETES_SHREK_H