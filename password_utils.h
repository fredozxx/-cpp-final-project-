#ifndef PASSWORD_UTILS_H
#define PASSWORD_UTILS_H

#include <string>

std::string generatePassword(int length);
void writePasswordToFile(const std::string &password);
void displayMenu();
bool isValidLength(int length);
void generateRandomPassword(char password[], int length);

#endif
