/* PlayerInputs.cpp
   Jay-Mark Pascua
   CS 201
   04/13/2020
   Plays sound effects
*/

#include "Pokemon.h"


void continueMusic() { // Continues music after playing a SFX
	random_device r;
	uniform_int_distribution<int> random(0, 2);
	switch (random(r)) {
	case 0: PlaySound(TEXT("PokemonBattleContinue.wav"), NULL, SND_ASYNC);
		break;
	case 1: PlaySound(TEXT("PokemonBattleContinue1.wav"), NULL, SND_ASYNC);
		break;
	case 2: PlaySound(TEXT("PokemonBattleContinue2.wav"), NULL, SND_ASYNC);
		break;
	}
}

void playSound(Pokemon& p, int move){ // Plays SFX of pokemon attacks
    string attack = p.attack[move].getName();
	if (attack == "Quick Attack") {
		PlaySound(TEXT("Quick Attack.wav"), NULL, SND_ASYNC);
		Sleep(800);
		continueMusic();
	}
}