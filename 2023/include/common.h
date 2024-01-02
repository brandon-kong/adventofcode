#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <string>
#include <map>

#include <fstream>
#include <iostream>

#include <cctype>

std::vector<std::string> readFromFile(const std::string& filename);

int digitToInt(char digit);
int combineTwoNumbers(int a, int b);

#endif // COMMON_H
