#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "sprite.h"

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
#define NUMBER_MAX_OF_SCARED_CHILDREN 3
#define NUMBER_OF_MAPS 3

typedef struct Child {
    unsigned int positionX;
    unsigned int positionY;
    Sprite image;
} Child;

typedef struct ChildStatus {
    bool scared;
} ChildStatus;

extern unsigned int positionXOfChildren[NUMBER_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN];

extern unsigned int positionYOfChildren[NUMBER_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN];

extern ChildStatus childStatus[NUMBER_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN];

Child *createChild();

#endif //CODE_CACAHUETES_CHILDREN_H
