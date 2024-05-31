#ifndef CODE_CACAHUETES_MAP_H
#define CODE_CACAHUETES_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include "shrek.h"
#include "ane.h"
#include "gingy.h"
#include "children.h"

#define WIDTH_MAP 380
#define HEIGHT_MAP 120

#define CELL_SIZE 5
#define SPRITE_WIDTH 5
#define SPRITE_HEIGHT 5
#define BORDER_MAP_SPRITE '#'
#define FLAG_SPRITE_SIZE 5

typedef struct Map {
    int width;
    int height;
    char ***cells;
    Shrek *shrek;
    Donkey *donkey;
    Gingy *gingy;
    Child *children;
    unsigned int flagX;
    unsigned int flagY;
    unsigned int gingyX;
    unsigned int gingyY;
} Map;

extern const char FLAG_SPRITE[FLAG_SPRITE_SIZE][FLAG_SPRITE_SIZE];

void putDonkeyOnMap(Map *map, Donkey *donkey, unsigned int donkeyX, unsigned int donkeyY);

void putGingyOnMap (Map *map, Gingy *gingy, unsigned int gingyX, unsigned int gingyY);

void putChildOnMap (Map *map, Child *child, unsigned int childrenX, unsigned int childrenY);

void displayMap(Map *map);

Map *createMap(unsigned int width, unsigned int height);

Map *loadMapFromFile(const char *filename,
                     unsigned int *startX,
                     unsigned int *startY,
                     unsigned int *flagX,
                     unsigned int *flagY,
                     unsigned int *gingyX,
                     unsigned int *gingyY);

void putShrekOnMap(Map *map, Shrek *shrek, int x, int y);

void updateMapWithShrek(Map *map, Shrek *shrek, char direction);

int isLevelComplete(Map *map);

void loadNextMap(Map **map, Shrek *shrek, const char *filename);

void placeFlagOnMap(Map *map, unsigned int flagX, unsigned int flagY);

int isShrekEatingGingy(Map *map);

#endif //CODE_CACAHUETES_MAP_H
