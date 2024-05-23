#include "move.h"
#include "map.h"

void moveShrekDownRight(Shrek *shrek, int widthMap, int heightMap) {
    if (shrek->positionX < widthMap - SHREK_WIDTH - 1) {
        shrek->positionX++;
    }
    if (shrek->positionY < heightMap - SHREK_HEIGHT - 1) {
        shrek->positionY++;
    }
}

void moveShrek(Map *map, char direction) {
    int deltaX = 0;
    int deltaY = 0;

    switch (direction) {
        case 'Z':
        case 'z':
            deltaY = -1;
            break;
        case 'S':
        case 's':
            deltaY = 1;
            break;
        case 'Q':
        case 'q':
            deltaX = -1;
            break;
        case 'D':
        case 'd':
            deltaX = 1;
            break;
        default:
            return;
    }

    for (int row = 0; row < SHREK_HEIGHT; row++) {
        for (int col = 0; col < SHREK_WIDTH; col++) {
            printf("\033[%d;%dH ", map->shrek->positionY + row + 1, map->shrek->positionX + col + 1);
        }
    }

    map->shrek->positionX += deltaX;
    map->shrek->positionY += deltaY;

    for (int row = 0; row < SHREK_HEIGHT; row++) {
        for (int col = 0; col < SHREK_WIDTH; col++) {
            printf("\033[%d;%dH%c", map->shrek->positionY + row + 1, map->shrek->positionX + col + 1, map->shrek->image[row][col]);
        }
    }

    fflush(stdout);
}
