#include "map.h"
#include "move.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char FLAG_SPRITE[FLAG_SPRITE_SIZE][FLAG_SPRITE_SIZE] = {
        {'|', '-', '-', '-', '-'},
        {'|', ' ', ' ', ' ', '|'},
        {'|', '-', '-', '-', '-'},
        {'|', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' '}
};

void displayMap(Map *map) {
    for (int row = 0; row < map->height; ++row) {
        for (int cell_row = 0; cell_row < CELL_SIZE; ++cell_row) {
            for (int col = 0; col < map->width; ++col) {
                for (int cell_col = 0; cell_col < CELL_SIZE; ++cell_col) {
                    int mapX = col * CELL_SIZE + cell_col;
                    int mapY = row * CELL_SIZE + cell_row;

                    int shrekX = map->shrek->positionX;
                    int shrekY = map->shrek->positionY;
                    if (mapX >= shrekX && mapX < shrekX + SPRITE_WIDTH &&
                        mapY >= shrekY && mapY < shrekY + SPRITE_HEIGHT) {
                        int spriteRow = mapY - shrekY;
                        int spriteCol = mapX - shrekX;
                        printf("%c", map->shrek->images[map->shrek->currentSpriteIndex].image[spriteRow][spriteCol]);
                    } else {
                        printf("%c", map->cells[row][col][cell_row * CELL_SIZE + cell_col]);
                    }
                }
            }
            printf("\n");
        }
    }
}

void updateMapWithShrek(Map *map, Shrek *shrek, char direction) {
    printf("\033[?25l");

    for (int row = 0; row < SPRITE_HEIGHT; ++row) {
        for (int col = 0; col < SPRITE_WIDTH; ++col) {
            printf("\033[%d;%dH ", shrek->positionY + row + 1, shrek->positionX + col + 1);
        }
    }

    moveShrek(map, direction);

    for (int row = 0; row < SPRITE_HEIGHT; ++row) {
        for (int col = 0; col < SPRITE_WIDTH; ++col) {
            printf("\033[%d;%dH%c", shrek->positionY + row + 1, shrek->positionX + col + 1, shrek->images[shrek->currentSpriteIndex].image[row][col]);
        }
    }

    printf("\033[%d;%dH", map->height * CELL_SIZE + 1, 1);
    printf("\033[?25h");

    fflush(stdout);
}

Map *createMap(unsigned int width, unsigned int height) {
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
    newMap->donkey = createDonkey();
    newMap->gingy = createGingy();
    newMap->children = createChild();
    return newMap;
}

Map *loadMapFromFile(const char *filename,
                     unsigned int *startX,
                     unsigned int *startY,
                     unsigned int *flagX,
                     unsigned int *flagY,
                     unsigned int *gingyX,
                     unsigned int *gingyY) {

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
                putShrekOnMap(map, map->shrek, col, row);
            }

            if (line[col] == 'A') {
                map->donkey->positionX = col;
                map->donkey->positionY = row;
                for (int cell_row = 0; cell_row < CELL_SIZE; ++cell_row) {
                    for (int cell_col = 0; cell_col < CELL_SIZE; ++cell_col) {
                        map->cells[row][col][cell_row * CELL_SIZE + cell_col] = ' ';
                    }
                }
                putDonkeyOnMap(map, map->donkey, row, col);
            }

            if (line[col] == 'E') {
                map->children->positionX = col;
                map->children->positionY = row;
                for (int cell_row = 0; cell_row < CELL_SIZE; ++cell_row) {
                    for (int cell_col = 0; cell_col < CELL_SIZE; ++cell_col) {
                        map->cells[row][col][cell_row * CELL_SIZE + cell_col] = ' ';
                    }
                }
                putChildOnMap(map, map->children, row, col);
            }

            if (line[col] == 'B') {
                map->gingy->positionX = col;
                map->gingy->positionY = row;
                *gingyX = col;
                *gingyY = row;
                putGingyOnMap(map, map->gingy, *gingyX, *gingyY);
            }

            if (line[col] == '^') {
                *flagX = col;
                *flagY = row;
                placeFlagOnMap(map, *flagX, *flagY);
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

int isLevelComplete(Map *map) {
    for (int row = 0; row < SPRITE_HEIGHT; ++row) {
        for (int col = 0; col < SPRITE_WIDTH; ++col) {
            int shrekX = map->shrek->positionX + col;
            int shrekY = map->shrek->positionY + row;

            if (shrekX / CELL_SIZE == map->flagX && shrekY / CELL_SIZE == map->flagY) {
                return 1;
            }
        }
    }
    return 0;
}

int isShrekEatingGingy(Map *map) {
    for (int row = 0; row < SPRITE_HEIGHT; ++row) {
        for (int col = 0; col < SPRITE_WIDTH; ++col) {
            int shrekX = map->shrek->positionX + col;
            int shrekY = map->shrek->positionY + row;

            if (shrekX / CELL_SIZE == map->gingyX && shrekY / CELL_SIZE == map->gingyY) {
                return 1;
            }
        }
    }
    return 0;
}

int isShrekScaringAChild(Map *map,  unsigned int currentMapIndex) {
    for (int row = 0; row < SPRITE_HEIGHT; ++row) {
        for (int col = 0; col < SPRITE_WIDTH; ++col) {
            int shrekX = map->shrek->positionX + col;
            int shrekY = map->shrek->positionY + row;

            for (int childIndex = 0; childIndex < NUMBER_OF_SCARED_CHILDREN; ++childIndex) {
                if (shrekX == positionXOfChildren[currentMapIndex][childIndex] &&
                    shrekY == positionYOfChildren[currentMapIndex][childIndex]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


void loadNextMap(Map **map, Shrek *shrek, const char *filename) {
    unsigned int startX, startY, flagX, flagY, gingyX, gingyY;
    Map *newMap = loadMapFromFile(filename, &startX, &startY, &flagX, &flagY, &gingyX, &gingyY);
    if (!newMap) {
        printf("Failed to load map: %s\n", filename);
        return;
    }

    free(*map);
    *map = newMap;

    newMap->flagX = flagX;
    newMap->flagY = flagY;

    newMap->gingyX = gingyX;
    newMap->gingyY = gingyY;

    int centeredX = startX;
    int centeredY = startY;
    putShrekOnMap(newMap, shrek, centeredX, centeredY);

    printf("\033[H\033[J");
    displayMap(newMap);
}

void placeFlagOnMap(Map *map, unsigned int flagX, unsigned int flagY) {
    for (int row = 0; row < FLAG_SPRITE_SIZE; ++row) {
        for (int col = 0; col < FLAG_SPRITE_SIZE; ++col) {
            map->cells[flagY][flagX][row * CELL_SIZE + col] = FLAG_SPRITE[row][col];
        }
    }
}

void putGingyOnMap (Map *map, Gingy *gingy, unsigned int gingyX, unsigned int gingyY) {
    map->gingy = gingy;
    map->gingy->positionX = gingyX * CELL_SIZE;
    map->gingy->positionY = gingyY * CELL_SIZE;

    for (int row = 0; row < SPRITE_HEIGHT; ++row) {
        for (int col = 0; col < SPRITE_WIDTH; ++col) {
            map->cells[gingyY][gingyX][row * CELL_SIZE + col] = gingy->image.image[row][col];
        }
    }
}

void putDonkeyOnMap(Map *map, Donkey *donkey, unsigned int donkeyX, unsigned int donkeyY) {
    map->donkey = donkey;
    map->donkey->positionX = donkeyX * CELL_SIZE;
    map->donkey->positionY = donkeyY * CELL_SIZE;

    for (int row = 0; row < SPRITE_HEIGHT; ++row) {
        for (int col = 0; col < SPRITE_WIDTH; ++col) {
            map->cells[donkeyX][donkeyY][row * CELL_SIZE + col] = donkey->image.image[row][col];
        }
    }
}

void putChildOnMap (Map *map, Child *child, unsigned int childX, unsigned int childY) {
    map->children = child;
    map->children->positionX = childX * CELL_SIZE;
    map->children->positionY = childY * CELL_SIZE;

    for (int row = 0; row < SPRITE_HEIGHT; ++row) {
        for (int col = 0; col < SPRITE_WIDTH; ++col) {
            map->cells[childX][childY][row * CELL_SIZE + col] = child->image.image[row][col];
        }
    }
}