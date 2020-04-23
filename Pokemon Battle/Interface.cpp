/* Interface.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Main outputs seen by user; user interface
*/

#include "Pokemon.h"

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
    cout << string(12, '\n');
    printBoxTop();
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << char(186) << ' ' << '[' << i + 1 << "] " << setw(20) << left << p.attack[i].getName() << "PP: " << p.attack[i].pp <<
            setw(5) << right << char(186) << endl;
    }
    cout << char(186) << ' ' << "[5] BACK" << setw(27) << right << char(186) << endl;
    printBoxBottom();
}



string displayHealthBar(int remainingHP, int hp) { // Displays pokemons' health bar
    string healthBar = "";

    double segment = hp / 10; // Divides total hp by 10

    int bars = (int)round(remainingHP / segment); // Divides remaining hp by # of segments; decreases # of segments
    std::vector<char> cHP(bars, char(254));
    for (auto x : cHP) {
        healthBar += x;
    }
    return healthBar;
}



void displayHealth(Pokemon& p, Pokemon& pCopy, Pokemon& c, Pokemon& cCopy) { // Displays pokemons' remaining health and base health
    // Opponent's health
    cout << setw(23) << right << char(205) << char(187) << endl;
    cout << setw(12) << c.name << " Lvl. " << c.level << endl;
    cout << setw(6) << right << '[' << setw(10) << left << displayHealthBar(cCopy.hp, c.hp) << ']' << endl;
    cout << setw(12) << right << cCopy.hp << '/' << c.hp << endl;
    cout << char(200) << char(205) << endl;
    // Player's health
    cout << setw(111) << right << char(205) << char(187) << endl;
    cout << setw(100) << right << p.name << " Lvl. " << p.level << endl;
    cout << setw(95) << right << '[' << setw(10) << left << displayHealthBar(pCopy.hp, p.hp) << ']' << endl;
    cout << setw(100) << right << pCopy.hp << '/' << p.hp << endl;
    cout << setw(90) << right << char(200) << char(205) << endl;
}