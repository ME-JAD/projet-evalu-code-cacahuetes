#include "map.h"
#include "move.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMap(Map *map) {
    for (int row = 0; row < map->height; ++row) {
        for (int column = 0; column < map->width; ++column) {
            printf("%c", map->image[row][column]);
        }
        printf("\n");
    }
}

Map *createMap(int width, int height) {
    Map *newMap = (Map *) malloc(sizeof(Map));
    newMap->height = height;
    newMap->width = width;
    newMap->image = (char **) malloc(height * sizeof(char *));
    for (int row = 0; row < height; ++row) {
        newMap->image[row] = (char *) malloc((width + 1) * sizeof(char));
        for (int column = 0; column < width; ++column) {
            newMap->image[row][column] = MAP_SPRITE;
        }
        newMap->image[row][width] = '\0';
    }
    newMap->shrek = createShrek();
    return newMap;
}

Map *loadMapFromFile(const char *filename, int *startX, int *startY) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open map file");
        return NULL;
    }

    int width = 0, height = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        if (height == 0) {
            width = strlen(line) - 1;
        }
        height++;
    }

    fseek(file, 0, SEEK_SET);

    Map *map = createMap(width, height);
    for (int row = 0; row < height; ++row) {
        fgets(map->image[row], width + 2, file);
        map->image[row][width] = '\0';

        char *startPos = strchr(map->image[row], 'S');
        if (startPos) {
            *startX = startPos - map->image[row];
            *startY = row;
        }
    }

    fclose(file);
    return map;
}

void putShrekOnMap(Map *map, Shrek *shrek, int x, int y) {
    map->shrek = shrek;
    map->shrek->positionX = x;
    map->shrek->positionY = y;
}

void updateMapWithShrek(Map *map, Shrek *shrek, char direction) {
    for (int row = 0; row < SHREK_HEIGHT; row++) {
        for (int col = 0; col < SHREK_WIDTH; col++) {
            printf("\033[%d;%dH ", shrek->positionY + row + 1, shrek->positionX + col + 1);
        }
    }

    moveShrek(map, direction);

    for (int row = 0; row < SHREK_HEIGHT; row++) {
        for (int col = 0; col < SHREK_WIDTH; col++) {
            printf("\033[%d;%dH%c", shrek->positionY + row + 1, shrek->positionX + col + 1, shrek->image[row][col]);
        }
    }

    fflush(stdout);
}
