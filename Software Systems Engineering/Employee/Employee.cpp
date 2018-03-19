#include "Employee.h"

/**
 * Constructor for Employee
 * @param first  Employee's first name
 * @param last   Employee's last name
 * @param salary Employee's monthly salary
 *
 * Will verify monthly salary is a positive number
 * If not, user must use set salary to change salary from 0.
 */
Employee::Employee(std::string first, std::string last, double salary)
{
  firstName = first;
  lastName = last;
  if(checkSalary(salary))
  {
    monthlySalary = salary;
  }
  else
  {
    std::cout<<"Invalid salary, must be positive."<<std::endl;
    std::cout<<"Please use setSalary to modify salary."<<std::endl;
    monthlySalary = 0;
  }
}

/**
 * Setter for Employee's first name
 * @param name First name to give to Employee
 */
void Employee::setFirstName(std::string name)
{
  firstName = name;
}

/**
 * Setter for Employee's last name
 * @param name Last name to give to Employee
 */
void Employee::setLastName(std::string name)
{
  lastName = name;
}

/**
 * Setter for Employee's monthly salary
 * @param salary Salary to give to Employee
 *
 * Will verify salary is a positive number.
 * If not, user must call set Salary again.
 */
void Employee::setSalary(double salary)
{
  if(checkSalary(salary))
  {
    monthlySalary = salary;
  }
  else
  {
    std::cout<<"Invalid salary, must be positive."<<std::endl;
  }
}

/**
 * Getter for Employee's first name
 * @return Employee's first name
 */
std::string Employee::getFirstName()
{
  return firstName;
}

/**
 * Getter for Employee's last name
 * @return Employee's last name
 */
std::string Employee::getLastName()
{
  return lastName;
}

/**
 * Getter for Employee's monthly salary
 * @return Employee's monthly salary
 */
double Employee::getSalary()
{
  return monthlySalary;
}

/**
 * Checks if salary if a positive number.
 * @param  salary   salary to verify
 * @return          true if salary is positive number, false otherwise
 */
bool Employee::checkSalary(double salary)
{
  if(salary >= 0)
  {
    return true;
  }
  return false;
}
