#include <stdlib.h>
#include <stdbool.h>
#include "sprite.h"


#ifndef CODE_CACAHUETES_GINGY_H
#define CODE_CACAHUETES_GINGY_H

#define GINGY_SPRITE_HEAD 'o'
#define GINGY_SPRITE_LEFT_ARM '/'
#define GINGY_SPRITE_RIGHT_ARM '\\'
#define GINGY_SPRITE_BODY '|'
#define GINGY_SPRITE_LEFT '/'
#define GINGY_SPRITE_RIGHT '\\'


typedef struct Gingy{
    unsigned int positionX;
    unsigned int positionY;
    bool collision;
    Sprite image;

}Gingy;

Gingy *createGingy();

#endif //CODE_CACAHUETES_GINGY_H
