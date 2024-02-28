#include <iostream>
using namespace std;

#include "employee.h"
#include "manager.h"

int main()
{
   Manager m1;
   m1.set_name("Lin, Sally");
   m1.set_base_salary(104000);
   m1.set_bonus(10000);
   
   cout << "Manager:" << endl;
   cout << "   Name: " << m1.get_name() << endl;
   cout << "   Salary: " << m1.get_salary() << endl;

   return 0;
}