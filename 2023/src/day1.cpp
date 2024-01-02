#include "common.h"

#include <cctype>

int partOne () {
    std::vector<std::string> lines = readFromFile("input/day1.txt");
    std::vector<int> numbers;

    int firstNum;
    int lastNum;

    int total = 0;

    for (const auto& line : lines) {
        
        // two pointers
        int i = 0, j = line.length() - 1;

        int firstCharacter = -1, lastCharacter = -1;

        while (i <= j) {
            char iPointer = line.at(i);
            char jPointer = line.at(j);

            if (std::isdigit(iPointer) && firstCharacter == -1) {
                firstCharacter = digitToInt(iPointer);
            }
            else if (firstCharacter == -1) {
                i++;
            }

            if (std::isdigit(jPointer) && lastCharacter == -1) {
                lastCharacter = digitToInt(jPointer);
            }
            else if (lastCharacter == -1) {
                j--;
            }

            if (firstCharacter != -1 && lastCharacter != -1) {
                break;
            }
        }

        total += combineTwoNumbers(firstCharacter, lastCharacter);
    }
    
    return total;
}

int partTwo () {
    std::vector<std::string> lines = readFromFile("input/day1.txt");
    std::vector<int> numbers;

    int firstNum;
    int lastNum;

    int total = 0;

    for (const auto& line : lines) {
        
        // two pointers
        int i = 0, j = line.length() - 1;

        int firstCharacter = -1, lastCharacter = -1;

        while (i <= j) {
            char iPointer = line.at(i);
            char jPointer = line.at(j);

            if (std::isdigit(iPointer) && firstCharacter == -1) {
                firstCharacter = digitToInt(iPointer);
            }
            else {
                if (firstCharacter == -1) {
                    // check for substrings
                }
            }
            
            if (firstCharacter == -1) {
                i++;
            }

            if (std::isdigit(jPointer) && lastCharacter == -1) {
                lastCharacter = digitToInt(jPointer);
            }
            else if (lastCharacter == -1) {
                j--;
            }

            if (firstCharacter != -1 && lastCharacter != -1) {
                break;
            }
        }

        total += combineTwoNumbers(firstCharacter, lastCharacter);
    }
    
    return total;
}

int main ()
{
     std::cout << "Part 1: " + std::to_string(partOne()) << std::endl;
    std::cout << "Part 2: " + std::to_string(partTwo()) << std::endl;
}