//
// Created by lilou.boutibonnes on 15/05/2024.
//

#include "map.h"

void displayMap(Map map) {
    for (int i = 0; i < map.width; ++i) {
        for (int j = 0; j < map.height; ++j) {
            printf("%c", EMPTY_MAP_SPRITE);
        }
        printf("\n");
    }
}

Map *createMap(int width, int height) {
    Map *newMap = (Map *) malloc(sizeof(Map));
    newMap->width = width;
    newMap->height = height;
    newMap->image = (char **) malloc(height * sizeof(char *));
    for (int row = 0; row < height; ++row) {
        newMap->image[row] = (char *) malloc((width + 1) * sizeof(char));
        for (int column = 0; column < width; ++column) {
            newMap->image[row][column] = EMPTY_MAP_SPRITE;
        }
        newMap->image[row][width] = '\0';
    }
    return newMap;
}

/*void putPlaneOnSky(Map *map, Plane *plane, int x, int y) {
    if (sky->plane != NULL) {
        return;
    }
    sky->plane = plane;
    sky->plane->x = x;
    sky->plane->y = y;
}*/