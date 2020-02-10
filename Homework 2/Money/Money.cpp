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
double amount;

void printCoins(int p, int n, int d, int q, int dol);
void total(int p, int n, int d, int q, int dol);

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
        cout << endl;
        printCoins(pennies, nickels, dimes, quarters, dollars);
        total(pennies, nickels, dimes, quarters, dollars);

    return 0;
}

void printCoins(int p, int n, int d, int q, int dol) // Prints amount of each coin
{
    if (p == 1)                                      // If statements output singular amount
        cout << "You have " << p << " penny" << endl;
    else 
        cout << "You have " << p << " pennies" << endl;
    if (n == 1)
        cout << "You have " << n << " nickel" << endl;
    else 
        cout << "You have " << n << " nickels" << endl;
    if (d == 1)
        cout << "You have " << d << " dime" << endl;
    else
        cout << "You have " << d << " dimes" << endl;
    if (q == 1)
        cout << "You have " << q << " quarters" << endl;
    else 
        cout << "You have " << q << " quarters" << endl;
    if (dol == 1)
        cout << "You have " << dol << " dollar" << endl;
    else
    cout << "You have " << dol << " dollars" << endl;
}

void total(int p, int n, int d, int q, int dol)
{
    amount = (double)(p + (5 * n) + (10 * d) + (25 * q) + (100 * dol)) / 100;
    cout << "\nThe value of all your coins is $" << amount << endl;
}