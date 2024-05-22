#include <stdio.h>
#include <stdlib.h>
//#include "plane.h"

#ifndef DOGFIGHT_CIR1_SKY_H
#define DOGFIGHT_CIR1_SKY_H
#define EMPTY_MAP_SPRITE '-'

typedef struct Map {
    int width;
    int height;
    //Plane *plane;
    char **image;
} Map;

void displayMap(Map map);

Map *createMap(int width, int height);

//void putPlaneOnMap(Map *map, Plane *plane, int x, int y);

#endif //DOGFIGHT_CIR1_SKY_H
