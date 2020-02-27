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
    vector<string> fifo; // FIFO container holding user's inputted items
    vector<string> lifo; // LIFO container holding user's inputted items
    string option; // User's option to add or pop an item
    string item; // User's inputted items
    int num = 0; // Detects if user inputs a single digit for the options choice

    cout << "~~~~~~~~~~\"Inventory Tracker\"~~~~~~~~~~\n" << endl;
    cout << "Select an option (enter its number):\n";
    cout << "(1) Push item to FIFO container\n";
    cout << "(2) Pop item to FIFO container\n";
    cout << "(3) Push item to LIFO container\n";
    cout << "(4) Pop item to LIFO container\n";
    cout << "(5) Close program\n" << endl;

    while (num != 5)
    {
        getline(cin, option); // User's option input

        istringstream opt(option); // Reads a digit from option
        opt >> num; // Ensures input is a single digit

        if (!opt || num > 5 || num < 1) // Error check
        {
            cout << "\nPlease enter an option 1-4" << endl;
        }

        if (num == 1)
        {
            cout << "Enter an item to push: ";
            getline(cin, item);
            FifoPush(fifo, item);
        }
        else if (num == 2)
        {
            item = "";
            FifoPop(fifo, item);
        }
        else if (num == 3)
        {

        }
        else if (num == 4)
        {

        }
        cout << "\nSelect another option (enter its number):\n";
    } 

    cout << "\nHave a good day!";

    return 0;
}

/////////////////////////////////////////////////////////////////////
////////////////////FIRST IN FIRST OUT FUNCTIONS////////////////////
void FifoPush(vector<string>& container, const string& item) // Pushes an item into the FIFO container
{
    container.push_back(item);

    cout << "\nItems in FIFO container:" << endl;
    for (auto i : container) // Prints all elements in FIFO container
    {
        cout << "|"; // Item dividers for output neatness
        cout << i << "|";
    }
    cout << "\n";
}


void FifoPop(vector<string>& container, string& item) // Pops the item that was first in from FIFO container
{
    if (IsContainerEmpty(container) == true)
    {
        vector<string> temp(container.size() - 1); // Creates temp vector to hold elements from container vector
        for (int i = 1; i < container.size(); i++) // Pops the first element from FIFO container
        {
            temp[i - 1] = container[i];
        }
        container = temp; // Sets FIFO container its first element popped
        for (auto i : container) // Prints all elements in FIFO container
        {
            cout << "|"; // Item dividers for output neatness
            cout << i << "|";
        }
        cout << "\n";
    }
    else if (IsContainerEmpty(container) == false)
    {
        cout << "There are no items in this container. Please place some.\n\n";
    }
}
////////////////////////////////////////////////////////////////////
////////////////////LAST IN FIRST OUT FUNCTIONS////////////////////
void LifoPush(vector<string>& container, const string& item) // Pushes an item into the LIFO container
{

}


void LifoPop(vector<string>& container, string& item) // Pops the item that was last in from the LIFO container
{

}
///////////////////////////////////////////////////////////////////
///////////////////////SHARED FUNCTIONALITY///////////////////////
bool IsContainerEmpty(const vector<string>& container)
{
    if (container.size() > 0)
        return true;
    return false;
}


void PrintContainer(const vector<string>& container)
{

}