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

Map *loadMapFromFile(const char *filename, unsigned int *startX, unsigned int *startY, unsigned int *flagX, unsigned int *flagY) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open map file");
        return NULL;
    }

    int width = 0, height = 0;
    char line[1024];

    int colCount;
    while (fgets(line, sizeof(line), file)) {
        if (height == 0) {
            width = strlen(line) - 1;
        }
        height++;

        colCount = 0;
        for (int i = 0; i < width; i++) {
            if (line[i] == '^') {
                *flagX = i;
                *flagY = height - 1;
            }
            colCount++;
        }
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
            map->image[row][*startX] = MAP_SPRITE;
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

int isLevelComplete(Map *map) {
    for (int row = 0; row < SHREK_HEIGHT; row++) {
        for (int col = 0; col < SHREK_WIDTH; col++) {
            int shrekX = map->shrek->positionX + col;
            int shrekY = map->shrek->positionY + row;

            if (shrekX == map->flagX && shrekY == map->flagY) {
                return 1;
            }
        }
    }
    return 0;
}


void loadNextMap(Map **map, Shrek *shrek, const char *filename) {
    int startX, startY, flagX, flagY;
    Map *newMap = loadMapFromFile(filename, &startX, &startY, &flagX, &flagY);
    if (!newMap) {
        printf("Failed to load map: %s\n", filename);
        return;
    }

    free(*map);
    *map = newMap;

    newMap->flagX = flagX;
    newMap->flagY = flagY;

    int centeredX = startX - SHREK_WIDTH / 2;
    int centeredY = startY - SHREK_HEIGHT / 2;
    putShrekOnMap(newMap, shrek, centeredX, centeredY);

    printf("\033[H\033[J");
    displayMap(newMap);
}
