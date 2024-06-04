#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "menu.h"

void loadMenuFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open menu file");
        exit(EXIT_FAILURE);
    }

    printf("\033[H\033[J");

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

char getMenuSelection() {
    char selection;
    do {
        selection = _getch();
    } while (selection != PLAY_IS_SELECTED && selection != QUIT_IS_SELECTED);
    return selection;
}

void displayMenu() {
    const char *menuFilename = "../menu.txt";
    loadMenuFromFile(menuFilename);
}
void displayVictoryMenu() {
    const char *menuFilename = "../victory.txt";
    loadMenuFromFile(menuFilename);
}
void displayDefeatMenu() {
    const char *menuFilename = "../defeat.txt";
    loadMenuFromFile(menuFilename);
}
