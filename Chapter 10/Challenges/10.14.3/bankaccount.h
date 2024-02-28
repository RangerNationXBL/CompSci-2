#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

/**
A bank account has a balance that can be changed by 
deposits and withdrawals.
*/
class BankAccount
{  
public:
/**
    Constructs a bank account with a zero balance.
   */
    BankAccount();

/**
    Constructs a bank account with a given balance.
    @param initial_balance the initial balance
   */
    BankAccount(double initial_balance);

    /**
    Deposits money into this account.
    @param amount the amount to deposit
   */
    void deposit(double amount);

    /**
    Makes a withdrawal from this account.
    @param amount the amount of the withdrawal
   */
    void withdraw(double amount);

/**
    Gets the current balance of this account.
    @return the current balance
   */
    double get_balance() const;

private:
    double balance;
};

#endif