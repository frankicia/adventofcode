#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>

#define SUM_TO_FIND 2020

int findDifference(std::unordered_set<int> set, int difference) {
    auto it = set.find(difference);
    if ( it != set.end() ) {
        return 1;
    }
    return 0;
}

std::pair<int,int> findPair(std::unordered_set<int> set, int difference, int number) {
    // difference is composed of 2 numbers
    for (auto it = set.begin(); it != set.end(); ++it) {
        if (*it + number > 2020)
            continue;
        int newDifference = abs(difference - *it);
        if (findDifference(set, newDifference) ) {
            return std::pair<int,int> (*it, newDifference);
        }
    }
    return std::pair<int,int> (0, 0);
}


int main() {
    int x;
    int difference;
    std::unordered_set<int> myNumbers;
    while (!std::cin.eof())
    {
        std::cin >> x;
        difference = abs(SUM_TO_FIND - x);
        //if (findDifference(myNumbers, difference) )
        //    printf("%i\n", difference*x);
        std::pair<int, int> result = findPair(myNumbers, difference, x);
        if (result.first != 0) {
            printf("numbers: %i %i %i = %i\n", x, result.first, result.second, x*result.first*result.second);
            exit(0);
        }
        myNumbers.insert(x);
    }
}