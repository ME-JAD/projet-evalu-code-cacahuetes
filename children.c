#include "children.h"

Child *createChild() {
    Child *newChild = (Child *) malloc(sizeof(Child));
    if (newChild == NULL) {
        return NULL;
    }

    newChild->positionX = 0;
    newChild->positionY = 0;

    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newChild->image.image[i][j] = ' ';
        }
    }

    newChild->image.image[1][0] = CHILD_SPRITE_HEAD_R;
    newChild->image.image[1][1] = CHILD_SPRITE_EYES;
    newChild->image.image[1][2] = CHILD_SPRITE_MOUTH;
    newChild->image.image[1][3] = CHILD_SPRITE_EYES;
    newChild->image.image[1][4] = CHILD_SPRITE_HEAD_L;
    newChild->image.image[2][1] = CHILD_SPRITE_LEFT_ARM;
    newChild->image.image[2][2] = CHILD_SPRITE_BODY;
    newChild->image.image[2][3] = CHILD_SPRITE_RIGHT_ARM;
    newChild->image.image[3][1] = CHILD_SPRITE_LEFT;
    newChild->image.image[3][3] = CHILD_SPRITE_RIGHT;

    return newChild;
}

unsigned int positionXOfChildren[NUMBER_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN] = {
        {245, 225, 350}, // enf1 (X1)   ;  enft2(X1)   ;  enft3(X1)
        {25, 340, 355},  // enf1 (X2)   ;  enft2(X2)   ;  enft3(X2)
        {125, 165, 150}  // enf1 (X3)   ;  enft2(X3)   ;  enft3(X3)
};
unsigned int positionYOfChildren[NUMBER_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN] = {
        {100, 10, 10}, // enf1 (Y1)   ;  enft2(Y1)   ;  enft3(Y1)
        {10, 105, 45}, // enf1 (Y2)   ;  enft2(Y2)   ;  enft3(Y2)
        {70, 105, 25}  // enf1 (Y3)   ;  enft2(Y3)   ;  enft3(Y3)
};

ChildStatus childStatus[NUMBER_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN] = {
        {{false}, {false}, {false}},
        {{false}, {false}, {false}},
        {{false}, {false}, {false}}
};