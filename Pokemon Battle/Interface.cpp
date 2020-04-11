/* Interface.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Main outputs seen by user; user interface
*/

#include "Pokemon.h"

int main()
{
    srand((unsigned)time(0)); // Generates random number
    
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

    Pokemon cPokemon =  pSelect((rand() % 5) + 1); // Opponent's Pokemon
    cout << "\nYour opponent is " << cPokemon.name << '!';
    cout << "\n\n";


    system("PAUSE");
    system("CLS");

    decideTurn(pPokemon, cPokemon); // Decides who goes first and begins battle loop in BattleLoop.cpp

    return 0;
}

