#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <string>
#include <map>
#include <regex>

#include <sstream>
#include <fstream>
#include <iostream>

#include <cctype>

std::vector<std::string> readFromFile(const std::string& filename);

/* DAY 1 UTILITY */

int digitToInt(char digit);
int combineTwoNumbers(int a, int b);

/* DAY 2 UTILITY */

const int RED_CUBES = 12;
const int BLUE_CUBES = 14;
const int GREEN_CUBES = 13;

std::vector<std::string> splitString(const std::string &s, const std::string &delimiter);
std::string trim(const std::string &s);

#endif // COMMON_H
