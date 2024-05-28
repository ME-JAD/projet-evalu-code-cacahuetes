#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "shrek.h"
#include "ane.h"
#include "move.h"
#include "map.h"
#include "menu.h"

void clearScreen() {
    printf("\033[H\033[J");
}

int main() {
    system("chcp 65001");

    displayMenu();

    char menuSelection = getMenuSelection();

    if (menuSelection == '2') {
        printf("\nExiting the game...\n");
        return 0;
    }

    const char *filenames[] = {
            "../map1.txt",
            "../map2.txt",
            "../map3.txt"
    };
    int currentMapIndex = 0;

    unsigned int startX, startY, flagX, flagY;
    Map *map = loadMapFromFile(filenames[currentMapIndex], &startX, &startY, &flagX, &flagY);
    if (!map) {
        return 1;
    }

    Shrek *shrek = createShrek();
    int centeredX = startX;
    int centeredY = startY;
    putShrekOnMap(map, shrek, centeredX, centeredY);
    map->flagX = flagX;
    map->flagY = flagY;

    clearScreen();
    displayMap(map);

    char input;
    do {
        input = _getch();
        if (input == 'W' || input == 'w') {
            break;
        }
        updateMapWithShrek(map, shrek, input);

        if (isLevelComplete(map)) {
            currentMapIndex++;
            if (currentMapIndex < sizeof(filenames) / sizeof(filenames[0])) {
                loadNextMap(&map, shrek, filenames[currentMapIndex]);
            } else {
                displayVictoryMenu();
                break;
            }
        }
    } while (1);

    free(shrek);
    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            free(map->cells[i][j]);
        }
        free(map->cells[i]);
    }
    free(map->cells);
    free(map);

    return 0;
}