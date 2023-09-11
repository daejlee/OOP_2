#include <iostream>
#include "Account.h"

using namespace std;

int main() {
  Account ac1("Jane Green", 50);
  Account ac2("Jone Blue", -7);

  /**************************** deposit ********************************/
  cout << "account1: " << ac1.getName() << " balance is $" << ac1.getBalance();
  cout << "\naccount2: " << ac2.getName() << " balance is $" << ac2.getBalance();
  cout << "\n\nEnter deposit amount for account1: ";
  int depositAmount;
  cin >> depositAmount;
  cout << "adding " << depositAmount << " to account1 balance";
  ac1.deposit(depositAmount);

  cout << "\n\naccount1: " << ac1.getName() << " balance is $" << ac1.getBalance();
  cout << "\naccount2: " << ac2.getName() << " balance is $" << ac2.getBalance();
  cout << "\n\nEnter deposit amount for account2: ";
  cin >> depositAmount;
  cout << "adding " << depositAmount << " to account2 balance";
  ac2.deposit(depositAmount);

  /**************************** withdraw ********************************/
  cout << "\n\naccount1: " << ac1.getName() << " balance is $" << ac1.getBalance();
  cout << "\naccount2: " << ac2.getName() << " balance is $" << ac2.getBalance();
  cout << "\n\nEnter withdraw amount for account1: ";
  int withdrawalAmount;
  cin >> withdrawalAmount;
  cout << "subtracting " << withdrawalAmount << " from account1 balance";
  ac1.withdraw(withdrawalAmount);

  cout << "\n\naccount1: " << ac1.getName() << " balance is $" << ac1.getBalance();
  cout << "\naccount2: " << ac2.getName() << " balance is $" << ac2.getBalance();
  cout << "\n\nEnter withdraw amount for account2: ";
  cin >> withdrawalAmount;
  cout << "subtracting " << withdrawalAmount << " from account2 balance";
  ac2.withdraw(withdrawalAmount);

  cout << "\n\naccount1: " << ac1.getName() << " balance is $" << ac1.getBalance();
  cout << "\naccount2: " << ac2.getName() << " balance is $" << ac2.getBalance() << endl;
}
