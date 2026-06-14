#include "audio_module.h"

void InitAudio(void) {
    InitAudioDevice();
}

void CloseAudio(void) {
    CloseAudioDevice();
}

Sound LoadEffect(const char *fileName) {
    return LoadSound(fileName);
}

void PlayEffect(Sound sound) {
    PlaySound(sound);
}
