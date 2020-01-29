#include <iostream>
using std::cout;
using std::endl;

void main()
{
	int n = 0; // n = user's input

	while (n==n) // Test for postive number
	{
		cout << "Enter a positive number: ";
		std::cin >> n;
		if (n < 0)
			cout << "That is not a positive number!\n" << endl;
		else if (n == 0)
			cout << "The number cannot be 0.\n" << endl;
		else
			break;
	}

	int row = 0;
	for (int i=1; i <= n; i++)
	{	
		
		cout << i + row << endl;
		row++;

	}


}