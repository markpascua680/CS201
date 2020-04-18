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
    
    std::vector<int> integers = numbers();
    int seed = 5;
    std::shuffle(integers.begin(), integers.end(), std::default_random_engine(5));

    printIntegersToFile(integers, file); 

    /*
    std::ifstream read("Hello.txt");

    if (!read) { // If file can't be opened
        std::cout << "Cannot open file" << std::endl;
    }
    else
    {
        std::cout << "Reading from file:" << std::endl;

        while (true) { // Reads the file
            std::string line;
            std::getline(read, line);
            if (!read) {
                if (read.eof()) {
                    std::cout << "Finished reading file" << std::endl;
                }
                else
                {
                    std::cout << "An error ocurred, GG" << std::endl;
                }
                break;
            }
            std::cout << line << std::endl;
        }
    }
    */
    return 0;
}

std::vector<int> numbers() {

    std::ofstream file("Hello.txt");

    std::vector<int> integers;

    for (int i = 1; i <= 100; i++) { 
        file << std::setw(4) << i;
        if (i % 10 == 0) {
            file << '\n';
        }
        integers.push_back(i);
    }
    return integers;
}

void printIntegersToFile(const std::vector<int>& integers, std::ofstream& output) {

    for (int i = 1; i <= 100; i++) {
        output << std::setw(4) << integers[i-1];
        if (i % 10 == 0) {
            output << '\n';
        }
    }
}