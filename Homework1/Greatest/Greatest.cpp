/* Greatest.cpp
   Jay-Mark Pascua
   CS 201
   01/30/2020
   Outputs the greatest integer of a sequence of numbers
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int n; // User's integer input
    int max = 0; // The greatest integer

    cout << "Enter a sequence of positive integers. The greatest number will be printed.\n" << endl;

    while (true) // Gathers all integers
    {
        cout << "Enter a positive integer (0 to stop): " << endl;
        n = 0;
        cin >> n; 

        if (n == 0) // Stops loop
        {
            break;
        }

        if (n > max) // Stores the largest integer
        {
            max = n;
        }
    }

    cout << "\nThe greatest number entered: " << max;
    
    return 0;
}