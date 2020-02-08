#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

void InputNames(vector<string>& names);

bool DoesNameExist(const string& nameToFind, const vector<string> names);

void PrintNames(const vector<string>& names);



int main(int argc, char** argv)
{
	vector<string> names;
	string nameToFind;
	
	InputNames(names);

	cout << "Search for a name: ";
	cin >> nameToFind;
	DoesNameExist(nameToFind, names);

	PrintNames(names);

	

	return 0;
}



void InputNames(vector<string>& names)
{
	for (int i = 0; i < 10; i++)
	{
		string name;
		cout << "Please enter a name: ";
		std::getline(cin, name);
		names.push_back(name);
	}
	cout << "\n" << endl;
}



void PrintNames(const vector<string>& names)
{
	cout << "Names listed: " << endl;

	for (int i = 0; i < 10; i++)     // Prints the list of names
	{
		cout << names[i] << " ";
	}

	cout << "\nName with the highest amount of letters: " << endl;
}



bool DoesNameExist(const string& nameToFind, const vector<string> names)
{
	for (int i = 0; i < 10; i++)
	{
		if (nameToFind == names[i])
		{
			cout << "Name found at sector " << i << ": " << names[i] << "\n" << endl;
			return true;
		}
	}
	
	cout << "Name does not exist.\n" << endl;
	return false;
}