#include <iostream>
using std::cout;
using std::endl;

void main()
{
	int n = 0; // n = user's input

	while (n == n) // Test for postive number
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

	int row = 0; // Adds a # to each successive row

	int pound = 0; // Indicates how many #'s to output

	for (int i = 1; i <= n; i++) // Creates the rows of the diamond up to the width
	{
		
		for (pound = pound; pound >= 0; pound--)
		{
			cout << "#";
		}
		cout << endl;

		row++;
		pound = i + row;
		

		if (i == n) // Tests if the max width is met; n = rows until max width
		{
			row-=2; // Prevents program from reprinting the max width twice

			for (int i=n-1; i > 0; i--) // Creates the rows after the diamond's width
			{
				
				pound = i + row;
				for (pound = pound; pound > 0; pound--)
				{
					cout << "#";
				}
				cout << endl;
				row--;


			}
		}

	}


}