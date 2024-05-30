#include "move.h"
#include "collision.h"

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

    int newX = map->shrek->positionX + deltaX * CELL_SIZE;
    int newY = map->shrek->positionY + deltaY * CELL_SIZE;

    if (checkCollision(map, newX, newY)) {
        return;
    }

    for (int row = 0; row < SPRITE_HEIGHT; row++) {
        for (int col = 0; col < SPRITE_WIDTH; col++) {
            printf("\033[%d;%dH ", map->shrek->positionY + row + 1, map->shrek->positionX + col + 1);
        }
    }

    map->shrek->positionX = newX;
    map->shrek->positionY = newY;

    for (int row = 0; row < SPRITE_HEIGHT; row++) {
        for (int col = 0; col < SPRITE_WIDTH; col++) {
            printf("\033[%d;%dH%c", map->shrek->positionY + row + 1, map->shrek->positionX + col + 1, map->shrek->image.image[row][col]);
        }
    }

    fflush(stdout);
}
