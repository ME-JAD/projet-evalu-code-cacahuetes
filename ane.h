#include <stdlib.h>
#include <stdbool.h>
#include "sprite.h"

#ifndef CODE_CACAHUETES_ANE_H
#define CODE_CACAHUETES_ANE_H

#define PLANE_SIZE 20
#define PLANE_SPRITE 20
typedef struct Donkey{
    int positionX;
    int positionY;
    bool collision;
    Sprite image;

}Donkey;

Donkey *createDonkey();

#endif //CODE_CACAHUETES_ANE_H