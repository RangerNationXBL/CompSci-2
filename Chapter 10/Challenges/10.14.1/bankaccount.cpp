#include "checkingaccount.h"
#include <iostream>

using namespace std;

int main()
{
   int initial_balance = 1000;
   int withdrawal;
   cin >> withdrawal;
   CheckingAccount my_checking;
   my_checking.deposit(initial_balance);
   cout << "Initial balance: " << my_checking.get_balance() << endl;
   my_checking.withdraw(withdrawal);
   cout << "After withdrawal of " << withdrawal << ": ";
   cout << my_checking.get_balance() << endl;

   return 0;
}


BankAccount::BankAccount(double initial_balance) 
{
   balance = initial_balance;
}

void BankAccount::deposit(double amount) 
{ 
   balance = balance + amount;
}

void BankAccount::withdraw(double amount) 
{ 
   balance = balance - amount;
}

double BankAccount::get_balance() const 
{ 
   return balance; 
}