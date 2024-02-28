#include "bankaccount.h"

class CheckingAccount : public BankAccount
{
public:
    void withdraw(double amount);

};

void CheckingAccount::withdraw(double amount)
{
    if(amount < 100)
    {
        BankAccount::withdraw(amount + 5);
    }
    else
    {
        BankAccount::withdraw(amount);
    }
}