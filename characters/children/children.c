#include "children.h"

Child *createChild() {
    Child *newChild = (Child *) malloc(sizeof(Child));
    if (newChild == NULL) {
        return NULL;
    }

    newChild->positionX = 0;
    newChild->positionY = 0;

    for (int i = 0; i < SPRITE_HEIGHT; ++i) {
        for (int j = 0; j < SPRITE_WIDTH; ++j) {
            newChild->image.image[i][j] = ' ';
        }
    }

    newChild->image.image[1][0] = CHILD_SPRITE_HEAD_R;
    newChild->image.image[1][1] = CHILD_SPRITE_EYES;
    newChild->image.image[1][2] = CHILD_SPRITE_MOUTH;
    newChild->image.image[1][3] = CHILD_SPRITE_EYES;
    newChild->image.image[1][4] = CHILD_SPRITE_HEAD_L;
    newChild->image.image[2][1] = CHILD_SPRITE_LEFT_ARM;
    newChild->image.image[2][2] = CHILD_SPRITE_BODY;
    newChild->image.image[2][3] = CHILD_SPRITE_RIGHT_ARM;
    newChild->image.image[3][1] = CHILD_SPRITE_LEFT;
    newChild->image.image[3][3] = CHILD_SPRITE_RIGHT;

    return newChild;
}

unsigned int positionsXOfChildrenOnTheMap[NUMBER_TOTAL_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN] = {
        {245, 225, 350},
        {25, 340, 355},
        {125, 165, 150}
};
unsigned int positionsYOfChildrenOnTheMap[NUMBER_TOTAL_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN] = {
        {100, 10, 10},
        {10, 105, 45},
        {70, 105, 25}
};

ChildStatus childStatus[NUMBER_TOTAL_OF_MAPS][NUMBER_MAX_OF_SCARED_CHILDREN] = {
        {{false}, {false}, {false}},
        {{false}, {false}, {false}},
        {{false}, {false}, {false}}
};

void displayScaredChildrenBelowTheMap(unsigned int scaredChildrenCount) {
    unsigned int offsetX = 0;
    unsigned int offsetY = HEIGHT_MAP + 2;

    for (int i = 0; i < scaredChildrenCount; ++i) {
        for (int row = 0; row < NUMBER_MAX_OF_SCARED_CHILDREN; ++row) {
            printf("\033[%d;%dH", offsetY + row, offsetX + i + GAP_OF_CHILDREN_BELOW_THE_MAP);
            printf("     ");
        }
    }

    for (int i = 0 ; i < scaredChildrenCount; ++i) {
        int childOffsetX = offsetX + i * GAP_OF_CHILDREN_BELOW_THE_MAP;
        printf("\033[%d;%dH", offsetY, childOffsetX);
        printf("(T_T)");
        printf("\033[%d;%dH", offsetY + 1, childOffsetX);
        printf(" /|\\ ");
        printf("\033[%d;%dH", offsetY + 2, childOffsetX);
        printf(" / \\ ");
    }
}

void clearScaredChildrenBelowTheMap() {
    int mapHeight = HEIGHT_MAP;
    int offsetX = 0;
    int offsetY = mapHeight + 2;

    for (int i = 0; i < NUMBER_MAX_OF_SCARED_CHILDREN; ++i) {
        for (int row = 0; row < NUMBER_MAX_OF_SCARED_CHILDREN; ++row) {
            printf("\033[%d;%dH", offsetY + row, offsetX + i * GAP_OF_CHILDREN_BELOW_THE_MAP);
            printf("     ");
        }
    }
}