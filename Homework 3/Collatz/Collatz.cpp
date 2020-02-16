/* Jay-Mark Pascua
   CS 201
   02/16/2020
   Takes in user's integer and plugs it into the Collatz sequence until 1 is reached
*/
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int n; // User's input


    cout << "Enter a nonzero positive integer: ";
    cin >> n;

    if (n < 1) // Zero and negative number detector
    {
        while (n < 1)
        {
            cout << "Please enter a nonzero positive integer: ";
            cin >> n;
        }
    }

    return 0;
}