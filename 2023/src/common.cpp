#include "common.h"
#include <fstream>
#include <iostream>

#include <cctype>

std::vector<std::string> readFromFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return lines;
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

int digitToInt(char digit)
{
    return digit - '0';
}

int combineTwoNumbers(int a, int b)
{
    int times = 1;
    while (times <= b)
        times *= 10;

    return a*times + b;
}