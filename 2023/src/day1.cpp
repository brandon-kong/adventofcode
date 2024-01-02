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

    std::map<std::string, int> numAsWord;

    numAsWord["one"] = 1;
    numAsWord["two"] = 2;
    numAsWord["three"] = 3;
    numAsWord["four"] = 4;
    numAsWord["five"] = 5;
    numAsWord["six"] = 6;
    numAsWord["seven"] = 7;
    numAsWord["eight"] = 8;
    numAsWord["nine"] = 9;
    numAsWord["zero"] = 0;

    for (const auto& line : lines) {
        
        // two pointers
        int size = line.length();
        int i = 0, j = size - 1;

        int firstCharacter = -1, lastCharacter = -1;

        while (i < size && j >= 0) {
            char iPointer = line.at(i);
            char jPointer = line.at(j);

            if (firstCharacter == -1) {
                if (std::isdigit(iPointer)) {
                    firstCharacter = digitToInt(iPointer);
                }
                else {
                    // check for substrings

                    for ( const auto &[key, value]: numAsWord ) {
                        int wordLen = i + key.length();
                        if (wordLen < size) {
                            if (line.substr(i, key.length()) == key) {
                                firstCharacter = value;
                                break;
                            }
                        }
                    }
                }
                if (firstCharacter == -1) {
                    i++;
                }
            }
            
            

            if (lastCharacter == -1) {
                if (std::isdigit(jPointer)) {
                    lastCharacter = digitToInt(jPointer);
                }
                else {
                    // check for substrings

                    for ( const auto &[key, value]: numAsWord ) {
                        if (j + key.length() <= size) {
                            if (line.substr(j, key.length()) == key) {
                                //std::cout << key << std::endl;
                                lastCharacter = value;
                                break;
                            }
                        }
                    }
                }
                
                if (lastCharacter == -1) {
                    j--;
                }
            }

            

            if (firstCharacter != -1 && lastCharacter != -1) {
                break;
            }
        }

        int b =  combineTwoNumbers(firstCharacter, lastCharacter);
        total += b;
    }
    
    return total;
}

int main ()
{
    std::cout << "Part 1: " + std::to_string(partOne()) << std::endl;
    std::cout << "Part 2: " + std::to_string(partTwo()) << std::endl;
}