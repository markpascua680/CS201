/* Jay-Mark Pascua
   CS 201
   02/10/2020
   User enters number of pennies, nickels, dimes, quarters, and dollar coins. Outputs total.
*/
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int pennies;
int nickels;
int dimes;
int quarters;
int dollars;
int total;

void printCoins(int p, int n, int d, int q, int dol);

int main()
{
    cout << "How many pennies do you have?" << endl;
        cin >> pennies;
    cout << "How many nickels do you have?" << endl;
        cin >> nickels;
    cout << "How many dimes do you have?" << endl;
        cin >> dimes;
    cout << "How many quarters do you have?" << endl;
        cin >> quarters;
    cout << "How many dollar coins do you have?" << endl;
        cin >> dollars;

        printCoins(pennies, nickels, dimes, quarters, dollars);

    return 0;
}

void printCoins(int p, int n, int d, int q, int dol)
{
    cout << "You have " << p << " pennies" << endl;
    cout << "You have " << n << " nickels" << endl;
    cout << "You have " << d << " dimes" << endl;
    cout << "You have " << q << " quarters" << endl;
    cout << "You have " << dol << " dollars" << endl;
}