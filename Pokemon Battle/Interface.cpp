/* Interface.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Main outputs seen by user; user interface
*/

#include "Pokemon.h"

int main()
{
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


    system("PAUSE");
    system("CLS");

    decideTurn(pPokemon, cPokemon); // Decides who goes first and begins battle loop in BattleLoop.cpp

    return 0;
}



char bLC = 200; // Bottom left box corner character
char tLC = 201; // Top left box corner
char tRC = 187; // Top right box corner character
char bBW = 205; // Bottom box wall character
void displayOptions() { // Displays player's options when it's their turn
    for (int i = 0; i <= 10; i++) { // Prints top box wall
        cout << bBW;
    }
    cout << "\nWhat will you do?" << endl;
    cout << "\n[1] FIGHT\n[2] STATS\n" << endl;
}



void displayAttacks(Pokemon& p) { // Displays player's attacks
    cout << string(15, '\n');
    for (int i = 0; i <= 10; i++) { // Prints top box wall
        cout << bBW;
    }
    cout << endl;
    for (int i = 0; i < 4;i++) {
        cout << '[' << i + 1 << "] " << setw(20) << left << p.attack[i].getName() << "PP: " << p.attack[i].pp << endl;
    }
    cout << "[5] BACK" << endl;
}



void displayHealth(Pokemon& p, Pokemon& pCopy, Pokemon& c, Pokemon& cCopy) { // Displays pokemon's remaining health and base health
    // Opponent's health
    cout << setw(23) << right << bBW << tRC << endl;
    cout << setw(12) << right << c.name << " Lvl. " << c.level << endl;
    cout << setw(12) << right << cCopy.hp << '/' << c.hp << endl;
    cout << bLC << bBW << endl;
    // Player's health
    cout << setw(111) << right << bBW << tRC << endl;
    cout << setw(100) << right << p.name << " Lvl. " << p.level << endl;
    cout << setw(100) << right << pCopy.hp << '/' << p.hp << endl;
    cout << setw(90) << right << bLC << bBW << endl;
}