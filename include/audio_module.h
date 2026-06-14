#ifndef AUDIO_MODULE_H
#define AUDIO_MODULE_H

#include "raylib.h"

void InitAudio(void);
void CloseAudio(void);
Sound LoadEffect(const char *fileName);
void PlayEffect(Sound sound);

#endif
