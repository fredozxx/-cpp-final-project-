#include "password_utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

// Function to generate a password
std::string generatePassword(int length) {
    if (!isValidLength(length)) {
        std::cerr << "Invalid password length. Length must be greater than 0." << std::endl;
        return "";
    }

    // Create a password array
    char password[length];
    generateRandomPassword(password, length);
    return std::string(password);
}

// Function to write password to a file
void writePasswordToFile(const std::string &password) {
    std::ofstream outFile("password.txt");
    if (outFile.is_open()) {
        outFile << password;
        outFile.close();
        std::cout << "Password saved to 'password.txt'." << std::endl;
    } else {
        std::cerr << "Error opening file to save password." << std::endl;
    }
}

// Display menu to user
void displayMenu() {
    std::cout << "\n=== Crypto Password Generator ===\n";
    std::cout << "1. Generate Strong Password\n";
    std::cout << "2. Exit\n";
    std::cout << "Choose an option: ";
}

// Check if the length is valid
bool isValidLength(int length) {
    return length > 0;
}

// Function to generate random password
void generateRandomPassword(char password[], int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+";
    srand(time(0));  // seed for randomness

    for (int i = 0; i < length; ++i) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length] = '\0';  // Null-terminate the password string
}
