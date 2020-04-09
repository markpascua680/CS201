/* shopping.cpp
   Jay-Mark Pascua
   CS 201
   04/08/2020
   Represents online shopping
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <map>
#include <iterator>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using std::cout;
using std::endl;
using std::map;
using std::string;

struct Record
{
    double unitPrice;
    int units;
};

map<string, Record> items{ // Stores items; MUST BE ALPHABETIZED
    {"Apple", {0.75, 1}},
    {"Chocolate Bar", {1.75, 1}},
    {"Milk",  {8.50, 1}},
    {"Shampoo", {6.50, 1}},
    {"T-Shirt", {5.00, 1}}
};

void printItems(map<string, Record> items) { // Prints item options to screen
    map<string, Record>::iterator it = items.begin();
    cout << "Items for sale:" << endl;
    for (size_t i = 0; i < items.size(); i++) {
        cout << i+1 << ". " << it->first << ": " << '$' << std::fixed << std::setprecision(2) << it->second.unitPrice << endl;
        it++;
    }
}

void printCart(map<string, Record>& cart) { // Prints the items in user's cart
    if (cart.empty()) {
        cout << "\nYour cart is empty" << endl;
    }
    else
    cout << "\nItems currently in cart:" << endl;
    for (auto x : cart) {
        if (x.second.units == 1) {
            cout << x.first << ": " << x.second.units << " unit, $"
                << std::fixed << std::setprecision(2) << x.second.unitPrice << " each" << endl;
        } else
        cout << x.first << ": " << x.second.units << " units, $" 
            << std::fixed << std::setprecision(2) << x.second.unitPrice << " each" << endl;
    }
}

void printOptions() { // Displays user's options
    cout << "\nSelect an option:\n";
    cout << "Enter 1 to add item to cart" << endl;
    cout << "Enter 2 to remove item from cart" << endl;
    cout << "Enter 3 to view cart" << endl;
    cout << "Enter 4 to checkout to view total and exit" << endl;

    cout << "\nEnter the number of the option you wish to do: " << endl;
}

void formatInput(string& input) { // Formats user strings to have first letter capitalized only
    for (size_t i = 0; i < input.length(); i++) {
        input[i] = (tolower(input[i]));
    }
    input[0] = (toupper(input[0]));
}

void addItem(map<string, Record>& cart) { // Adds item to user's cart
    cout << "Which item do you want to add?\n" << endl;
    printItems(items);
    cout << "\nEnter the corresponding number of the item you wish to add: ";
    int addItem;
    std::cin >> addItem;

    if (addItem == 1) {
        cart.insert({ "Apple", {0.75} });
        cart["Apple"].units++;
        cout << "Apple was added to your cart." << endl;
    }
    else if (addItem == 2) {
        cart.insert({ "Chocolate Bar", {1.75} });
        cart["Chocolate Bar"].units++;
        cout << "Chocolate Bar was added to your cart." << endl;
    }
    else if (addItem == 3) {
        cart.insert({ "Milk",  {8.50} });
        cart["Milk"].units++;
        cout << "Milk was added to your cart." << endl;
    }
    else if (addItem == 4) {
        cart.insert({ "Shampoo", {6.50} });
        cart["Shampoo"].units++;
        cout << "Shampoo was added to your cart." << endl;
    }
    else if (addItem == 5) {
        cart.insert({ "T-Shirt", {5.00} });
        cart["T-Shirt"].units++;
        cout << "T-Shirt was added to your cart." << endl;
    }
    else
        cout << "Item not found or invalid number was entered" << endl;
}

void removeItem(map<string, Record>& cart) {
    printCart(cart);
    cout << "Which item do you want to remove?\nEnter the item name" << endl;
    string removeItem;
    std::cin >> removeItem;
    formatInput(removeItem);
    map<string, Record>::iterator it = cart.find(removeItem);
    if (it != cart.end())
    {
        cart[removeItem].units--;
        if (cart[removeItem].units == 0) {
            cart.erase(removeItem);
        }
        cout << "The item has been removed" << endl;
    }
    else
        cout << "Item not found or was entered incorrectly" << endl;
}

double totalPrice(map<string, Record>& cart) {
    double total = 0; // Total of current purchase
    std::vector<double> prices;
    for (auto x : cart) {
        prices.push_back((x.second.unitPrice) * (x.second.units));
    }
    total = std::accumulate(prices.begin(), prices.end(), total);
    return total;
}

int main() {
    cout << "~~~~~Welcome to Wal-Meyers~~~~~\n" << endl;
    map<string, Record> cart;

    printItems(items); // Prints list of items for sale
    printOptions();    // Prints list of option for user to select
    
    int stop = 0; // Stop user input loop
    char option;

    while (stop != 1) {
        std::cin >> option;
        if (option == '1')
        {
            addItem(cart);
        }
        if (option == '2')
        {
            if (cart.empty()) {
                printCart(cart);
                printOptions();
                continue;
            }
            removeItem(cart);
        }
        if (option == '3')
        {
            printCart(cart);
        }
        if (option == '4')
        {
            cout << "TOTAL OF PURCHASE: $" << std::fixed << std::setprecision(2) << totalPrice(cart);
            break;
        }
        if (option != '1' && option != '2' && option != '3' && option != '4')
        {
            cout << option << endl;
            cout << "Please enter a valid option" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        printOptions();
        
    }

    return 0;
}