#include <stdlib.h>
#include <stdio.h>
#include "sprite.h"

#ifndef CODE_CACAHUETES_SHREK_H
#define CODE_CACAHUETES_SHREK_H

#define SPRITE_WIDTH 5
#define SPRITE_HEIGHT 5
#define SPRITE_COUNT 3

#define SHREK_SPRITE_HORN '\''
#define SHREK_SPRITE_HEAD 'O'
#define SHREK_SPRITE_BODY '('
#define SHREK_SPRITE_ARMS_CLOSE ')'
#define SHREK_SPRITE_RIGHT '/'
#define SHREK_SPRITE_LEFT '\\'

typedef struct Shrek {
    unsigned int positionX;
    unsigned int positionY;
    int currentSpriteIndex;
    Sprite images[SPRITE_COUNT];
} Shrek;

Shrek *createShrek();

#endif //CODE_CACAHUETES_SHREK_H