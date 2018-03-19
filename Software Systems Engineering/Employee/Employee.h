#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
/**
 * Employee class to hold name and salary information
 */
class Employee
{
private:
  std::string firstName, lastName;
  double monthlySalary;

public:
  Employee(std::string first, std::string last, double salary);

  //setters
  void setFirstName(std::string name);
  void setLastName(std::string name);
  void setSalary(double salary);

  //getters
  std::string getFirstName();
  std::string getLastName();
  double getSalary();

  //verification
  bool checkSalary(double salary);
};

#endif /* EMPLOYEE_H */
