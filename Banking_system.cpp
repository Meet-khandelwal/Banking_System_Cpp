#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Account {
    int id;
    string name;
    double balance;
};

unordered_map<int, Account> accounts;
int nextAccountId = 1001;

void createAccount() {
    Account acc;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, acc.name);
    acc.id = nextAccountId++;
    acc.balance = 0.0;
    accounts[acc.id] = acc;
    cout << "Account created! Account ID: " << acc.id << "\n\n";
}

void viewAccount() {
    int id;
    cout << "Enter Account ID: ";
    cin >> id;

    if (accounts.count(id)) {
        Account& acc = accounts[id];
        cout << "\n--- Account Details ---\n";
        cout << "Name   : " << acc.name << "\n";
        cout << "ID     : " << acc.id << "\n";
        cout << "Balance: $" << acc.balance << "\n\n";
    } else {
        cout << "Account not found.\n\n";
    }
}

void depositMoney() {
    int id;
    double amount;
    cout << "Enter Account ID: ";
    cin >> id;

    if (accounts.count(id)) {
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount.\n\n";
            return;
        }
        accounts[id].balance += amount;
        cout << "Deposited successfully. New balance: $" << accounts[id].balance << "\n\n";
    } else {
        cout << "Account not found.\n\n";
    }
}

void withdrawMoney() {
    int id;
    double amount;
    cout << "Enter Account ID: ";
    cin >> id;

    if (accounts.count(id)) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= 0 || amount > accounts[id].balance) {
            cout << "Invalid amount or insufficient balance.\n\n";
            return;
        }
        accounts[id].balance -= amount;
        cout << "Withdrawal successful. New balance: $" << accounts[id].balance << "\n\n";
    } else {
        cout << "Account not found.\n\n";
    }
}

void deleteAccount() {
    int id;
    cout << "Enter Account ID to delete: ";
    cin >> id;

    if (accounts.count(id)) {
        accounts.erase(id);
        cout << "Account deleted successfully.\n\n";
    } else {
        cout << "Account not found.\n\n";
    }
}

void menu() {
    cout << "====== BANKING SYSTEM ======\n";
    cout << "1. Create Account\n";
    cout << "2. View Account\n";
    cout << "3. Deposit Money\n";
    cout << "4. Withdraw Money\n";
    cout << "5. Delete Account\n";
    cout << "6. Exit\n";
    cout << "============================\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    while (true) {
        menu();
        cin >> choice;
        cout << "\n";
        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccount(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: deleteAccount(); break;
            case 6: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n\n";
        }
    }
}
