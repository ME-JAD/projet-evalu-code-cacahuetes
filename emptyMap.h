#include <stdio.h>
#include <stdlib.h>

#include "shrek.h"

#ifndef CODE_CACAHUETES_EMPTYMAD_H
#define CODE_CACAHUETES_EMPTYMAD_H

#define EMPTY_MAP_SPRITE ' '
#define BORDER_MAP_SPRITE 'X'

typedef struct EmptyMap {
    int width;
    int height;
    char **image;
    Shrek *shrek;
} EmptyMap;

void displayEmptyMap(EmptyMap *map);

EmptyMap *createEmptyMap(int width, int height);

void putShrekOnEmptyMap(EmptyMap *map, Shrek *shrek, int x,int y);



#endif //CODE_CACAHUETES_EMPTYMAD_H
