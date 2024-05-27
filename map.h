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
    unsigned int flagX;
    unsigned int flagY;
}Map;

void displayMap(Map *map);

Map *createMap(int width, int height);

Map *loadMapFromFile(const char *filename, unsigned int *startX, unsigned int *startY, unsigned int *flagX, unsigned int *flagY);

void putShrekOnMap(Map *map, Shrek *shrek, int x, int y);

void updateMapWithShrek(Map *map, Shrek *shrek, char direction);

int isLevelComplete(Map *map);

void loadNextMap(Map **map, Shrek *shrek, const char *filename);

#endif //CODE_CACAHUETES_MAP_H
