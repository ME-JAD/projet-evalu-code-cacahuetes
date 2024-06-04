#include "move.h"
#include "collision.h"

void moveShrek(Map *map, char direction) {
    int deltaX = 0;
    int deltaY = 0;

    switch (direction) {
        case 'Z':
        case 'z':
            deltaY = -CELL_SIZE * map->shrek->speed;
            break;
        case 'S':
        case 's':
            deltaY = CELL_SIZE * map->shrek->speed;
            break;
        case 'Q':
        case 'q':
            deltaX = -CELL_SIZE * map->shrek->speed;
            break;
        case 'D':
        case 'd':
            deltaX = CELL_SIZE * map->shrek->speed;
            break;
        default:
            return;
    }

    int newX = map->shrek->positionX + deltaX;
    int newY = map->shrek->positionY + deltaY;

    if (checkCollision(map, newX, newY)) {
        return;
    }

    for (int row = 0; row < SPRITE_HEIGHT; row++) {
        for (int col = 0; col < SPRITE_WIDTH; col++) {
            printf("\033[%d;%dH ", map->shrek->positionY + row + 1, map->shrek->positionX + col + 1);
        }
    }

    map->shrek->positionX = newX;
    map->shrek->positionY = newY;

    map->shrek->currentSpriteIndex = (map->shrek->currentSpriteIndex + 1) % SPRITE_COUNT;

    for (int row = 0; row < SPRITE_HEIGHT; row++) {
        for (int col = 0; col < SPRITE_WIDTH; col++) {
            printf("\033[%d;%dH%c", map->shrek->positionY + row + 1, map->shrek->positionX + col + 1,
                   map->shrek->images[map->shrek->currentSpriteIndex].image[row][col]);
        }
    }

    fflush(stdout);
}

void activateSpeedBoost(Shrek *shrek) {
    shrek->speed = 3;
    shrek->boostStartTime = time(NULL);
}

void moveDonkeyRandomly(Map *map) {
    for (int i = 0; i < map->donkeyCount; ++i) {
        if (map->donkeys[i] != NULL) {
            int oldX = 0;
            int oldY = 0;

            int direction = rand() % 4;
            switch (direction) {
                case 0: // Move up
                    oldY = -CELL_SIZE;
                    break;
                case 1: // Move down
                    oldY = CELL_SIZE;
                    break;
                case 2: // Move left
                    oldX = -CELL_SIZE;
                    break;
                case 3: // Move right
                    oldX = CELL_SIZE;
                    break;
            }

            int newX = map->donkeys[i]->positionX + oldX;
            int newY = map->donkeys[i]->positionY + oldY;

            if (checkCollision(map, newX, newY)) {
                return;
            }

            for (int row = 0; row < SPRITE_HEIGHT; row++) {
                for (int col = 0; col < SPRITE_WIDTH; col++) {
                    printf("\033[%d;%dH ", map->donkeys[i]->positionY + row + 1, map->donkeys[i]->positionX + col + 1);
                }
            }

            map->donkeys[i]->positionX = newX;
            map->donkeys[i]->positionY = newY;


            for (int row = 0; row < SPRITE_HEIGHT; row++) {
                for (int col = 0; col < SPRITE_WIDTH; col++) {
                    printf("\033[%d;%dH%c", map->donkeys[i]->positionY + row + 1, map->donkeys[i]->positionX + col + 1,
                           map->donkeys[i]->image.image[row][col]);
                }
            }

            fflush(stdout);
        }
    }
}