#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "shrek.h"
#include "map.h"

#ifndef CODE_CACAHUETES_MOVE_H
#define CODE_CACAHUETES_MOVE_H
#define SPEED_BOOST 3
#define NUMBER_OF_POSSIBLE_DIRECTIONS 4

void moveShrek(Map *map, char direction, unsigned int currentMapIndex);

void activateSpeedBoost(Shrek *shrek);

void moveDonkeyRandomly(Map *map, unsigned int currentMapIndex);

void moveDonkeysPeriodically(Map *map, unsigned int currentMapIndex);

#endif //CODE_CACAHUETES_MOVE_H
