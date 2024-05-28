#include "shrek.h"


Shrek *createShrek() {
    Shrek *newShrek = (Shrek *) malloc(sizeof(Shrek));
    if (newShrek == NULL) {
        return NULL; // Gestion de l'erreur d'allocation mémoire
    }

    newShrek->positionX = 0;
    newShrek->positionY = WIDTH_MAP * WIDTH_MAP;

    // Initialisation du sprite de Shrek
    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newShrek->image.image[i][j] = ' '; // Remplir avec des espaces par défaut
        }
    }

    // Dessin de Shrek
    newShrek->image.image[0][1] = SHREK_SPRITE_HORN;
    newShrek->image.image[0][2] = SHREK_SPRITE_HEAD;
    newShrek->image.image[0][3] = SHREK_SPRITE_HORN;
    newShrek->image.image[1][0] = SHREK_SPRITE_RIGHT;
    newShrek->image.image[1][1] = SHREK_SPRITE_BODY;
    newShrek->image.image[1][2] = ' ';
    newShrek->image.image[1][3] = SHREK_SPRITE_ARMS_CLOSE;
    newShrek->image.image[1][4] = SHREK_SPRITE_LEFT;
    newShrek->image.image[2][1] = SHREK_SPRITE_RIGHT;
    newShrek->image.image[2][2] = ' ';
    newShrek->image.image[2][3] = SHREK_SPRITE_LEFT;


    return newShrek;
}




/*Shrek *createShrek() {
    Shrek *newShrek = (Shrek *) malloc(sizeof(Shrek));
    if (newShrek == NULL) {
        return NULL; // Gestion de l'erreur d'allocation mémoire
    }

    newShrek->positionX = 0;
    newShrek->positionY = WIDTH_MAP * WIDTH_MAP;

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
}*/
