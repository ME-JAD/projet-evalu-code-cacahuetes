#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "shrek.h"
#include "move.h"
#include "map.h"

void clearScreen() {
    printf("\033[H\033[J");
}

int main() {
    const char *filename = "C:\\Users\\agath\\Documents\\GitHub\\Code-Cacahuetes\\map1.txt"; //A ADAPTER !!
    int startX, startY;
    Map *map = loadMapFromFile(filename, &startX, &startY);
    if (!map) {
        return 1;
    }

    Shrek *shrek = createShrek();
    putShrekOnMap(map, shrek, startX, startY);

    clearScreen();
    displayMap(map);

    char input;
    do {
        input = _getch();
        if (input == 'W' || input == 'w') {
            break;
        }
        updateMapWithShrek(map, shrek, input);
    } while (1);

    free(shrek);
    for (int i = 0; i < map->height; ++i) {
        free(map->image[i]);
    }
    free(map);

    return 0;
}
