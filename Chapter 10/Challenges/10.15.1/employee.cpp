#include "employee.h"

Employee::Employee()
{
   base_salary = 0.0;
}

void Employee::set_name(string employee_name)
{
   name = employee_name;
}

string Employee::get_name() const
{
   return name; 
}

void Employee::set_base_salary(double new_salary)
{
   base_salary = new_salary;
}

double Employee::get_salary() const
{
   return base_salary;
}