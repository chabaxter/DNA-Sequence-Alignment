/*
    Copyright
    PS5 - Edit Distance Algorithm
    Charles Baxter
    11/8/2021
    EDistance.h
    Header File for the EDistance object.
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class EDistance {
 public:
    EDistance(std::string ifirst, std::string isecond);
    ~EDistance();

    static int penalty(char a, char b);
    static int min(int a, int b, int c); //NOLINT
    int OptDistance();
    std::string stringAlignment();

    friend std::ostream& operator<<(std::ostream& out, const EDistance& e);
 private:
    unsigned dimX, dimY;
    std::string left, right;
    int** matrix;
    static const int gap = 2, mismatch = 1, match = 0;
};

