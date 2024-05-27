#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "shrek.h"
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

    int startX, startY, flagX, flagY;
    Map *map = loadMapFromFile(filenames[currentMapIndex], &startX, &startY, &flagX, &flagY);
    if (!map) {
        return 1;
    }

    Shrek *shrek = createShrek();
    int centeredX = startX - SHREK_WIDTH / 2;
    int centeredY = startY - SHREK_HEIGHT / 2;
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

                printf("\n Congratulations! \n You've completed all levels! \n Shrek is now happy !\n");

                displayVictoryMenu();

                break;
            }
        }
    } while (1);

    free(shrek);
    for (int i = 0; i < map->height; ++i) {
        free(map->image[i]);
    }
    free(map);

    return 0;
}
