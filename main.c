#include <stdlib.h>
#include <windows.h>

#include "emptyMap.h"
#include "shrek.h"

void moveShrekDownRight(Shrek *shrek, int widthMap, int heightMap) {
    if (shrek->positionX < widthMap - SHREK_WIDTH - 1) {
        shrek->positionX++;
    }
    if (shrek->positionY < heightMap - SHREK_HEIGHT - 1) {
        shrek->positionY++;
    }
}

int main() {
    int widthMap = 40;
    int heightMap = 20;
    Map *map = createEmptyMap(widthMap, heightMap);
    Shrek *shrek = createShrek();

    putShrekOnMap(map, shrek, 1, 1);

    for (int i = 0; i < 20; ++i) {
        system("cls");
        displayEmptyMap(map);
        moveShrekDownRight(shrek, widthMap, heightMap);
        Sleep(500);
    }

    free(shrek);
    for (int i = 0; i < map->height; ++i) {
        free(map->image[i]);
    }
    free(map->image);
    free(map);


    return 0;
}
