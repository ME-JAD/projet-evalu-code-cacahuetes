#include <stdio.h>
#include <stdlib.h>

#include "shrek.h"
#include "ane.h"

#ifndef CODE_CACAHUETES_MAP_H
#define CODE_CACAHUETES_MAP_H

#define WIDTH_MAP 380
#define HEIGHT_MAP 120

#define CELL_SIZE 5

#define NUMBER_OF_CELL_IN_MAP_WITDH (WIDTH_MAP / CELL_SIZE)
#define NUMBER_OF_CELL_IN_MAP_HEIGHT (HEIGHT_MAP / CELL_SIZE)

#define MAP_SPRITE ' '
#define BORDER_MAP_SPRITE 'X'

#define FLAG_SPRITE_SIZE 5

typedef struct Map {
    int width;
    int height;
    char ***cells;
    Shrek *shrek;
    unsigned int flagX;
    unsigned int flagY;
} Map;

extern const char FLAG_SPRITE[FLAG_SPRITE_SIZE][FLAG_SPRITE_SIZE];

void displayMap(Map *map);

Map *createMap(int width, int height);

Map *loadMapFromFile(const char *filename, unsigned int *startX, unsigned int *startY, unsigned int *flagX, unsigned int *flagY);

void putShrekOnMap(Map *map, Shrek *shrek, int x, int y);

void updateMapWithShrek(Map *map, Shrek *shrek, char direction);

int isLevelComplete(Map *map);

void loadNextMap(Map **map, Shrek *shrek, const char *filename);

void placeFlagOnMap(Map *map, unsigned int flagX, unsigned int flagY);

#endif //CODE_CACAHUETES_MAP_H

