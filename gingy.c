#include "gingy.h"

Gingy *createGingy() {
    Gingy *newGingy = (Gingy *) malloc(sizeof(Gingy));
    if (newGingy == NULL) {
        return NULL; // Gestion de l'erreur d'allocation mémoire
    }

    newGingy->positionX = 0;
    newGingy->positionY = 0;

    // Initialisation du sprite de l'âne
    char gingySprite[SPRITE_HEIGHT][SPRITE_WIDTH] = {
            {'!', '!', ' ', ' ', ' '},
            {'O', '(', ' ', ')', '~'},
            {' ', '/', ' ', '\\', ' '},
            {' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newGingy->image.image[j][i] = gingySprite[i][j];
        }
    }

    return newGingy;
}