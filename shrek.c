#include "shrek.h"

Shrek *createShrek() {
    Shrek *newShrek = (Shrek *) malloc(sizeof(Shrek));
    newShrek->positionX = 0;
    newShrek->positionY = 0;

    newShrek->image[0][1] = 'O';
    newShrek->image[1][0] = '/';
    newShrek->image[1][1] = '|';
    newShrek->image[1][2] = '\\';
    newShrek->image[2][0] = '/';
    newShrek->image[2][2] = '\\';

    for (int i = 0; i < SHREK_HEIGHT; ++i) {
        for (int j = 0; j < SHREK_WIDTH; ++j) {
            if (newShrek->image[i][j] != 'O' &&
                newShrek->image[i][j] != '|' &&
                newShrek->image[i][j] != '/' &&
                newShrek->image[i][j] != '\\') {
                newShrek->image[i][j] = ' '; // Empty space
            }
        }
    }

    return newShrek;
}

void moveShrek(Shrek *shrek, int widthMap, int heightMap) {
    shrek->positionX = (shrek->positionX + widthMap) % widthMap;
    shrek->positionY = (shrek->positionY + heightMap) % heightMap;
}

void moveShrekDownRight(Shrek *shrek, int widthMap, int heightMap) {
    if (shrek->positionX < widthMap - SHREK_WIDTH - 1) {
        shrek->positionX++;
    }
    if (shrek->positionY < heightMap - SHREK_HEIGHT - 1) {
        shrek->positionY++;
    }
}

