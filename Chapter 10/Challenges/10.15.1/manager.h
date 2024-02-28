#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
using namespace std;
#include "employee.h"

class Manager : public Employee
{
public:
   Manager();
   double set_bonus(double bonus_amount);
   double get_salary() const;
   string get_name() const;
private:
   double bonus;
};

#endif