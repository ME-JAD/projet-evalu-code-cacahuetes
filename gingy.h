//
// Created by lilou.boutibonnes on 28/05/2024.
//
#include <stdlib.h>
#include <stdbool.h>
#include "sprite.h"

#ifndef CODE_CACAHUETES_GINGY_H
#define CODE_CACAHUETES_GINGY_H

typedef struct Gingy{
    int positionX;
    int positionY;
    bool collision;
    Sprite image;

}Gingy;

Gingy *createGingy();

#endif //CODE_CACAHUETES_GINGY_H
