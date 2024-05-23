#include <stdlib.h>
#include <stdbool.h>

#ifndef CODE_CACAHUETES_ANE_H
#define CODE_CACAHUETES_ANE_H

#define PLANE_SIZE 20
#define PLANE_SPRITE 20
typedef struct Donkey{
    int x;
    int y;
    int width;
    int heght;
    bool collision;
    char** sprite;

}Donkey;

Donkey createDonkey(int x, int y);

#endif //CODE_CACAHUETES_ANE_H