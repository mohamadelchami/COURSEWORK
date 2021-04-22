//Name: Mohamad Elchami Date:March 20th, 2018

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct employee
{
    char firstname[40];
    char lastname[40];
    int id;
};

typedef struct employee Employee;

void wordcap(char *E);

int main()
{
  Employee EmployeeList[3];

  FILE *fp;
  fp = fopen("employee.dat", "r");

  //takes the first lane as garbage
  char temp[100];
  fscanf(fp, "%s %s %s", temp, temp, temp);

  for(int i = 0 ; i < 3; i++)
  {
    fscanf(fp, "%d %s %s", &EmployeeList[i].id, EmployeeList[i].firstname, EmployeeList[i].lastname);
    wordcap(EmployeeList[i].firstname); //wordcap for the firstname
    wordcap(EmployeeList[i].lastname); //wordcap for the last name
  }

  fclose(fp);

  //overwrites the file witht the new data
  fp = fopen("employee.dat", "w");
  fprintf(fp, "ID\t\tFIRSTNAME\tLASTNAME\n");

  for(int i = 0; i < 3 ; i++ )
  {
    fprintf(fp, "%d\t\t%s\t\t%s\n", EmployeeList[i].id, EmployeeList[i].firstname, EmployeeList[i].lastname);
  }

  fclose(fp);

}



//wordcap: Capitalizes the first letter of each name
//Input: EmployeeList Array
//Output:
void wordcap(char *E)
{
  *E = toupper(*E);

  E++;

  for(; *E != '\0'; E++)
  {
    *E = tolower(*E);
  }

}
