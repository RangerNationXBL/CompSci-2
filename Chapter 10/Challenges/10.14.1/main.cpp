#include "savingsaccount.h"
#include <iostream>

using namespace std;

int main()
{
   int initial_balance = 1000;
   int withdrawal;
   cin >> withdrawal;
   SavingsAccount my_checking;
   my_checking.deposit(initial_balance);
   cout << "Initial balance: " << my_checking.get_balance() << endl;
   my_checking.withdraw(withdrawal);
   cout << "After withdrawal of " << withdrawal << ": ";
   cout << my_checking.get_balance() << endl;

   return 0;
}
