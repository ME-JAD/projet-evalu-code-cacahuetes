#include "map.h"
#include "move.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMap(Map *map) {
    for (int row = 0; row < map->height; ++row) {
        for (int cell_row = 0; cell_row < CELL_SIZE; ++cell_row) {
            for (int col = 0; col < map->width; ++col) {
                for (int cell_col = 0; cell_col < CELL_SIZE; ++cell_col) {
                    printf("%c", map->cells[row][col][cell_row * CELL_SIZE + cell_col]);
                }
            }
            printf("\n");
        }
    }
}

Map *createMap(int width, int height) {
    Map *newMap = (Map *) malloc(sizeof(Map));
    newMap->height = height;
    newMap->width = width;
    newMap->cells = (char ***) malloc(height * sizeof(char **));
    for (int row = 0; row < height; ++row) {
        newMap->cells[row] = (char **) malloc(width * sizeof(char *));
        for (int col = 0; col < width; ++col) {
            newMap->cells[row][col] = (char *) malloc(CELL_SIZE * CELL_SIZE * sizeof(char));
            for (int cell_row = 0; cell_row < CELL_SIZE; ++cell_row) {
                for (int cell_col = 0; cell_col < CELL_SIZE; ++cell_col) {
                    newMap->cells[row][col][cell_row * CELL_SIZE + cell_col] = ' ';
                }
            }
        }
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

    while (fgets(line, sizeof(line), file)) {
        if (height == 0) {
            width = strlen(line) - 1;
        }
        height++;
    }

    fseek(file, 0, SEEK_SET);

    Map *map = createMap(width, height);
    for (int row = 0; row < height; ++row) {
        fgets(line, sizeof(line), file);
        for (int col = 0; col < width; ++col) {
            for (int cell_row = 0; cell_row < CELL_SIZE; ++cell_row) {
                for (int cell_col = 0; cell_col < CELL_SIZE; ++cell_col) {
                    map->cells[row][col][cell_row * CELL_SIZE + cell_col] = line[col];
                }
            }

            if (line[col] == 'S') {
                *startX = col;
                *startY = row;
                for (int cell_row = 0; cell_row < CELL_SIZE; ++cell_row) {
                    for (int cell_col = 0; cell_col < CELL_SIZE; ++cell_col) {
                        map->cells[row][col][cell_row * CELL_SIZE + cell_col] = ' ';
                    }
                }
            }

            if (line[col] == '^') {
                *flagX = col;
                *flagY = row;
            }
        }
    }

    fclose(file);
    return map;
}

void putShrekOnMap(Map *map, Shrek *shrek, int x, int y) {
    map->shrek = shrek;
    map->shrek->positionX = x * CELL_SIZE;
    map->shrek->positionY = y * CELL_SIZE;
}

void updateMapWithShrek(Map *map, Shrek *shrek, char direction) {
    for (int row = 0; row < SHREK_HEIGHT; ++row) {
        for (int col = 0; col < SHREK_WIDTH; ++col) {
            printf("\033[%d;%dH ", shrek->positionY + row + 1, shrek->positionX + col + 1);
        }
    }

    moveShrek(map, direction);

    for (int row = 0; row < SHREK_HEIGHT; ++row) {
        for (int col = 0; col < SHREK_WIDTH; ++col) {
            printf("\033[%d;%dH%c", shrek->positionY + row + 1, shrek->positionX + col + 1, shrek->image[row][col]);
        }
    }

    fflush(stdout);
}

int isLevelComplete(Map *map) {
    for (int row = 0; row < SHREK_HEIGHT; ++row) {
        for (int col = 0; col < SHREK_WIDTH; ++col) {
            int shrekX = map->shrek->positionX + col;
            int shrekY = map->shrek->positionY + row;

            if (shrekX / CELL_SIZE == map->flagX && shrekY / CELL_SIZE == map->flagY) {
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

    int centeredX = startX;
    int centeredY = startY;
    putShrekOnMap(newMap, shrek, centeredX, centeredY);

    printf("\033[H\033[J");
    displayMap(newMap);
}