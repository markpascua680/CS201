/* shopping.cpp
   Jay-Mark Pascua
   CS 201
   04/08/2020
   Represents online shopping
*/

#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;

struct Record
{
    double unitPrice;
    int units;
};

std::map<std::string, Record> items{ // Stores items
    {"Apple", {0.75, 1}},
    {"Milk",  {8.50, 1}},
    {"Shampoo", {6.50, 1}},
    {"Chocolate Bar", {1.75, 1}},
    {"T-Shirt", {5.00, 1}}
};

void printItems(std::map<std::string, Record> items) { // Prints item options to screen
    std::map<std::string, Record>::iterator it = items.begin();
    cout << "Items for sale:" << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << i+1 << ". " << it->first << ": " << '$' << it->second.unitPrice << endl;
        it++;
    }
}

int selectOption() { // Displays user's options
    cout << "\nSelect an option:\n";
    cout << "Enter 1 to add item to cart" << endl;
    cout << "Enter 2 to remove item from cart" << endl;
    cout << "Enter 3 to view cart" << endl;
    cout << "Enter 4 to view total and checkout" << endl;
    
    int opt = 0; // User's option
    while (opt != 1 && opt != 2 && opt != 3 && opt != 4) {
        std::cin >> opt;
    }
    return opt;
}

void main() {
    cout << "~~~~~Welcome to Wal-Meyers~~~~~\n" << endl;
    printItems(items);
    selectOption();
}