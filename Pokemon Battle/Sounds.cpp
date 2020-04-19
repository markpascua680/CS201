/* PlayerInputs.cpp
   Jay-Mark Pascua
   CS 201
   04/13/2020
   Plays sound effects
*/

#include "Pokemon.h"


void continueMusic() { // Continues music after playing a SFX
	random_device r;
	uniform_int_distribution<int> random(0, 5);
	switch (random(r)) {
	case 0: PlaySound(TEXT("PokemonBattleContinue.wav"), NULL, SND_ASYNC);
		break;
	case 1: PlaySound(TEXT("PokemonBattleContinue1.wav"), NULL, SND_ASYNC);
		break;
	case 2: PlaySound(TEXT("PokemonBattleContinue2.wav"), NULL, SND_ASYNC);
		break;
	case 3: PlaySound(TEXT("PokemonBattleContinue3.wav"), NULL, SND_ASYNC);
		break;
	case 4: PlaySound(TEXT("PokemonBattleContinue4.wav"), NULL, SND_ASYNC);
		break;
	case 5: PlaySound(TEXT("PokemonBattleContinue5.wav"), NULL, SND_ASYNC);
	}
}

void playSound(Pokemon& p, int move){ // Plays SFX of pokemon attacks
    string attack = p.attack[move].getName();
	if (attack == "Quick Attack") 
		PlaySound(TEXT("Quick Attack.wav"), NULL, SND_ASYNC);
	if (attack == "Tackle")
		PlaySound(TEXT("Tackle.wav"), NULL, SND_ASYNC);
	if (attack == "Scratch")
		PlaySound(TEXT("Scratch.wav"), NULL, SND_ASYNC);
	if (attack == "Vine Whip")
		PlaySound(TEXT("Vine Whip.wav"), NULL, SND_ASYNC);
	if (attack == "Razor Leaf")
		PlaySound(TEXT("Razor Leaf.wav"), NULL, SND_ASYNC);
	if (attack == "Fire Fang")
		PlaySound(TEXT("Fire Fang.wav"), NULL, SND_ASYNC);
	if (attack == "Electro Ball")
		PlaySound(TEXT("Electro Ball.wav"), NULL, SND_ASYNC);
	if (attack == "Rollout")
		PlaySound(TEXT("Rollout.wav"), NULL, SND_ASYNC);
	if (attack == "Ember")
		PlaySound(TEXT("Ember.wav"), NULL, SND_ASYNC);
	if (attack == "Water Gun")
		PlaySound(TEXT("Water Gun.wav"), NULL, SND_ASYNC);
	if (attack == "Water Pulse")
		PlaySound(TEXT("Water Pulse.wav"), NULL, SND_ASYNC);
	if (attack == "Thunder Shock")
		PlaySound(TEXT("Thunder Shock.wav"), NULL, SND_ASYNC);
	if (attack == "Growth")
		PlaySound(TEXT("Growth.wav"), NULL, SND_ASYNC);
	if (attack == "Defense Curl")
		PlaySound(TEXT("Defense Curl.wav"), NULL, SND_ASYNC);
	if (attack == "Smokescreen")
		PlaySound(TEXT("Smokescreen.wav"), NULL, SND_ASYNC);
	if (attack == "Tail Whip")
		PlaySound(TEXT("Tail Whip.wav"), NULL, SND_ASYNC);
	if (attack == "Play Nice")
		PlaySound(TEXT("Play Nice.wav"), NULL, SND_ASYNC);
		Sleep(1300);
		continueMusic();
}