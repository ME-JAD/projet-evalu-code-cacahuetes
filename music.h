//
// Created by lilou.boutibonnes on 10/06/2024.
//

#ifndef CODE_CACAHUETES_MUSIC_H
#define CODE_CACAHUETES_MUSIC_H

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

bool keepPlayingMusic = true;

void* playMusic(void* arg);
void* playAudioOnce(void* arg);


#endif //CODE_CACAHUETES_MUSIC_H
