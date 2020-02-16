/* Jay-Mark Pascua
   CS 201
   02/16/2020
   Takes in user's integer and plugs it into the Collatz sequence until 1 is reached
*/
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

/* 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% BROKEN KELVIN CODE %%
%%%%%%%%%%%%%%%%%%%%%%%%
// Converts Celsius to Kelvin
double ctok(double c)     <--- Function prototype is undeclared
{
    int k = c + 273.15;   <--- Data can be lost from data to int conversion
    return int;           <--- Function cannot return int if function is a double
}

int main()
{
    double c = 0;
    cin >> d;             <--- Variable d is undeclared
    double k = ctok("c"); <--- Quotations shouldn't be used for int
    Cout << k << '\n';    <--- Quotations should be used for escape characters, and
}                              cout shouldn't be capitalized
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

double ctok(double c);

double ctok(double c)
{
    double k = c + 273.15;
    return k;
}

int main()
{
    double c = 0;
    cin >> c;
    double k = ctok(c);
    cout << k << "\n";
}