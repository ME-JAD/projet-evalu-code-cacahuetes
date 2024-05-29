#include "gingy.h"
//uwu

Gingy *createGingy() {
    Gingy *newGingy = (Gingy *) malloc(sizeof(Gingy));
    if (newGingy == NULL) {
        return NULL;
    }

    newGingy->positionX = 0;
    newGingy->positionY = WIDTH_MAP * WIDTH_MAP;
    newGingy->collision = false;

    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newGingy->image.image[i][j] = ' ';
        }
    }

    newGingy->image.image[0][1] = GINGY_SPRITE_HEAD;
    newGingy->image.image[1][0] = GINGY_SPRITE_LEFT_ARM;
    newGingy->image.image[1][1] = GINGY_SPRITE_BODY;
    newGingy->image.image[1][2] = GINGY_SPRITE_RIGHT_ARM;
    newGingy->image.image[2][0] = GINGY_SPRITE_LEFT;
    newGingy->image.image[2][2] = GINGY_SPRITE_RIGHT;


    return newGingy;
}