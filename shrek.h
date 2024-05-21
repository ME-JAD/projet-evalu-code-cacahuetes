#include <stdlib.h>
#include <stdio.h>

#ifndef CODE_CACAHUETES_SHREK_H
#define CODE_CACAHUETES_SHREK_H

#define SHREK_SPRITE_HEAD 'O'
#define SHREK_SPRITE_BODY '|'
#define SHREK_SPRITE_ARM '/'
#define SHREK_SPRITE_LEG '\\'


#define SHREK_WIDTH 5
#define SHREK_HEIGHT 5

typedef struct Shrek {
    int positionX;
    int positionY;
    char image[SHREK_WIDTH][SHREK_HEIGHT];
} Shrek;

Shrek *createShrek();
void displayShrek(Shrek *shrek, int widthMap, int heightMap);
void moveShrek(Shrek *shrek, int widthMap, int heightMap);
void moveShrekDownRight(Shrek *shrek, int widthMap, int heightMap);

#endif //CODE_CACAHUETES_SHREK_H