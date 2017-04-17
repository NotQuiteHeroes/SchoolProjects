/*
Paige Eckstein
Programming II
Inheritance Example
*/

#include<iostream>

using namespace std;

/*=======================================================================================
==================================Person Class===========================================
========================================================================================*/
//Base class
class Person
{
private:
	//private fields
	string name, address, city, state, zip, phoneNumber;

public:
	//default constructor
	Person();
	//display function to print out private fields
	virtual void display();
};

/*=======================================================================================
==================================Student Class===========================================
========================================================================================*/
//Student class derived from Person base class
class Student: public Person
{
private:
	//private fields specific to student
	string grade, course, GPA;

public:
	//default constructor
	Student();
	//student display function
	void display();
};

/*=======================================================================================
==================================Professional Class=====================================
========================================================================================*/
//Professional class derived from Person base class
class Professional: public Person
{
private:
	string companyName, website, email;
public:
	Professional();
	void display();
};


/*=======================================================================================
==================================Class Definitions=======================================
========================================================================================*/

//Person default constructor defined
Person::Person()
{
	//initialized values
	name = "Jane Doe";
	address = "123 Main St.";
	city = "St. Louis";
	state = "Missouri";
	zip = "63116";
	phoneNumber = "636-357-9948";
}

//Person display method defined
void Person::display()
{
	cout<<name<<endl;
	cout<<address<<endl;
	cout<<city<<", "<<state<<endl;
	cout<<zip<<endl;
	cout<<phoneNumber<<endl;
}

//Student constructor defined
Student::Student()
{
	//initialized values
	grade = "B+";
	course = "Calculus";
	GPA = "3.6";
}

//Student display method defined
void Student::display()
{
	//calls display method from Person base class
	Person::display();
	//display field values from Student derived class
	cout<<grade<<"     "<<course<<"     "<<GPA<<endl;
}

//Professional default constructor
Professional::Professional()
{
	companyName = "Google";
	website = "www.google.com";
	email = "jane.doe@gmail.com";
}

void Professional::display()
{
	//calls display method from Person base class
	Person::display();
	//display field values from Professional derived class
	cout<<email<<endl;
	cout<<companyName<<"     :     "<<website<<endl;
}

/*=======================================================================================
========================================Main=============================================
========================================================================================*/
int main()
{	
	//create pointers of Person base class and point them to new objects of Person
	//Student and Professional classes
	Person* pPerson = new Person;
	Person* pStudent = new Student;
	Person* pProfessional = new Professional;
	
	//late binding, call display using pointer variable currently pointing to Person
	//base class
	cout<<"From Person base class: "<<endl;
	pPerson->display();
	
	cout<<endl;
	
	//Late binding; call display using pointer variable currently pointing to Student
	//derived class
	cout<<"From Student derived class: "<<endl;
	pStudent->display();
	
	cout<<endl;
	
	//Late binding; call display using pointer variable currently pointing to Professional
	//derived class
	cout<<"From Professional derived class: "<<endl;
	pProfessional->display();
	
	return 0;
	
}
	