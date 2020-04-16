/* PlayerInputs.cpp
   Jay-Mark Pascua
   CS 201
   04/13/2020
   Plays sound effects
*/

#include "Pokemon.h"

void playMusic() {
	SDL_Init(SDL_INIT_AUDIO);
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;

	// Load wav file

	SDL_LoadWAV("Quick Attack.wav", &wavSpec, &wavBuffer, &wavLength);

	// Open audio device

	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

	// Play audio

	int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);

	SDL_Delay(1000);
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
	SDL_Quit();
}

void playSound(Pokemon& p, int move){
    string attack = p.attack[move].getName();
	if (attack == "Quick Attack") {
		PlaySound(TEXT("Quick Attack.wav"), NULL, SND_ASYNC);
	}
}