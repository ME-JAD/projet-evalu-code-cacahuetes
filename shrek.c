#include "shrek.h"

#define WIDTH_MAP 220
#define HEIGHT_MAP 70

Shrek *createShrek() {
    Shrek *newShrek = (Shrek *) malloc(sizeof(Shrek));
    newShrek->positionX = 0;
    newShrek->positionY = WIDTH_MAP*WIDTH_MAP;

    newShrek->image[0][1] = SHREK_SPRITE_HEAD;
    newShrek->image[1][0] = SHREK_SPRITE_RIGHT;
    newShrek->image[1][1] = SHREK_SPRITE_BODY;
    newShrek->image[1][2] = SHREK_SPRITE_LEFT;
    newShrek->image[2][0] = SHREK_SPRITE_RIGHT;
    newShrek->image[2][2] = SHREK_SPRITE_LEFT;

    for (int i = 0; i < SHREK_HEIGHT; ++i) {
        for (int j = 0; j < SHREK_WIDTH; ++j) {
            if (newShrek->image[i][j] != 'O' &&
                newShrek->image[i][j] != '|' &&
                newShrek->image[i][j] != '/' &&
                newShrek->image[i][j] != '\\') {
                newShrek->image[i][j] = ' ';
            }
        }
    }

    return newShrek;
}

