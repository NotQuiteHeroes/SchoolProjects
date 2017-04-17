/* This will simply allocate space */

Employee[] employees = new Employee[100];

/* This will initialize */

for(int index = 0; index<employees.length; index++){
     employees[index] = new Employee(index + 1);
}
