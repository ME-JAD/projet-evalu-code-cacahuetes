#include "children.h"
//uwu
Child *createChild() {
    Child *newChild = (Child *) malloc(sizeof(Child));
    if (newChild == NULL) {
        return NULL;
    }

    newChild->positionX = 0;
    newChild->positionY = WIDTH_MAP * WIDTH_MAP;
    newChild->collision = false;

    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newChild->image.image[i][j] = ' ';
        }
    }

    newChild->image.image[0][0] = CHILD_SPRITE_HEAD_R;
    newChild->image.image[0][1] = CHILD_SPRITE_EYES;
    newChild->image.image[0][2] = CHILD_SPRITE_MOUTH;
    newChild->image.image[0][3] = CHILD_SPRITE_EYES;
    newChild->image.image[0][4] = CHILD_SPRITE_HEAD_L;
    newChild->image.image[1][1] = CHILD_SPRITE_LEFT_ARM;
    newChild->image.image[1][2] = CHILD_SPRITE_BODY;
    newChild->image.image[1][2] = CHILD_SPRITE_RIGHT_ARM;
    newChild->image.image[2][1] = CHILD_SPRITE_LEFT;
    newChild->image.image[2][3] = CHILD_SPRITE_RIGHT;


    return newChild;
}
