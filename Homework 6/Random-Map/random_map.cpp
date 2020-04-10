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
#include <time.h>

void PrintDistribution(const std::map<int, int>& numbers) { // Prints list of the random numbers 
    for (auto p : numbers)
    {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2) << p.first << ' ' << std::string(p.second / 200, '*') << '\n';
    }
}

int RandomBetweenU(int first, int last) { // Returns a uniform random number between first and last, inclusively
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> distrib(first, last);

    return distrib(r);
}

int RandomBetweenN(double first, double last) { // Returns a normally distributed random number between first and last, inclusively
    std::random_device r;
    std::default_random_engine e1(r());
    std::normal_distribution<double> distrib(first, last);

    return distrib(r);
}

int RandomBetween(int first, int last) { // Returns number using rand()
    std::srand(time(NULL));
    int rand = (std::rand() % last) + first;
    return rand;
}

int main()
{
    std::random_device r;
    std::uniform_int_distribution<int> distribU(1, 6);
    std::normal_distribution<double> distribN(1, 6);

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    std::cout << "Randomly chosen mean: " << mean << '\n';

    // Generate a normal distribution around that mean
    std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean, 2);

    std::cout << "RANDOM BETWEEN U GENERATED NUMBER: " << RandomBetweenU(1, 6) << std::endl;
    std::cout << "RANDOM BETWEEN N GENERATED NUMBER: " << RandomBetweenN(1, 6) << std::endl;
    std::cout << "RANDOM BETWEEN GENERATED NUMBER: " << RandomBetween(1, 6) << std::endl;
    
    std::srand(time(NULL));
    int rand = (std::rand() % 6) + 1;
    
    std::map<int, int> numbersU; 
    std::map<int, int> numbersN;
    std::map<int, int> numbersRAND;
    for (int n = 0; n < 10000; n++) // Makes map of uniform_int_distribution, normal_int_distribution, and rand()
    {
        ++numbersU[uniform_dist(r)];
        ++numbersN[normal_dist(r)];
        ++numbersRAND[rand];
    }

    std::cout << "RANDOM BETWEEN UNIFORM GENERATED HISTOGRAM: " << std::endl;
    PrintDistribution(numbersU);

    std::cout << "RANDOM BETWEEN NORMAL GENERATED HISTOGRAM: " << std::endl;
    PrintDistribution(numbersN);

    std::cout << "RAND() GENERATED HISTOGRAM: " << std::endl;
    PrintDistribution(numbersRAND);

    return 0;
}