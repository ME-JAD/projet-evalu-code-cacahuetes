#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../sprite.h"

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
#define NUMBER_TOTAL_OF_MAPS 3
#define GAP_OF_CHILDREN_BELOW_THE_MAP 6
#define HEIGHT_MAP 120
#define WIDTH_MAP 380

typedef struct Child {
    unsigned int positionX;
    unsigned int positionY;
    Sprite image;
} Child;

typedef struct ChildStatus {
    bool scared;
} ChildStatus;

extern unsigned int positionsXOfChildrenOnTheMap[NUMBER_TOTAL_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN];

extern unsigned int positionsYOfChildrenOnTheMap[NUMBER_TOTAL_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN];

extern ChildStatus childStatus[NUMBER_TOTAL_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN];

Child *createChild();

void displayScaredChildrenBelowTheMap(unsigned int scaredChildrenCount);

void clearScaredChildrenBelowTheMap();

#endif //CODE_CACAHUETES_CHILDREN_H
