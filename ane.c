#include "ane.h"

Donkey *createDonkey() {
    Donkey *newDonkey = (Donkey *) malloc(sizeof(Donkey));
    if (newDonkey == NULL) {
        return NULL; // Gestion de l'erreur d'allocation mémoire
    }

    newDonkey->positionX = 0;
    newDonkey->positionY = WIDTH_MAP * WIDTH_MAP;
    newDonkey->collision = false;

    // Initialisation du sprite de Shrek
    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newDonkey->image.image[i][j] = ' '; // Remplir avec des espaces par défaut
        }
    }

    newDonkey->image.image[0][1] = DONKEY_SPRITE_HEAD;
    newDonkey->image.image[0][2] = DONKEY_SPRITE_HEAD;
    newDonkey->image.image[1][0] = DONKEY_SPRITE_NOSE;
    newDonkey->image.image[1][1] = DONKEY_SPRITE_BODY_L;
    newDonkey->image.image[1][3] = DONKEY_SPRITE_BODY_R;
    newDonkey->image.image[1][4] = DONKEY_SPRITE_TAIL;
    newDonkey->image.image[2][2] = DONKEY_SPRITE_PAW;
    newDonkey->image.image[2][4] = DONKEY_SPRITE_PAW;


    return newDonkey;
}


/*Donkey *createDonkey() {
    Donkey *newDonkey = (Donkey *) malloc(sizeof(Donkey));
    if (newDonkey == NULL) {
        return NULL; // Gestion de l'erreur d'allocation mémoire
    }

    newDonkey->positionX = 0;
    newDonkey->positionY = 0;

    // Initialisation du sprite de l'âne
    char donkeySprite[SPRITE_HEIGHT][SPRITE_WIDTH] = {
            {'!', '!', ' ', ' ', ' '},
            {'O', '(', ' ', ')', '~'},
            {' ', '/', ' ', '\\', ' '},
            {' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newDonkey->image.image[j][i] = donkeySprite[i][j];
        }
    }

    return newDonkey;
}*/