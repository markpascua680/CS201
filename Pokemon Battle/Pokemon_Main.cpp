/* Pokemon_Main.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Main source file
*/

#include "Pokemon.h"

int main(int argc, char* argv[])
{
    PlaySound(TEXT("StartUp.wav"), NULL, SND_ASYNC);
    cout << R"(                                  ,'\
    _.----.        ____         ,'  _\   ___    ___     ____
_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                `'                            '-._|)" << endl;

    cout << "Choose your Pokemon:\n";
    cout << "[1] Bulbasaur\n[2] Charmander\n[3] Squirtle\n[4] Pikachu\n[5] Bidoof" << endl;
    cout << "Press a number key" << endl;

    Pokemon pPokemon = choosePoke(); // Player's Pokemon

    random_device r;
    uniform_int_distribution<int> random(1, 5);
    Pokemon cPokemon =  pSelect(random(r)); // Opponent's Pokemon
    cout << "\nYour opponent is " << cPokemon.name << '!';
    cout << "\n\n";

    PlaySound(TEXT("PokemonBattle.wav"), NULL, SND_LOOP | SND_ASYNC);

    Sleep(3500);

    system("CLS");

    decideTurn(pPokemon, cPokemon); // Decides who goes first and begins battle loop in BattleLoop.cpp

    PlaySound(TEXT("EndBattle.wav"), NULL, SND_ASYNC);

    return 0;
}