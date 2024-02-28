#include <iostream>
#include "manager.h"

Manager::Manager()
{
   bonus = 0.0;
}

double Manager::set_bonus(double bonus_amount)
{
   bonus = bonus_amount;
   return bonus;
}

double Manager::get_salary() const
{
   return Employee::get_salary() + bonus;
}
string Manager::get_name() const
{
    return "*" + Employee::get_name();
}