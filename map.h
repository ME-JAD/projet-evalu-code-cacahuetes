#ifndef CODE_CACAHUETES_MAP_H
#define CODE_CACAHUETES_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shrek.h"
#include "ane.h"
#include "gingy.h"
#include "children.h"
#include "flag.h"

#define CELL_SIZE 5
#define BORDER_MAP_SPRITE '#'

typedef struct Map {
    int width;
    int height;
    char ***cells;
    Shrek *shrek;
    Donkey *donkeys [NUMBER_MAX_OF_DONKEYS];
    Gingy *gingy;
    Child *children;
    unsigned int donkeyCount;
    unsigned int flagX;
    unsigned int flagY;
    unsigned int gingyX;
    unsigned int gingyY;
} Map;

Map *createMap(unsigned int width, unsigned int height);
void displayMap(Map *map);
Map *loadMapFromFile(const char *filename,
                     unsigned int *startX,
                     unsigned int *startY,
                     unsigned int *flagX,
                     unsigned int *flagY,
                     unsigned int *gingyX,
                     unsigned int *gingyY,
                     unsigned int currentMapIndex,
                     unsigned int childIndex);
void loadNextMap(Map **map, Shrek *shrek, const char *filename);

void putShrekOnMap(Map *map, Shrek *shrek, int x, int y);
void putGingyOnMap (Map *map, Gingy *gingy, unsigned int gingyX, unsigned int gingyY);
void putDonkeyOnMap(Map *map, Donkey *donkey, unsigned int donkeyX, unsigned int donkeyY);
void putChildOnMap (Map *map, Child *child, unsigned int childX, unsigned int childY, unsigned int currentMapIndex, unsigned int childIndex);
void placeFlagOnMap(Map *map, unsigned int flagX, unsigned int flagY);

void updateMapWithShrek(Map *map, Shrek *shrek, char direction);
void updateMapWithDonkey(Map *map);

int isLevelComplete(Map *map, unsigned int currentMapIndex);
int isShrekEatingGingy(Map *map);
bool isShrekCollisionDonkey(Map *map, Shrek *shrek);
int isShrekScaringAChild(Map *map,  unsigned int currentMapIndex);
int areAllChildrenScared(Map *map, unsigned int currentMapIndex);

#endif //CODE_CACAHUETES_MAP_H
