#include "common.h"

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

std::vector<std::string> splitString(const std::string &s, const std::string &delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);
    while (end != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

std::string trim(const std::string &s) {
    return std::regex_replace(s, std::regex("^\\s+|\\s+$"), std::string(""));
}