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
	for (int i = 0; i < 10; i++)
	{
		string name;
		cout << "Please enter a name: ";
		std::getline(cin, name);
		names.push_back(name);
	}



	return 0;
}