#ifndef CODE_CACAHUETES_MENU_H
#define CODE_CACAHUETES_MENU_H

#define PLAY_IS_SELECTED '1'
#define QUIT_IS_SELECTED '2'

void loadMenuFromFile(const char *filename);

char getMenuSelection();

void displayMenu();

void displayVictoryMenu();

void displayDefeatMenu();

#endif //CODE_CACAHUETES_MENU_H
