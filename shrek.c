#include "shrek.h"

Shrek *createShrek() {
    Shrek *newShrek = (Shrek *) malloc(sizeof(Shrek));
    newShrek->positionX = 0;
    newShrek->positionY = 0;
    for (int row = 0; row < SHREK_HEIGHT; row++) {
        for (int column = 0; column < SHREK_WIDTH; column++) {
            newShrek->image[row][column] = SHREK_SPRITE;
        }
    }
    return newShrek;
}

void moveShrek(Shrek *shrek, int widthMap, int heightMap) {
    shrek->positionX = (shrek->positionX + widthMap) % widthMap;
    shrek->positionY = (shrek->positionY + heightMap) % heightMap;
}

