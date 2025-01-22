#include <iostream>
#include <string>
using namespace std;

// Encapsulation: Wrapping data and methods that operate on the data into a single class.
class Account {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor to initialize account details
    Account(string name, int number, double initialBalance)
        : accountHolderName(name), accountNumber(number), balance(initialBalance) {}

    // Public method to access private data (Getter)
    double getBalance() {
        return balance;
    }

    // Public method to modify private data safely (Setter)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    void displayAccountDetails() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Inheritance: Deriving new classes from an existing class.
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string name, int number, double initialBalance, double rate)
        : Account(name, number, initialBalance), interestRate(rate) {}

    // Method specific to SavingsAccount
    void applyInterest() {
        double interest = getBalance() * (interestRate / 100);
        deposit(interest); // Reusing base class method (Polymorphism)
        cout << "Interest applied at rate " << interestRate << "%: " << interest << endl;
    }
};

// Polymorphism: Ability to redefine methods in derived classes.
class CurrentAccount : public Account {
public:
    CurrentAccount(string name, int number, double initialBalance)
        : Account(name, number, initialBalance) {}

    void withdraw(double amount) {
        // Overriding base class method
        cout << "CurrentAccount Withdrawal Processing..." << endl;
        Account::withdraw(amount); // Optionally use base class method
    }
};

int main() {
    // Abstraction: Using the class to hide implementation details and work with objects.
    SavingsAccount savings("John Doe", 101, 5000, 5); // Create a SavingsAccount object
    CurrentAccount current("Jane Smith", 102, 3000);  // Create a CurrentAccount object

    // Demonstrating functionality
    savings.displayAccountDetails();
    savings.deposit(2000);
    savings.applyInterest();

    cout << "\n";

    current.displayAccountDetails();
    current.withdraw(1000);
    current.withdraw(2500); // Trying to withdraw more than balance

    return 0;
}
