#include <stdlib.h>
#include <stdbool.h>
#include "sprite.h"
//uwu

#ifndef CODE_CACAHUETES_CHILDREN_H
#define CODE_CACAHUETES_CHILDREN_H

#define CHILD_SPRITE_HEAD_R '('
#define CHILD_SPRITE_HEAD_L ')'
#define CHILD_SPRITE_EYES 'T'
#define CHILD_SPRITE_MOUTH '_'
#define CHILD_SPRITE_LEFT_ARM '/'
#define CHILD_SPRITE_RIGHT_ARM '\\'
#define CHILD_SPRITE_BODY '|'
#define CHILD_SPRITE_LEFT '/'
#define CHILD_SPRITE_RIGHT '\\'


typedef struct Child{
    unsigned int positionX;
    unsigned int positionY;
    bool collision;
    Sprite image;

}Child;

Child *createChild();

#endif //CODE_CACAHUETES_CHILDREN_H
