#include "bankaccount.h"

class SavingsAccount : public BankAccount
{
public:
    void month_end();
};

void SavingsAccount::month_end()
{
    double interest = get_balance() * 0.001;
    deposit(interest);
}