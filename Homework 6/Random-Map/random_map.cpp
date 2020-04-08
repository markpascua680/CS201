/* random-map.cpp
   Jay-Mark Pascua
   CS 201
   04/04/2020
   Tests uniform distribution of numbers annd normal distribution of numbers
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
#include <random>
#include <cmath>

using namespace std;

int RandomBetweenU(int first, int last) { // Returns a uniform random number between first and last, inclusively

    return 0;
}

int RandomBetweenN(int first, int last) { // Returns a normally distributed random number between first and last, inclusively

    return 0;
}

int RandomBetween(int first, int last) { // Returns number using rand()

    return 0;
}

void PrintDistribution(const map<int, int>& numbers) { // Prints list of the random numbers 

}

int main()
{
    // Seed with a real random value, if available
    random_device r;

    // Choose a random mean between 1 and 6
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    cout << "Randomly chosen mean: " << mean << '\n';

    //Generate a normal distribution around that mean
    seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
    mt19937 e2(seed2);
    normal_distribution<> normal_dist(mean, 2);

    map<int, int> hist;
    for (int n = 0; n < 10000; n++)
    {
        ++hist[round(normal_dist(e2))];
    }

    cout << "Normal distribution around " << mean << ":\n";

    for (auto p : hist)
    {
        cout << fixed << setprecision(1) << setw(2) << p.first << ' ' << string(p.second / 200, '*') << '\n';
    }

    return 0;
}