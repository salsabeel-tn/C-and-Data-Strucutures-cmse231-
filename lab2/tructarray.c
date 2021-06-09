#include<stdio.h>
#include <stdlib.h>
#include<string.h>

struct persalary
{
int month; /* number 1 corresponds to January, */
long salary; /* 2 corresponds to February, and so on */
};
struct employee
{
int empnr; /* Employee number */
char name[12]; /* Employee name */
struct persalary salaries[3]; /* three months salaries */
long total; /* Sum of 3 months salaries */
float average; /* Average of 3 months salaries*/
};

void display(struct employee a[])
{
	int i;
char * mounths[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
printf("Employee Nr  Name    Month       Salary\n");
for (i=0;i<4;i++)
{

printf("%d          ",a[i].empnr);
printf("%s",a[i].name);
printf("   %s       %ul\n",mounths[a[i].salaries[0].month-1],a[i].salaries[0].salary);
printf("                     %s      %ul\n",mounths[a[i].salaries[1].month-1],a[i].salaries[1].salary);
printf("                     %s      %ul\n",mounths[a[i].salaries[2].month-1],a[i].salaries[2].salary);

printf("\n");
}
}


void sumAverage (struct employee a[])
{ 
int i,j;
for (i=0;i<4;i++)
{
a[i].total=0;

for(j=0;j<3;j++)

 a[i].total=a[i].total+a[i].salaries[j].salary;

a[i].average=(float)a[i].total/3;

}
printf("Employee Nr    Name      Average         Sum\n");
for (i=0;i<4;i++)
{
printf("%d          ",a[i].empnr);
printf("%s     ",a[i].name);
printf("%f       ",a[i].average);
printf("%ul        \n",a[i].total);
}
}





















int main()
{
	struct employee a[4];
	int emp ,mon1,mon2,mon3;
	long sal1,sal2,sal3;
	char nam[12];
	int p;
	FILE *stud_file;
    stud_file = fopen("C:\\Users\\Imen\\Desktop\\emp.txt","r");
    if (stud_file == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   p=0; //counter for person
   
   do //reading the file
{
fscanf(stud_file ,"%d %s %d %ld %d %ld %d %ld" , &emp , nam , &mon1,&sal1,&mon2,&sal2,&mon3,&sal3);
a[p].empnr=emp;
strcpy(a[p].name, nam);
a[p].salaries[0].month=mon1;
a[p].salaries[0].salary=sal1;
a[p].salaries[1].month=mon2;
a[p].salaries[1].salary=sal2;
a[p].salaries[2].month=mon3;
a[p].salaries[2].salary=sal3; 
p++;
}while (feof(stud_file) == 0);

display(a);
sumAverage (a);

	return 0;
}
