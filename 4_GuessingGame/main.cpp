#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);

    int secretNumber = distribution(gen)
    int guess;
    int attempts = 0;

    std::cout << " Number Guessing Game " << std::endl;
    std::cout << " I have chosen a number between 1 - 100. " << std::endl;
    std::cout << " Try to guess it " << std::endl;

    while (true) {
        std::cout << " Enter your guess: ";
        if (!(std::cin >> guess)) {
            std::cout << " Please enter a valid number. " << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;    
        }
        if (guess < 1 || guess > 100) {
            std::cout << " Your guess must be between 1 and 100. " << std::endl;
            continue;
        }
        attempts++;
        if (guess < secretNumber) {
            std::cout << " Too low"
        }
    }
}