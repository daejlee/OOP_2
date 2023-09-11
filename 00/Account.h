#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP
# include <string>

class Account {
  public:
    Account(std::string accountName, int initialBalance) : name_(accountName), balance_(0) {
      if (initialBalance > 0)
        balance_ = initialBalance;
    }
    
    void  deposit(int depositAmount){
      if (depositAmount > 0)
        balance_ = balance_ + depositAmount;
    }

    void  withdraw(int withdrawAmount){
      if (withdrawAmount > balance_)
        std::cout << "\nWithdrawal amount exceeded account balance";
      if (withdrawAmount <= balance_)
        balance_ -= withdrawAmount;
    }

    int getBalance() const{return balance_;}

    void setName(std::string accountName){name_ = accountName;}

    std::string getName() const {return name_;}

    private:
      std::string name_;
      int balance_;
};

#endif