/* Jay-Mark Pascua
   CS 201
   02/10/2020
   User stores name and value pairs that they can interact with
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

vector<string> names;
vector<string> scores;

void namesNumbers();
void selectOption();
void printNamesScores();
int searchName();
int searchScore();

int option; // The option chosen by user
int flag = 0;   // Stops while loop in namesNumbers

int main()
{
    cout << "Enter NoName and 0 to stop\n" << endl;
    namesNumbers();
    selectOption();


    return 0;
}





void namesNumbers()
{
    while (flag == 0)
    {
        string name;
        string num;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter score: ";
        cin >> num;

        if (names.size() >= 1) // Checks if names vector has more than one name
        {
            for (int i = 0; i < names.size(); i++) // Stops program if a name is entered twice
            {
                if (name == names[i])
                {
                    cout << "ERROR: Name was entered twice!" << endl;
                    flag = 1;
                }

            }
        }

        if (flag == 1)
        {
            break;
        }
        
        cout << "\n";


        if (name == "NoName" && num == "0") // Stops program
        {
            flag = 1;
        }
        else
        {
            names.push_back(name);
            scores.push_back(num);
        }
        
    }
    
}





void selectOption()
{
    cout << "To add names and scores, enter 1." << endl;
    cout << "To print the names and scores, enter 2." << endl;
    cout << "To search for a name, enter 3." << endl;
    cout << "To search for a score, enter 4." << endl;
    cin >> option;

    if (option == 1)
    {
        flag == 0;
        cout << "\n" << endl;
        namesNumbers();
    }
    else if (option == 2)
    {
        cout << "\n" << endl;
        printNamesScores();
    }
    else if (option == 3)
    {
        cout << "\n" << endl;
        searchName();
    }
    else if (option == 4)
    {
        cout << "\n" << endl;
        searchScore();
    }
    else
        cout << "Invalid number" << endl;
}





void printNamesScores()
{
    cout << "List of names and scores:" << endl;
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << " ";
        cout << scores[i];
        cout << endl;
    }
}





int searchName()
{
    string name;

    cout << "Search for a name: " << endl; // Search vector names for a name
    cin >> name;

    for (int i = 0; i < names.size(); i++)
    {
        if (name == names[i])
        {
            cout << name << "'s score is: " << scores[i] << endl;
            return 0;
        }
    }
    cout << "Name not found." << endl;
}





int searchScore()
{
    return 0;
}