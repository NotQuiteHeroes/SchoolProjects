// Paige Eckstein
// Software Systems Engineering
// 1/3/18
// Test client for Employee class
#include "Employee.h"

void printEmployeeInfo(Employee emp);

int main()
{
  Employee one("John", "Doe", 2200.50);
  Employee two("Jane", "Doe", 2350.75);

  std::cout<<"Employee Information"<<std::endl;
  std::cout<<"-----------------------------------"<<std::endl;
  printEmployeeInfo(one);
  std::cout<<"-----------------------------------"<<std::endl;
  printEmployeeInfo(two);
  std::cout<<std::endl;
  std::cout<<std::endl;

  std::cout<<"Updating salary information..."<<std::endl;
  one.setSalary(one.getSalary() + one.getSalary() * .10);
  two.setSalary(two.getSalary() + two.getSalary() * .10);

  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<"Updated Employee information: "<<std::endl;
  std::cout<<"-----------------------------------"<<std::endl;
  printEmployeeInfo(one);
  std::cout<<"-----------------------------------"<<std::endl;
  printEmployeeInfo(two);

}

void printEmployeeInfo(Employee emp)
{
  std::cout<<emp.getFirstName()<< " " <<emp.getLastName()<<std::endl;
  std::cout<<"Yearly salary: "<<emp.getSalary() * 12 << std::endl;
}
