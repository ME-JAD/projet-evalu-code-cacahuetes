#include "music.h"


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

