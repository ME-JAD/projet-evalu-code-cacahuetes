#include "shrek.h"

Shrek *createShrek() {
    Shrek *shrek = (Shrek *) malloc(sizeof(Shrek));
    shrek->positionX = 0;
    shrek->positionY = 0;
    shrek->currentSpriteIndex = 0;

    char sprite1[SPRITE_HEIGHT][SPRITE_WIDTH] = {
            {' ', ' ', ' ', ' ', ' '},
            {' ', '\'', 'O', '\'', ' '},
            {'/', '(', ' ', ')', '\\'},
            {' ', '/', ' ', '\\', ' '},
            {' ', ' ', ' ', ' ', ' '}
    };

    char sprite2[SPRITE_HEIGHT][SPRITE_WIDTH] = {
            {' ', ' ', ' ', ' ', ' '},
            {' ', '\'', 'O', '\'', ' '},
            {'\\', '(', ' ', ')', '/'},
            {' ', '|', ' ', '|', ' '},
            {' ', ' ', ' ', ' ', ' '}
    };

    char sprite3[SPRITE_HEIGHT][SPRITE_WIDTH] = {
            {' ', ' ', ' ', ' ', ' '},
            {' ', '\'', 'O', '\'', ' '},
            {'/', '(', ' ', ')', '\\'},
            {' ', '\\', ' ', '/', ' '},
            {' ', ' ', ' ', ' ', ' '}
    };

    memcpy(shrek->images[0].image, sprite1, sizeof(sprite1));
    memcpy(shrek->images[1].image, sprite2, sizeof(sprite2));
    memcpy(shrek->images[2].image, sprite3, sizeof(sprite3));

    return shrek;
}