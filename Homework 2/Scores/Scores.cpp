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

int main()
{
    
    cout << "Enter NoName and 0 to stop\n" << endl;
    namesNumbers();



    return 0;
}

void namesNumbers()
{
    int flag = 0;   // Stops while loop in namesNumbers
    while (flag == 0)
    {
        string name;
        string num;

        cout << "Enter name: ";
        cin >> name;

        if (names.size() >= 1)
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

        cout << "Enter score: ";
        cin >> num;
        
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

    /* cout << "List of names and scores:" << endl;

    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << " ";
        cout << scores[i];
        cout << endl;
     */
}