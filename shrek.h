#include <stdlib.h>
#include <stdio.h>

#ifndef CODE_CACAHUETES_SHREK_H
#define CODE_CACAHUETES_SHREK_H

#define SHREK_SPRITE_HEAD 'O'
#define SHREK_SPRITE_BODY '|'
#define SHREK_SPRITE_RIGHT '/'
#define SHREK_SPRITE_LEFT '\\'


#define SHREK_WIDTH 5
#define SHREK_HEIGHT 5

typedef struct Shrek {
    unsigned int positionX;
    unsigned int positionY;
    char image[SHREK_WIDTH][SHREK_HEIGHT];
} Shrek;

Shrek *createShrek();

#endif //CODE_CACAHUETES_SHREK_H