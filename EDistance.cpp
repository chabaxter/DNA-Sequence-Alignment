/*
    Copyright
    PS5 - Edit Distance Algorithm
    Charles Baxter
    11/8/2021
    EDistance.cpp
    Impliments the functionality of the EDistacne object.
*/

#include "EDistance.h"

EDistance::EDistance(std::string ifirst, std::string isecond)
    : dimX(ifirst.size() + 1), dimY(isecond.size() + 1),
    left(isecond), right(ifirst) {
    matrix = new int*[dimY];
    for (unsigned i = 0; i < dimY; i++)
        matrix[i] = new int[dimX];
}

EDistance::~EDistance() {
    for (uint16_t i = 0; i < dimY; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int EDistance::penalty(char a, char b) {
    if (a == '-' || b == '-')
        return 2;
    return static_cast<int>(a != b);
}

int EDistance::min(int a, int b, int c) { //NOLINT
    int min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    return min;
}

int EDistance::OptDistance() {
    // Initialize the outer-edge of the matrix
    for (unsigned i = 0; i < dimY; i++) {
        matrix[i][dimX - 1] = (dimY - 1 - i) * 2;
    }
    for (unsigned i = 0; i < dimX - 1; i++) {
        matrix[dimY - 1][i] = (dimX - 1 - i) * 2;
    }

    // Compute each cell starting at matrix[M-1][N-1]
    for (int i = static_cast<int>(dimY) - 2; i >= 0; i--) {
        for (int j = static_cast<int>(dimX) - 2; j >= 0; j--) {
            matrix[i][j] = EDistance::min(
                // Moving up or left would cause a gap to be created
                matrix[i + 1][j] + gap,
                matrix[i][j + 1] + gap,
                // If moving diagonally, we must check if there is a match
                matrix[i + 1][j + 1] + penalty(left[i], right[j])
            ); //NOLINT
        }
    }

    // matrix[0][0] is now the minimum distance as a numerical value
    return matrix[0][0];
}

std::string EDistance::stringAlignment() {
    unsigned x = 0, y = 0;
    int m;
    std::string outLeft, outRight, returnStr;
    while (x < dimX - 1 && y < dimY - 1) {
        if (right[x] == left[y]) {
            outLeft += left[y];
            outRight += right[x];
            x++;
            y++;
        } else {
            m = EDistance::min(
                matrix[y][x + 1],
                matrix[y + 1][x + 1],
                matrix[y + 1][x]
            ); //NOLINT
            if (matrix[y][x + 1] == m) {
                outLeft += '-';
                outRight += right[x];
                x++;
            } else if (matrix[y + 1][x + 1] == m) {
                outLeft += left[y];
                outRight += right[x];
                x++;
                y++;
            } else {
                outLeft += left[y];
                outRight += '-';
                y++;
            }
        }
    }

    //  Check if either edge has been reached: traverse that edge
    while (x < dimX - 1) {
        outLeft += '-';
        outRight += right[x];
        x++;
    } while (y < dimY - 1) {
        outLeft += left[y];
        outRight += '-';
        y++;
    }

    //  After gap insertions, both output strings should be the same size
    for (uint16_t i = 0; i < outLeft.size(); i++) {
        returnStr += outLeft[i];
        returnStr += ' ';
        returnStr += outRight[i];
        returnStr += ' ';
        if (outLeft[i] == '-' || outRight[i] == '-')
            returnStr += std::to_string(gap);
        else
            returnStr += std::to_string(penalty(outLeft[i], outRight[i]));
        returnStr += "\n";
    }

    return returnStr;
}

std::ostream& operator<<(std::ostream& out, const EDistance& e) {
    for (unsigned i = 0; i < e.dimY + 1; i++) {
        for (unsigned j = 0; j < e.dimX + 1; j++) {
            out << std::setw(3);
            if (i == 0 && j == 0) {
                out << "~";
            } else if (i == 0) {
                if (j == e.dimX)
                    out << "~";
                else
                    out << e.right[j - 1];
            } else if (j == 0) {
                if (i == e.dimY)
                    out << "~";
                else
                    out << e.left[i - 1];
            } else {
                out << e.matrix[i - 1][j - 1];
            }
        }
        out << std::endl;
    }
    return out;
}
