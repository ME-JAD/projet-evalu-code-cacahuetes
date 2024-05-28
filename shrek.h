#include <stdlib.h>
#include <stdio.h>
#include "sprite.h"

#ifndef CODE_CACAHUETES_SHREK_H
#define CODE_CACAHUETES_SHREK_H

#define SHREK_SPRITE_HEAD 'O'
#define SHREK_SPRITE_BODY '|'
#define SHREK_SPRITE_RIGHT '/'
#define SHREK_SPRITE_LEFT '\\'


typedef struct Shrek {
    unsigned int positionX;
    unsigned int positionY;
    Sprite image;
} Shrek;

Shrek *createShrek();

#endif //CODE_CACAHUETES_SHREK_H