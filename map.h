#include <stdio.h>
#include <stdlib.h>

#include "shrek.h"

#ifndef CODE_CACAHUETES_MAP_H
#define CODE_CACAHUETES_MAP_H

#define WIDTH_MAP 220
#define HEIGHT_MAP 70

#define MAP_SPRITE ' '
#define BORDER_MAP_SPRITE 'X'

typedef struct Map {
    int width;
    int height;
    char **image;
    Shrek *shrek;
}Map;

void displayMap(Map *map);

Map *createMap(int width, int height);

Map *loadMapFromFile(const char *filename, int *startX, int *startY);

void putShrekOnMap(Map *map, Shrek *shrek, int x, int y);

void updateMapWithShrek(Map *map, Shrek *shrek, char direction);

#endif //CODE_CACAHUETES_MAP_H
