//
// Created by lilou.boutibonnes on 16/05/2024.
//

#include "ane.h"

Donkey createDonkey(int x, int y){
    Donkey *newDonkey = (Donkey *) malloc(sizeof(Donkey));
    newDonkey->x = x;
    newDonkey->y = y;
    for (int row = 0; row < PLANE_SIZE; row++) {
        for (int column = 0; column < PLANE_SIZE; column++) {
            newDonkey->sprite[row][column] = PLANE_SPRITE;
        }
    }
    return *newDonkey;
}