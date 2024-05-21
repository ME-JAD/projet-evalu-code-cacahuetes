#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "emptyMap.h"
#include "shrek.h"
#include "move.h"

#define WIDTH_MAP 220
#define HEIGHT_MAP 70

void clearScreen() {
    printf("\033[H\033[J");
}

int main() {
    Map *map = createEmptyMap(WIDTH_MAP, HEIGHT_MAP);
    Shrek *shrek = createShrek();

    displayEmptyMap(map);
    putShrekOnMap(map, shrek, SHREK_WIDTH, HEIGHT_MAP-(SHREK_HEIGHT-1));

    char input;
    do {
        input = getch();
        moveShrek(map, input);
    } while (input != 'W' && input != 'w');

    free(shrek);
    for (int i = 0; i < map->height; ++i) {
        free(map->image[i]);
    }
    free(map->image);
    free(map);

    return 0;
}
