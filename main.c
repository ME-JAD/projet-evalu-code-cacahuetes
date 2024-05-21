#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "emptyMap.h"
#include "shrek.h"
#include "move.h"

void clearScreen() {
    printf("\033[H\033[J");
}

int main() {
    int widthMap = 220;
    int heightMap = 70;
    Map *map = createEmptyMap(widthMap, heightMap);
    Shrek *shrek = createShrek();
    putShrekOnMap(map, shrek, (widthMap/2)-1, (heightMap/2)-1);

    displayEmptyMap(map);

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
