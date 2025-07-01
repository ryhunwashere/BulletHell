#include <raylib.h>
#include "audio.h"

AudioFX gAudioFX = {0};
MusicPlayer gMusicPlayer = {0};

int getMusicCount()
{
    return sizeof(gAudioFX.sounds) / sizeof(gAudioFX.sounds[0]);
}

int getSoundCount()
{
    return sizeof(gMusicPlayer.musicTracks) / sizeof(gMusicPlayer.musicTracks[0]);
}

void InitAudioComponents(void) {
    InitAudioDevice();
    
    // Load some sounds
    gAudioFX.sounds[0] = LoadSound("../assets/sounds/PlayerShoot1.wav");
    gAudioFX.soundCount = getSoundCount();
    
    // Load some music
    gMusicPlayer.musicTracks[0] = LoadMusicStream("../assets/music/music_track.ogg");
    gMusicPlayer.musicCount = getMusicCount();
    gMusicPlayer.currentTrack = 0;
    
    PlayMusicStream(gMusicPlayer.musicTracks[gMusicPlayer.currentTrack]);
}

void UpdateMusicPlayer(void) {
    // Update the stream each frame
    UpdateMusicStream(gMusicPlayer.musicTracks[gMusicPlayer.currentTrack]);
}

void UnloadAudioComponents(void) {
    for (int i = 0; i < gAudioFX.soundCount; i++) {
        UnloadSound(gAudioFX.sounds[i]);
    }
    for (int i = 0; i < gMusicPlayer.musicCount; i++) {
        UnloadMusicStream(gMusicPlayer.musicTracks[i]);
    }
    CloseAudioDevice();
}

void PlaySoundFX(int index) {
    if (index >= 0 && index < gAudioFX.soundCount) {
        PlaySound(gAudioFX.sounds[index]);
    }
}

void PlayMusicTrack(int index) {
    if (index >= 0 && index < gMusicPlayer.musicCount) {
        StopMusicStream(gMusicPlayer.musicTracks[gMusicPlayer.currentTrack]);
        gMusicPlayer.currentTrack = index;
        PlayMusicStream(gMusicPlayer.musicTracks[gMusicPlayer.currentTrack]);
    }
}
