/* Lab28.cpp
   Jay-Mark Pascua
   CS 201
   04/15/2020
   Send output to a text file
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>


std::vector<int> numbers();
void printIntegersToFile(const std::vector<int>& integers, std::ofstream& output);


int main() {

    std::ofstream file("Hello.txt"); // Opens file 

    if (!file) { // Error message if file couldn't be opened
        std::cout << "ERROR: FILE COULD NOT BE OPENED" << std::endl;
    }
    else {
        
        for (int i = 0; i < 10; i++) { // Writes "Hello" 10 times in the .txt file
            file << "Hello" << std::endl;
        }
    }

    if (!file) { // Error message if unable to write to file
        std::cout << "Error writing in file" << std::endl;
    }

    std::ifstream file2("Hello.txt");
    if (!file)
        std::cout << "Error" << std::endl;

    else {

        while (true) {
            std::string word;

            if (!file2) {

                if (file2.eof()) {
                    std::cout << "End of file" << std::endl;
                }
                else
                    std::cout << "Error" << std::endl;
                break;
            }
            file2 >> word;
            std::cout << word << std::endl;
        }
    }
    return 0;
}