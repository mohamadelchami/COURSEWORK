//Lab 6
//Name: Mohamad Elchami Date: March 20th, 2018 Description:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct employee
{
    char firstname[40];
    char lastname[40];
    int id;
};

typedef struct employee Employee;

/* Input the employee data interactively from the keyboard */
void InputEmployeeRecord(Employee *ptrEmp);

/* Display the contents of a given Employee record*/
void PrintEmployeeRecord(const Employee e1[]);

/* Save the contents of the employee record list to the newly created text file specified by FileName */
void SaveEmployeeRecord(const Employee e1[], const char *FileName);

int main() {

 Employee e1[3]; //

 InputEmployeeRecord(e1);
 PrintEmployeeRecord(e1);
 SaveEmployeeRecord(e1, "employee.dat");
}

//InputEmployeeRecord: Input the employee data interactively from the keyboard
//Input: pointer to the employee structure
//Output: None
void InputEmployeeRecord(Employee *ptrEmp)
{
  //loop for 3 inputs
  for(int i = 0 ; i < 3 ; i++)
  {
    //prompt for employee id input
    printf("Enter an employee ID: ");
    scanf("%d", &ptrEmp->id);

    //printf("%d\n", ptrEmp->id); test

    //prompt for employee first name input
    printf("Enter an employee first name: ");
    scanf(" %[^\n]", ptrEmp->firstname);

    //printf("%s\n", ptrEmp->firstname); test

    //prompt for employee last name input
    printf("Enter an employee last name: ");
    scanf(" %[^\n]", ptrEmp->lastname);

    //printf("%s\n", ptrEmp->lastname); test

    //for organizational purposes
    printf("Employee record entered.\n\n");

    ptrEmp++; //increment to the next element of e1

  }
}

//PrintEmployeeRecord: Display the contents of a given Employee record
//Input: Constant employee structure
//Ouput: Prints the employee record
void PrintEmployeeRecord(const Employee e1[])
{
  printf("ID\t\tFIRSTNAME\tLASTNAME\n");
  for(int i = 0; i < 3; i++)
  {
      printf("%d\t\t%s\t\t%s\n", e1[i].id, e1[i].firstname, e1[i].lastname);

  }
}

//SaveEmployeeRecord: Saves the employee record to a FileName
//Input: The employee struncture, pointyer to the File
//Output: File with the employee record
void SaveEmployeeRecord(const Employee e1[], const char *FileName)
{
  FILE *fp;

  fp = fopen("employee.dat", "w");
  fprintf(fp, "ID\t\tFIRSTNAME\tLASTNAME\n");

  for(int i = 0; i < 3 ; i++ )
  {
    fprintf(fp, "%d\t\t%s\t\t%s\n", e1[i].id, e1[i].firstname, e1[i].lastname);
  }
  fclose(fp);
}
