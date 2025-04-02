#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

struct Account {
  std::string account_name;
  double initial_balance;
  double account_balance;
};

void create_account(std::vector<Account> *);
void transfer_money(std::vector<Account> *);
void view_account_transactions();
void show_accounts(std::vector<Account> *);
void exit_program(std::vector<Account> *);
void get_account_list(std::vector<Account> *);
std::string get_current_time();

int main() {
  fs::create_directories("accounts");
  std::vector<Account> *account_db = new std::vector<Account>;
  get_account_list(account_db);

  int option{0};

  while (true) {
    std::cout << "\nWelcome to Simple Bank Management System\n\n"
              << "0. Show Accounts\n"
              << "1. Create Account\n"
              << "2. Transfer Money\n"
              << "3. View Account Transactions\n"
              << "4. Exit\n";

    std::cout << "Choose an option: ";
    std::cin >> option;
    std::cout << "\n";

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input! Please enter a number.\n";
      continue;
    }

    switch (option) {
    case 0:
      show_accounts(account_db);
      break;
    case 1:
      create_account(account_db);
      break;
    case 2:
      transfer_money(account_db);
      break;
    case 3:
      view_account_transactions();
      break;
    case 4:
      exit_program(account_db);
      return 0;
    default:
      std::cout << "Please enter a valid option!\n";
      break;
    }
  }
}

std::string get_current_time() {
  std::time_t now = std::time(nullptr);
  std::tm *now_tm = std::localtime(&now);
  char buf[20];
  std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", now_tm);
  return std::string(buf);
}

void show_accounts(std::vector<Account> *account_db) {
  if (account_db->empty()) {
    std::cout << "No accounts created...\n";
    return;
  }

  for (const auto &account : *account_db) {
    std::cout << "Account Name: " << account.account_name
              << " | Balance: " << account.account_balance << "\n";
  }
}

void create_account(std::vector<Account> *account_db) {
  std::string account_name;
  double initial_balance;

  std::cout << "Please enter account name: ";
  std::cin.ignore();
  std::getline(std::cin, account_name);

  if (account_name.empty()) {
    std::cerr << "Account name cannot be empty!\n";
    return;
  }

  std::cout << "Please enter initial balance: ";
  std::cin >> initial_balance;

  if (initial_balance < 0) {
    std::cerr << "Initial balance cannot be negative!\n";
    return;
  }

  const std::string filename = "accounts/" + account_name + ".txt";
  const std::string transaction_filename = "accounts/" + account_name + "_transactions.txt";

  if (fs::exists(filename)) {
    std::cerr << "Account already exists!\n";
    return;
  }

  std::ofstream account_file(filename);
  if (!account_file) {
    std::cerr << "Account creation failed!\n";
    return;
  }
  account_file << initial_balance;
  account_file.close();

  std::ofstream transaction_file(transaction_filename);
  transaction_file << get_current_time() << ": Account created with initial balance: " << initial_balance << "\n";
  transaction_file.close();

  Account new_account;
  new_account.account_name = account_name;
  new_account.initial_balance = initial_balance;
  new_account.account_balance = initial_balance;
  account_db->push_back(new_account);

  std::cout << "\nAccount successfully created!\n";
}

void transfer_money(std::vector<Account> *account_db) {
  std::string from_account, to_account;
  double transfer_amount;

  std::cout << "From (account holder's name): ";
  std::cin.ignore();
  std::getline(std::cin, from_account);

  std::cout << "To (account holder's name): ";
  std::getline(std::cin, to_account);

  if (from_account == to_account) {
    std::cerr << "Cannot transfer to the same account!\n";
    return;
  }

  std::cout << "Enter amount to transfer: ";
  std::cin >> transfer_amount;

  if (transfer_amount <= 0) {
    std::cerr << "Transfer amount must be positive!\n";
    return;
  }

  const std::string from_filename = "accounts/" + from_account + ".txt";
  const std::string to_filename = "accounts/" + to_account + ".txt";

  if (!fs::exists(from_filename) || !fs::exists(to_filename)) {
    std::cerr << "One or both accounts do not exist!\n";
    return;
  }

  double from_balance, to_balance;
  std::ifstream from_file(from_filename);
  from_file >> from_balance;
  from_file.close();

  std::ifstream to_file(to_filename);
  to_file >> to_balance;
  to_file.close();

  if (from_balance < transfer_amount) {
    std::cerr << "Insufficient balance in source account!\n";
    return;
  }

  double new_from_balance = from_balance - transfer_amount;
  double new_to_balance = to_balance + transfer_amount;

  std::ofstream from_out(from_filename);
  from_out << new_from_balance;
  from_out.close();

  std::ofstream to_out(to_filename);
  to_out << new_to_balance;
  to_out.close();

  std::ofstream from_log("accounts/" + from_account + "_transactions.txt", std::ios::app);
  from_log << get_current_time() << ": Transferred " << transfer_amount
           << " to " << to_account << ". New balance: " << new_from_balance << "\n";
  from_log.close();

  std::ofstream to_log("accounts/" + to_account + "_transactions.txt", std::ios::app);
  to_log << get_current_time() << ": Received " << transfer_amount
         << " from " << from_account << ". New balance: " << new_to_balance << "\n";
  to_log.close();

  for (auto &acc : *account_db) {
    if (acc.account_name == from_account) {
      acc.account_balance = new_from_balance;
    } else if (acc.account_name == to_account) {
      acc.account_balance = new_to_balance;
    }
  }

  std::cout << "\nTransfer successful!\n";
}

void view_account_transactions() {
  std::string account_name;
  std::cout << "Enter account name: ";
  std::cin.ignore();
  std::getline(std::cin, account_name);

  const std::string filename = "accounts/" + account_name + "_transactions.txt";

  if (!fs::exists(filename)) {
    std::cerr << "Account or transaction history not found!\n";
    return;
  }

  std::cout << "\n--- Transaction History for " << account_name << " ---\n";
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line)) {
    std::cout << line << "\n";
  }
  file.close();
}

void exit_program(std::vector<Account> *account_db) {
  delete account_db;
  std::cout << "\nThank you for using our program. Goodbye...\n";
}

void get_account_list(std::vector<Account> *account_db) {
  const std::string path = "accounts";

  try {
    for (const auto &entry : fs::directory_iterator(path)) {
      const std::string filename = entry.path().filename().string();
      if (filename.find("_transactions.txt") != std::string::npos) {
        continue;
      }

      const std::string account_name = filename.substr(0, filename.find(".txt"));
      std::ifstream file(entry.path());
      double balance;
      file >> balance;

      Account acc;
      acc.account_name = account_name;
      acc.initial_balance = balance;
      acc.account_balance = balance;
      account_db->push_back(acc);
    }
  } catch (const fs::filesystem_error &err) {
    std::cerr << "Error reading accounts: " << err.what() << "\n";
  }
}