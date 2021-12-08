/*
    Copyright
    PS5 - Edit Distance Algorithm
    Charles Baxter
    11/8/2021
    main.cpp
    This is the driver for PS5. It times the compute time for the algorithm
    and creates the algorithm object based on the directed input file.
*/

#include <iostream>
#include <string>
#include <chrono> //NOLINT

#include "EDistance.h"

int main(int argc, char* argv[]) {
    auto start = std::chrono::high_resolution_clock::now();

    auto getStr = []()->std::string {
        std::string out;
        std::cin >> out;
        return out;
    };

    EDistance e(getStr(), getStr());

    int edit = e.OptDistance();

    std::cout << "Edit Distance = " << edit << std::endl;

    //  std::cout << e;

    std::cout << e.stringAlignment() << std::endl;

    std::cout << "Edit Distance = " << edit << std::endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast
        <std::chrono::milliseconds>(stop - start);

    std::cout << "Execution time is " << duration.count()
        << " milliseconds" << std::endl;

    std::getchar();

    return 0;
}
