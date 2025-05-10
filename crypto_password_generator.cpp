#include <iostream>
#include <string>
#include "password_utils.h"  // Include the header file for utility functions

int main() {
    int choice, length;
    bool running = true;
    std::string password;  // Declare outside the switch for broader scope

    while (running) {
        displayMenu();  // Function to display the menu
        std::cin >> choice;  // Get user choice

        // Switch statement for menu options
        switch (choice) {
            case 1:
                std::cout << "Enter the desired password length: ";
                std::cin >> length;

                // Generate password
                password = generatePassword(length);
                if (!password.empty()) {
                    std::cout << "Generated Password: " << password << std::endl;

                    // Write password to file
                    writePasswordToFile(password);
                }
                break;

            case 2:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                running = false;
                break;

            default:
                std::cout << "Invalid choice, please try again!" << std::endl;
                break;
        }
    }

    return 0;
}
