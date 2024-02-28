#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
public:
   Employee();
   void set_name(string new_name);
   void set_base_salary(double new_salary);
   virtual string get_name() const;
   virtual double get_salary() const; // Returns base salary
private:
   string name;
   double base_salary;
};

#endif