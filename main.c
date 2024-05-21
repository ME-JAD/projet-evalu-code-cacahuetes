#include <stdlib.h>
#include <windows.h>

#include "emptyMap.h"
#include "shrek.h"

int main() {
    int widthMap = 225;
    int heightMap = 60;
    Map *map = createEmptyMap(widthMap, heightMap);
    Shrek *shrek = createShrek();

    putShrekOnMap(map, shrek, 1, 1);

    for (int i = 0; i < 5; ++i) {
        system("cls");
        displayEmptyMap(map);
        moveShrekDownRight(shrek, widthMap, heightMap);
        Sleep(100);
    }

    free(shrek);
    for (int i = 0; i < map->height; ++i) {
        free(map->image[i]);
    }
    free(map->image);
    free(map);


    return 0;
}
