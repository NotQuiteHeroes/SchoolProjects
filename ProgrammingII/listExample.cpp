/*
Paige Eckstein
Programming II
Demonstrate the use of STLS
*/

#include<string>
#include<iostream>
#include<list>

using namespace std;


struct StudentInfo
{
	string name;
	int grade;
	StudentInfo(string name, int grade):name(name), grade(grade) {}
	
	bool operator< (const StudentInfo& right) const {return name < right.name; }
};

void populateStudentRecord(list<StudentInfo>& students);

int main()
{
	list<StudentInfo> students;
	
	populateStudentRecord(students);
	
	students.sort();
	
	for(list<StudentInfo>::iterator it = students.begin(); it != students.end(); it++)
	{
		cout<<it->name<<" "<<it->grade<<endl;
	}
	
}

void populateStudentRecord(list<StudentInfo>& students)
{
	string Names[10] = {"Jane", "John", "Dan", "Chris", "Paige", "Phil", "Cam", "Ashley", "Brad", "Anna"};
	
	int Grades[10] = {88, 100, 72, 67, 81, 75, 87, 72, 92, 68};
	
	for(int i = 0; i < 10; i++)
	{
		students.push_back(StudentInfo(Names[i], Grades[i]));	
	}
	
}
	
	
	