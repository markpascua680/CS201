/* Interface.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Main outputs seen by user; user interface
*/

#include "Pokemon.h"

int main()
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

    return 0;
}



void clearScreen(Pokemon& p, Pokemon& tempP, Pokemon& c, Pokemon& tempC) {
    system("CLS");
    displayHealth(p, tempP, c, tempC);
}




// char(201) = Top left box corner character
// char(187) = Top right box corner character
// char(200) = Bottom left box corner character
// char(188) = Bottom right box corner character
// char(186) = Box wall sides character
// char(205) = Bottom/top box wall character
void printBoxTop() { // Prints top of box wall
    cout << char(201);
    for (int i = 0; i <= 34; i++) { 
        cout << char(205);
    }
    cout << char(187);
}



void printBoxBottom() { // Prints bottom of box wall
    cout << char(200);
    for (int i = 0; i <= 34; i++) {
        cout << char(205);
    }
    cout << char(188);
}



void displayOptions() { // Displays player's options when it's their turn
    printBoxTop();
    cout << "\n" << char(186) << " What will you do?" << setw(18) << char(186) << endl;
    cout << char(186) << setw(36) << char(186) << "\n" << char(186) << " [1] FIGHT" << setw(26) << char(186) << "\n" << char(186) << 
        " [2] STATS" << setw(26) << char(186) << "\n" << char(186) << setw(36) << char(186) << endl;
    printBoxBottom();
}



void displayAttacks(Pokemon& p) { // Displays player's attacks
    cout << string(15, '\n');
    printBoxTop();
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << char(186) << ' ' << '[' << i + 1 << "] " << setw(20) << left << p.attack[i].getName() << "PP: " << p.attack[i].pp << 
            setw(5) << right << char(186) << endl;
    }
    cout << char(186) << ' ' << "[5] BACK" << setw(27) << right << char(186) << endl;
    printBoxBottom();
}



void displayHealth(Pokemon& p, Pokemon& pCopy, Pokemon& c, Pokemon& cCopy) { // Displays pokemon's remaining health and base health
    // Opponent's health
    cout << setw(23) << right << char(205) << char(187) << endl;
    cout << setw(12) << right << c.name << " Lvl. " << c.level << endl;
    cout << setw(12) << right << cCopy.hp << '/' << c.hp << endl;
    cout << char(200) << char(205) << endl;
    // Player's health
    cout << setw(111) << right << char(205) << char(187) << endl;
    cout << setw(100) << right << p.name << " Lvl. " << p.level << endl;
    cout << setw(100) << right << pCopy.hp << '/' << p.hp << endl;
    cout << setw(90) << right << char(200) << char(205) << endl;
}