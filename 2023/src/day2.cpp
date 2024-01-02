#include "common.h"

int partOne()
{
    std::vector<std::string> lines = readFromFile("input/day2.txt");

    int total = 0;

    for (const auto& line : lines) {

        bool gameWorks = true;

        std::vector<std::string> split = splitString(line, ": ");
        
        std::vector<std::string> gameInfo = splitString(split[0], " ");
        int gameNumber = std::stoi(gameInfo[1]);

        std::vector<std::string> rounds = splitString(split[1], "; ");

        for (const auto& round : rounds) {
            std::vector<std::string> colors = splitString(round, ", ");

            for (const auto& color: colors) {
                std::vector<std::string> quantity = splitString(color, " ");
                int quant = std::stoi(quantity[0]);
                std::string colorOfCube = quantity[1];

                if (colorOfCube == "red") {
                    if (quant > RED_CUBES) {
                        gameWorks = false;
                    }
                }
                else if (colorOfCube == "green") {
                    if (quant > GREEN_CUBES) {
                        gameWorks = false;
                    }
                }

                else {
                    if (quant > BLUE_CUBES) {
                        gameWorks = false;
                    }
                }
            }
        }

        if (gameWorks) {
            total += gameNumber;
        }
    }

    return total;
}

int partTwo()
{
    std::vector<std::string> lines = readFromFile("input/day2.txt");

    int total = 0;

    for (const auto& line : lines) {
        
        bool gameWorks = true;

        int minRed = 0, minGreen = 0, minBlue = 0;

        std::vector<std::string> split = splitString(line, ": ");
        
        std::vector<std::string> gameInfo = splitString(split[0], " ");
        int gameNumber = std::stoi(gameInfo[1]);

        std::vector<std::string> rounds = splitString(split[1], "; ");

        for (const auto& round : rounds) {
            std::vector<std::string> colors = splitString(round, ", ");

            for (const auto& color: colors) {
                std::vector<std::string> quantity = splitString(color, " ");
                int quant = std::stoi(quantity[0]);
                std::string colorOfCube = quantity[1];

                if (colorOfCube == "red") {
                    if (quant > minRed) {
                        minRed = quant;
                    }
                }
                else if (colorOfCube == "green") {
                    if (quant > minGreen) {
                        minGreen = quant;
                    }
                }
                else {
                    if (quant > minBlue) {
                        minBlue = quant;
                    }
                }
            }
        }

        total += (minGreen * minRed * minBlue);
    }

    return total;
}

int main()
{
    std::cout << "Part one: " + std::to_string(partOne()) << std::endl;
    std::cout << "Part two: " + std::to_string(partTwo()) << std::endl;
}

// g++ -o day2 src/day2.cpp src/common.cpp -Iinclude -std=c++17