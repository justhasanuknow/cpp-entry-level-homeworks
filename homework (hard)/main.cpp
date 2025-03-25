#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

struct Account {
  std::string account_name;
  double account_balance;
  bool is_account_active;
};

void create_account();
void transfer_money();
void view_account_transactions();

void exit_program();

int main() {
  fs::create_directories("accounts");

  while (true) {
    int option{0};

    std::cout << "\n"
              << "Welcome to Simple Bank Management System" << "\n"
              << "\n";
    std::cout << "1. Create Account" << "\n";
    std::cout << "2. Transfer Money" << "\n";
    std::cout << "3. View Account Transactions" << "\n";
    std::cout << "4. Exit" << "\n";

    std::cout << "Choose an option: ";
    std::cin >> option;
    std::cout << "\n";

    if (option == 4)
      break;

    switch (option) {
    // Create account.
    case 1:
      create_account();
      break;

    // Transfer money.
    case 2:
      transfer_money();
      break;

    // View account transactions.
    case 3:
      view_account_transactions();
      break;

    // Invalid option.
    default:
      std::cout << "Please enter a valid option!" << "\n";
      break;
    }
  }

  exit_program();
  return 0;
}

void create_account() {
  std::string account_name{""};
  double initial_balance{0.0};

  std::cout << "Enter account holder's name: ";
  std::cin.ignore();
  getline(std::cin, account_name);

  std::cout << "\nEnter initial Balance: ";
  std::cin >> initial_balance;

  const std::string filename = "accounts/" + account_name + ".txt";

  std::ofstream file(filename);
  file << initial_balance;

  if (!file) {
    std::cerr << "Account creation failed!\n";
    file.close();
    return;
  }

  std::cout << "Account successfully created!" << std::endl;

  file.close();

  return;
}

void transfer_money() {
  std::string from_account{""};
  std::cout << "From (account holder's name): ";
  std::cin.ignore();
  std::getline(std::cin, from_account);

  std::string to_account{""};
  std::cout << "To (account holder's name): ";
  std::getline(std::cin, to_account);

  double transfer_amount{0};
  std::cout << "Enter amount to transfer: ";
  std::cin >> transfer_amount;

  const std::string from_account_name{"./accounts/" + from_account + ".txt"};
  const std::string to_account_name{"./accounts/" + to_account + ".txt"};

  std::fstream file;

  double from_account_balance{0.0};
  double to_account_balance{0.0};

  int from_temp_balance{0};
  int to_temp_balance{0};

  file.open(from_account_name);

  if (!file.is_open()) {
    std::cerr << "From file could not be opened!" << std::endl;
    return;
  }

  while (file >> from_temp_balance) {
    from_account_balance = from_temp_balance;
  }

  file.clear();
  file.close();
  file.open(to_account_name);

  if (!file.is_open()) {
    std::cerr << "To file could not be opened!" << std::endl;
    return;
  }

  while (file >> to_temp_balance) {
    to_account_balance = to_temp_balance;
  }

  file.clear();
  file.close();

  std::cout << "-----------------------" << std::endl;

  const double new_from_balance = from_account_balance - transfer_amount;
  const double new_to_balance = to_account_balance + transfer_amount;

  std::ofstream o_file;

  o_file.open(from_account_name);
  if (!o_file.is_open()) {
    std::cerr << "From o_file could not be opened!" << std::endl;
    return;
  }
  o_file << new_from_balance;
  o_file.clear();
  o_file.close();

  o_file.open(to_account_name);
  if (!o_file.is_open()) {
    std::cerr << "To o_file could not be opened!" << std::endl;
    return;
  }
  o_file << new_to_balance;
  o_file.clear();
  o_file.close();
}

void view_account_transactions() {
  std::cout << "View account transactions!" << std::endl;
}

void exit_program() {
  std::cout << std::endl
            << "Thank you for using our program. Goodbye..." << std::endl;
}
