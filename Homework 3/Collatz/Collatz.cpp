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
    int out; // Outputs integers from each iteration of Collatz sequence


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

    out = n;
    cout << out << " ";
    
    // COLLATZ SEQUENCE
    while (out != 1)
    {
        if (n % 2 == 0) // If n is even
        {
            n = n/2;
            out = n;
            cout << out << " ";
        }
        else if (n % 2 == 1) // If n is odd
        {
            n = 3 * n + 1;
            out = n;
            cout << out << " ";

            if (n == 1) // Stops sequence at n = 1
            {
                break;
            }
        }
    }
    

    return 0;
}