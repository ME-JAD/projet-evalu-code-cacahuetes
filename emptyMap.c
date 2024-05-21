#include "emptyMap.h"

void displayEmptyMap(Map *map) {
    for (int row = 0; row < map->height; ++row) {
        for (int column = 0; column < map->width; ++column) {
            if ((column == 0 || column == map->width - 1) && (row >= map->height / 2 - SHREK_HEIGHT && row <= map->height / 2 + SHREK_HEIGHT)) {
                map->image[row][column] = EMPTY_MAP_SPRITE;
            } else if ((row == 0 || row == map->height - 1) && (column >= map->width / 2 - SHREK_WIDTH && column <= map->width / 2 + SHREK_WIDTH)) {
                map->image[row][column] = EMPTY_MAP_SPRITE;
            } else if (row == 0 || row == map->height - 1 || column == 0 || column == map->width - 1) {
                map->image[row][column] = BORDER_MAP_SPRITE;
            } else {
                map->image[row][column] = EMPTY_MAP_SPRITE;
            }
        }
    }

    for (int row = 0; row < SHREK_HEIGHT; ++row) {
        for (int column = 0; column < SHREK_WIDTH; ++column) {
            int posX = map->shrek->positionX + column;
            int posY = map->shrek->positionY + row;
            if (posX < map->width && posY < map->height) {
                map->image[posY][posX] = map->shrek->image[row][column];
            }
        }
    }

    for (int row = 0; row < map->height; ++row) {
        for (int column = 0; column < map->width; ++column) {
            printf("%c", map->image[row][column]);
        }
        printf("\n");
    }
}


Map *createEmptyMap(int width, int height) {
    Map *newMap = (Map *) malloc(sizeof(Map));
    newMap->height = height;
    newMap->width = width;
    newMap->image = (char **) malloc(height * sizeof(char *));
    for (int row = 0; row < height; ++row) {
        newMap->image[row] = (char *) malloc((width + 1) * sizeof(char));
        for (int column = 0; column < width; ++column) {
            newMap->image[row][column] = EMPTY_MAP_SPRITE;
        }
        newMap->image[row][width] = '\0';
    }
    newMap->shrek = createShrek();
    return newMap;
}

void putShrekOnMap(Map *map, Shrek *shrek, int x, int y) {
    map->shrek = shrek;
    shrek->positionX = x;
    shrek->positionY = y;
}
