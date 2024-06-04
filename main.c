#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <unistd.h>

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

    unsigned int currentMapIndex = 0;
    unsigned int startX, startY, flagX, flagY, gingyX, gingyY;
    char input;
    unsigned int iterationCount = 0;
    unsigned int scaredChildrenCount = 0;

    Map *map = loadMapFromFile(filenames[currentMapIndex], &startX, &startY, &flagX, &flagY, &gingyX, &gingyY);
    if (!map) {
        return 1;
    }

    Shrek *shrek = createShrek();

    int centeredX = startX;
    int centeredY = startY;

    putShrekOnMap(map, shrek, centeredX, centeredY);
    map->flagX = flagX;
    map->flagY = flagY;
    map->gingyX = gingyX;
    map->gingyY = gingyY;

    clearScreen();
    displayMap(map);

    do {
        input = _getch();
        if (input == 'W' || input == 'w') {
            break;
        }
        updateMapWithShrek(map, shrek, input);

        if (isLevelComplete(map)) {
            scaredChildrenCount = 0;
            clearScaredChildrenBelowTheMap();
            currentMapIndex++;

            if (currentMapIndex < sizeof(filenames) / sizeof(filenames[0])) {
                loadNextMap(&map, shrek, filenames[currentMapIndex]);
            } else {
                displayVictoryMenu();
                break;
            }
        }

        if (iterationCount % 2 == 0) {
            updateMapWithDonkey(map);
        }

        if (isShrekCollisionDonkey(map, shrek)) {
            displayDefeatMenu();
            break;
        }

        iterationCount++;
        usleep(50);

        if (isShrekEatingGingy(map)) {
            activateSpeedBoost(map->shrek);
        }

        if (isShrekScaringAChild(map, currentMapIndex)) {
            scaredChildrenCount++;
            displayScaredChildrenBelowTheMap(scaredChildrenCount);
        }

        if (shrek->speed > 1 && difftime(time(NULL), shrek->boostStartTime) >= 5) {
            shrek->speed = 1;
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