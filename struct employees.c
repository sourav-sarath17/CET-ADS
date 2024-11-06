#include<stdio.h>
#include<string.h>

struct employees{
    int id;
    char name[20];
    int salary;
};
void main()
{
    int n;
    printf("\nEnter the number of employees: ");
    scanf("%d",&n);
    struct employees Employees[n];
    for(int i=0;i<n;i++){
        printf("\nEnter details of emplyee number %d",i+1);
        printf("\nEnter employee id: ");
        scanf("%d",&Employees[i].id);
        printf("\nEnter employee name: ");
        gets(Employees[i].name);
        printf("\nEnter salary: ");
        scanf("%d",&Employees[i].salary);

    }

    for(int i=0;i<n;i++){
        printf("\nDetails of emplyee number %d",i+1);
        printf("\nEmployee id: %d",Employees[i].id);
        printf("\nEmployee name: %s",Employees[i].name);
        printf("\nSalary: %d",Employees[i].salary);

    }

}