#include "shrek.h"

#define WIDTH_MAP 200
#define HEIGHT_MAP 70

Shrek *createShrek() {
    Shrek *newShrek = (Shrek *) malloc(sizeof(Shrek));
    if (newShrek == NULL) {
        return NULL; // Gestion de l'erreur d'allocation mémoire
    }

    newShrek->positionX = 0;
    newShrek->positionY = WIDTH_MAP * HEIGHT_MAP;

    // Initialisation du sprite de Shrek
    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newShrek->image.image[i][j] = ' '; // Remplir avec des espaces par défaut
        }
    }

    newShrek->image.image[0][1] = SHREK_SPRITE_HEAD;
    newShrek->image.image[1][0] = SHREK_SPRITE_RIGHT;
    newShrek->image.image[1][1] = SHREK_SPRITE_BODY;
    newShrek->image.image[1][2] = SHREK_SPRITE_LEFT;
    newShrek->image.image[2][0] = SHREK_SPRITE_RIGHT;
    newShrek->image.image[2][2] = SHREK_SPRITE_LEFT;

    return newShrek;
}
