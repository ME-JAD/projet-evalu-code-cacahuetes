#include <stdlib.h>
#include <stdio.h>

#ifndef CODE_CACAHUETES_SHREK_H
#define CODE_CACAHUETES_SHREK_H

#define SHREK_SPRITE '*'

#define SHREK_WIDTH 3
#define SHREK_HEIGHT 3

typedef struct Shrek {
    int positionX;
    int positionY;
    char image[SHREK_WIDTH][SHREK_HEIGHT];
} Shrek;

Shrek *createShrek();
void displayShrek(Shrek *shrek, int widthMap, int heightMap);
void moveShrek(Shrek *shrek, int widthMap, int heightMap);

#endif //CODE_CACAHUETES_SHREK_H