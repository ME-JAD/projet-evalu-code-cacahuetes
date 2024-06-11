#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include "menu/menu.h"
#include "move/move.h"

bool keepPlayingMusic = true;

void* playMusic(void* arg) {
    char* filename = (char*)arg;
    char command[256];

    while (keepPlayingMusic) {
        snprintf(command, sizeof(command), "powershell -Command \"(New-Object Media.SoundPlayer '%s').PlaySync()\"", filename);
        system(command);
    }

    return NULL;
}

void* playAudioOnce(void* arg) {
    char* filename = (char*)arg;
    char command[256];

    snprintf(command, sizeof(command), "powershell -Command \"(New-Object Media.SoundPlayer '%s').PlaySync()\"", filename);
    system(command);

    return NULL;
}

void clearScreen() {
    printf("\033[H\033[J");
}

int main() {
    system("chcp 65001");

    pthread_t musicThread;
    char* backgroundMusicFile = "../audio/Saving_Donkeys_Ass.wav";
    int result = pthread_create(&musicThread, NULL, playMusic, (void*)backgroundMusicFile);
    if (result != 0) {
        printf("Error creating music thread\n");
        return 1;
    }

    displayMenu();

    char menuSelection = getMenuSelection();

    if (menuSelection == QUIT_IS_SELECTED) {
        printf("\nExiting the game...\n");
        keepPlayingMusic = false;
        system("taskkill /IM powershell.exe /F");
        pthread_join(musicThread, NULL);
        return 0;
    }

    const char *filenames[] = {
            "../map1.txt",
            "../map2.txt",
            "../map3.txt"
    };

    unsigned int currentMapIndex = 0;
    unsigned int startX, startY, flagX, flagY, gingyX, gingyY;
    char input;
    unsigned int scaredChildrenCount = 0;

    Map *map = loadMapFromFile(filenames[currentMapIndex], &startX, &startY, &flagX, &flagY, &gingyX, &gingyY, currentMapIndex, scaredChildrenCount);
    if (!map) {
        keepPlayingMusic = false; // Arrêter la musique
        system("taskkill /IM powershell.exe /F");
        pthread_join(musicThread, NULL);
        return 1;
    }

    Shrek *shrek = createShrek();

    int centeredX = startX;
    int centeredY = startY;

    putShrekOnMap(map, shrek, centeredX, centeredY);
    map->flagX = flagX;
    map->flagY = flagY;
    map->gingyX = gingyX;
    map->gingyY = gingyY;

    clearScreen();
    displayMap(map);


    clock_t lastMoveTime = clock();
    const double moveInterval = 0.5 * CLOCKS_PER_SEC;

    bool gameRunning = true;
    while (gameRunning) {

        if (_kbhit()) {
            input = _getch();
            if (input == 'W' || input == 'w') {
                keepPlayingMusic = false;
                system("taskkill /IM powershell.exe /F");
                pthread_join(musicThread, NULL);
                gameRunning = false;
                break;
            }
            updateMapWithShrek(map, shrek, input, currentMapIndex);

            if (isLevelComplete(map, currentMapIndex)) {
                scaredChildrenCount = 0;
                clearScaredChildrenBelowTheMap();
                currentMapIndex++;

                if (currentMapIndex < sizeof(filenames) / sizeof(filenames[0])) {
                    loadNextMap(&map, shrek, filenames[currentMapIndex]);
                } else {
                    keepPlayingMusic = false;
                    system("taskkill /IM powershell.exe /F");
                    pthread_join(musicThread, NULL);

                    char* victoryMusicFile = "../audio/victory.wav";
                    pthread_t victoryMusicThread;
                    int victoryMusicResult = pthread_create(&victoryMusicThread, NULL, playAudioOnce, (void*)victoryMusicFile);
                    if (victoryMusicResult != 0) {
                        printf("Error creating defeat music thread\n");
                    }

                    displayVictoryMenu();

                    if (victoryMusicResult == 0) {
                        pthread_join(victoryMusicThread, NULL);
                    }

                    gameRunning = false;
                    break;
                }
            }

            if (isShrekCollisionDonkey(map, shrek)) {
                keepPlayingMusic = false;
                system("taskkill /IM powershell.exe /F");
                pthread_join(musicThread, NULL);

                displayDefeatMenu();
                char* defeatMusicFile = "../audio/ane.wav";
                pthread_t defeatMusicThread;
                int defeatMusicResult = pthread_create(&defeatMusicThread, NULL, playAudioOnce, (void*)defeatMusicFile);
                if (defeatMusicResult != 0) {
                    printf("Error creating defeat music thread\n");
                }

                if (defeatMusicResult == 0) {
                    pthread_join(defeatMusicThread, NULL);
                }

                gameRunning = false;
                break;
            }

            if (isShrekEatingGingy(map)) {

                activateSpeedBoost(map->shrek);

                char* boostSoundFile = "../audio/gingy.wav";
                pthread_t boostSoundThread;
                int boostSoundResult = pthread_create(&boostSoundThread, NULL, playAudioOnce, (void*)boostSoundFile);
                if (boostSoundResult != 0) {
                    printf("Error creating scared child sound thread\n");
                }

            }

            if (isShrekScaringAChild(map, currentMapIndex)) {
                scaredChildrenCount++;
                displayScaredChildrenBelowTheMap(scaredChildrenCount);

                char* scaredChildSoundFile = "../audio/enfant.wav";
                pthread_t scaredChildSoundThread;
                int scaredChildSoundResult = pthread_create(&scaredChildSoundThread, NULL, playAudioOnce, (void*)scaredChildSoundFile);
                if (scaredChildSoundResult != 0) {
                    printf("Error creating scared child sound thread\n");
                }
            }

            if (shrek->speed > 1 && difftime(time(NULL), shrek->boostStartTime) >= 5) {
                shrek->speed = 1;
            }
        }

        clock_t currentTime = clock();
        if ((currentTime - lastMoveTime) >= moveInterval) {
            moveDonkeysPeriodically(map, currentMapIndex);
            lastMoveTime = currentTime;
        }

        usleep(10000);
    }

    free(shrek);
    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            free(map->cells[i][j]);
        }
        free(map->cells[i]);
    }
    free(map->cells);
    free(map);

    return 0;
}
