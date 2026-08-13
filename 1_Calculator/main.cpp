#include <iostream>

void showMenu() {
    std::cout << "\n===============================\n";
    std::cout << "      CONSOLE CALCULATOR       \n";
    std::cout << "===============================\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
    std::cout << "-------------------------------\n";
    std::cout << "Choose an option (1-5): ";
}

int main() {
    int choice;
    double num1, num2;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting Calculator. Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            std::cout << "Invalid selection! Please choose between 1 and 5.\n";
            continue;
        }

        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        switch (choice) {
            case 1:
                std::cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << "\n";
                break;
            case 2:
                std::cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << "\n";
                break;
            case 3:
                std::cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << "\n";
                break;
            case 4:
                if (num2 == 0) {
                    std::cout << "Error: Division by zero is undefined!\n";
                } else {
                    std::cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
                }
                break;
        }
    }

    return 0;
}