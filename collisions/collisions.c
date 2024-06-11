#include "collisions.h"

int checkCollision(Map *map, int newX, int newY, unsigned int currentMapIndex) {
    for (int row = 0; row < SPRITE_HEIGHT; ++row) {
        for (int col = 0; col < SPRITE_WIDTH; ++col) {
            int mapX = (newX + col) / CELL_SIZE;
            int mapY = (newY + row) / CELL_SIZE;
            if (mapX < 0 || mapX >= map->width || mapY < 0 || mapY >= map->height) {
                return 1;
            }
            if (map->cells[mapY][mapX][0] == BORDER_MAP_SPRITE) {
                return 1;
            }
            if (map->cells[mapY][mapX][0] == FLAG_SPRITE[0][0]) {
                if (!areAllChildrenScared(map, currentMapIndex)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}