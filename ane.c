//
// Created by lilou.boutibonnes on 16/05/2024.
//

#include "ane.h"

Donkey *createDonkey() {
    Donkey *newDonkey = (Donkey *) malloc(sizeof(Donkey));
    if (newDonkey == NULL) {
        return NULL; // Gestion de l'erreur d'allocation mémoire
    }

    newDonkey->positionX = 0;
    newDonkey->positionY = 0;

    // Initialisation du sprite de l'âne
    char donkeySprite[SPRITE_HEIGHT][SPRITE_WIDTH] = {
            {'!', '!', ' ', ' ', ' ', ' '},
            {'O', '(', ' ', ')', '~', '~'},
            {' ', '/', ' ', '\\', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newDonkey->image.image[j][i] = donkeySprite[i][j];
        }
    }

    return newDonkey;
}