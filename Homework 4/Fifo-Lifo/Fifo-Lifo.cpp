/* Fifo-Lifo.cpp
   Jay-Mark Pascua
   CS 201
   02/25/2020
   Demonstrates the principles of FIFO and LIFO
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::istringstream;
using std::string;
using std::vector;

// First In First Out
void FifoPush(vector<string>& container, const string& item);
void FifoPop(vector<string>& container, string& item);

// Last In Last Out
void LifoPush(vector<string>& container, const string& item);
void LifoPop(vector<string>& container, string& item);

// Shared Functionality
bool IsContainerEmpty(const vector<string>& container);
void PrintContainer(const vector<string>& container);   

int main()
{
    vector<string> container; // Container holding user's inputted items
    string option; // User's option to add or pop an item
    string item; // User's inputted items

    cout << "~~~~~~~~~~\"Inventory Tracker\"~~~~~~~~~~\n" << endl;
    cout << "Select an option (enter its number):\n";
    cout << "(1) Push item to FIFO container\n";
    cout << "(2) Pop item to FIFO container\n";
    cout << "(3) Push item to LIFO container\n";
    cout << "(4) Pop item to LIFO container\n" << endl;

    while (true)
    {
        getline(cin, option); // User's option input

        int num;
        istringstream opt(option); // Reads a digit from option
        opt >> num; // Ensures input is a single digit

        if (!opt || num > 4 || num < 1) // Error check
        {
            cout << "\nPlease enter an option 1-4" << endl;
        }

        if (num == 1)
        {

        }
        else if (num == 2)
        {

        }
        else if (num == 3)
        {

        }
        else if (num == 4)
        {

        }

    }


    

    
    return 0;
}