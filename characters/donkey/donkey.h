#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../sprite.h"

#ifndef CODE_CACAHUETES_ANE_H
#define CODE_CACAHUETES_ANE_H

#define DONKEY_SPRITE_HEAD '!'
#define DONKEY_SPRITE_NOSE 'O'
#define DONKEY_SPRITE_BODY_L '('
#define DONKEY_SPRITE_BODY_R ')'
#define DONKEY_SPRITE_TAIL '~'
#define DONKEY_SPRITE_PAW '|'
#define NUMBER_MAX_OF_DONKEYS 10

typedef struct Donkey{
    unsigned int positionX;
    unsigned int positionY;
    bool collision;
    Sprite image;
}Donkey;

Donkey *createDonkey();

#endif //CODE_CACAHUETES_ANE_H