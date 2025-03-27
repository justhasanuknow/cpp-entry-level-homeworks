#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

struct Account {
  std::string account_name;
  double account_balance;
};

void create_account(std::vector<Account> *);
void transfer_money();
void view_account_transactions(std::vector<Account> *);
void exit_program();

int main() {
  std::vector<Account> *account_db = new std::vector<Account>;
  int option{0};

  std::cout << "\nWelcome to Simple Bank Management System\n\n"
            << "1. Create Account" << "\n"
            << "2. Transfer Money" << "\n"
            << "3. View Account Transactions" << "\n"
            << "4. Exit" << "\n";

  std::cout << "Choose an option: ";
  std::cin >> option;
  std::cout << "\n";

  if (std::cin.fail()) {
    std::cout << "Invalid input! Not a number." << std::endl;

    return 1;
  }

  if (option == 4) {
    exit_program();

    return 0;
  }

  switch (option) {
  // Create account.
  case 1:
    create_account(account_db);
    break;

  // Transfer money.
  case 2:
    transfer_money();
    break;

  // View account transactions.
  case 3:
    view_account_transactions(account_db);
    break;

    // Invalid option.
  default:
    std::cout << "Please enter a valid option!" << "\n";
    break;
  }

  return 0;
}

void create_account(std::vector<Account> *account_db) {
  // std::cout << "Create account!" << std::endl;
  std::string account_name{""};
  double initial_balance{0};

  std::cout << "Please enter account name:";
  std::cin >> account_name;
  std::cout << "Please enter initial balance:";
  std::cin >> initial_balance;

  Account new_account;
  new_account.account_name = account_name;
  new_account.account_balance = initial_balance;

  (*account_db).push_back(new_account);

  std::cout << std::endl
            << "Account successfully created!\n";
}

void transfer_money() {
  std::cout << "Transfer Money!" << std::endl;
}

void view_account_transactions(std::vector<Account> *account_db) {
  std::cout << "View account transactions!" << std::endl;
  for (size_t i = 0; i < (*account_db).size(); i++) {
    std::cout << (*account_db).at(i).account_name << std::endl;
  }
}

void exit_program() {
  std::cout << "\nThank you for using our program. Goodbye..." << std::endl;
}
