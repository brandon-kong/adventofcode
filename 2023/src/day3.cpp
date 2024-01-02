#include "common.h"

int partOne()
{
    std::vector<std::string> lines = readFromFile("input/day3.txt");
    int line_len = lines.at(0).length();

    int numRows = lines.size();
    int numCols = lines[0].size();

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int total = 0;

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            if (std::isdigit(lines[row][col]) && (col == 0 || !std::isdigit(lines[row][col - 1]))) {
                std::string number;
                int startCol = col;
                int endCol;

                for (endCol = col; endCol < numCols && std::isdigit(lines[row][endCol]); ++endCol) {
                    number += lines[row][endCol];
                }

                // Check adjacent characters

                bool added = false;
                for (int i = startCol; i < endCol && !added; i++) {
                    for (int j = 0; j < 8; j++) {
                        int newRow = row + dx[j];
                        int newCol = i + dy[j];

                        if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols) {
                            char adjacentChar = lines[newRow][newCol];

                            if (adjacentChar != '.' && !std::isdigit(adjacentChar)) {
                                total += std::stoi(number);
                                added = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return total;
}

int main()
{
    std::cout << "Part one: " + std::to_string(partOne()) << std::endl;

    return 0;
}

// g++ -o day3 src/day3.cpp src/common.cpp -Iinclude -std=c++17