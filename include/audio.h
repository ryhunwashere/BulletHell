#pragma once
#include <raylib.h>

typedef struct AudioFX
{
    Sound sounds[32];   // Stores up to 32 audio effects
    int soundCount;     // How many sound/voices being played
} AudioFX;

typedef struct MusicPlayer
{
    Music musicTracks[16];   // Stores up to 16 music tracks
    int musicCount;
    int currentTrack;   // Index of currently playing track
} MusicPlayer;

void InitAudioComponents(void);
void UpdateMusicPlayer(void);
void UnloadAudioComponents(void);

void PlaySoundFX(int index);
void PlayMusicTrack(int index);