#include <iostream>
#include <string>
#include <iomanip>

class BankAccount {
private:
    std::string ownerName;
    double balance;

public:
    BankAccount(std::string name, double initialBalance) {
        ownerName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "That's not a valid amount, try again.\n";
            return;
        }
        balance += amount;
        std::cout << "Deposited $" << std::fixed << std::setprecision(2) << amount << " successfully.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "That's not a valid amount, try again.\n";
            return;
        }
        if (amount > balance) {
            std::cout << "Not enough funds. You only have $" << std::fixed << std::setprecision(2) << balance << "\n";
            return;
        }
        balance -= amount;
        std::cout << "Withdrew $" << std::fixed << std::setprecision(2) << amount << " successfully.\n";
    }

    void displayBalance() const {
        std::cout << ownerName << "'s balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }

    std::string getOwnerName() const {
        return ownerName;
    }
};

void printMenu() {
    std::cout << "\n1. Check balance\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Quit\n";
    std::cout << "Pick an option: ";
}

int main() {
    std::string name;
    std::cout << "What's your name? ";
    std::getline(std::cin, name);

    // giving everyone a small starting bonus for now
    BankAccount account(name, 100.0);
    std::cout << "\nHey " << name << ", your account is set up with a $100 starting balance.\n";

    int choice;
    double amount;

    while (true) {
        printMenu();

        if (!(std::cin >> choice)) {
            // user typed something that wasn't a number, clear the error and skip
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Numbers only please.\n";
            continue;
        }

        switch (choice) {
            case 1:
                account.displayBalance();
                break;

            case 2:
                std::cout << "How much do you want to deposit? $";
                std::cin >> amount;
                account.deposit(amount);
                break;

            case 3:
                std::cout << "How much do you want to withdraw? $";
                std::cin >> amount;
                account.withdraw(amount);
                break;

            case 4:
                std::cout << "Thanks for stopping by, " << account.getOwnerName() << "!\n";
                return 0;

            default:
                std::cout << "Not a valid option, pick 1-4.\n";
        }
    }
}