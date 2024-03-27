// Write a C++ program to create a class employee containing salary as a data member. Write
// necessary member functions to overload the operator unary pre and post decrement "--"
// for decrementing salary. 
#include<iostream>
using namespace std;

class Employee {
   private:
      double salary;
   public:
      Employee(double s) {
         salary = s;
      }
      void displaySalary() {
         cout << "Salary : " << salary << endl;
      }
      Employee operator--() { // Pre-decrement operator overloading
         salary = salary - 1;
         return Employee(salary);
      }
      Employee operator--(int) { // Post-decrement operator overloading
         salary = salary - 1;
         return Employee(salary + 1);
      }
};

int main() {
   Employee emp(5000);
   emp.displaySalary();

   --emp; // Pre-decrement operator called
   emp.displaySalary();

   emp--; // Post-decrement operator called
   emp.displaySalary();

   return 0;
}
