/***
    Employee management system for 1500 employee

    Project create by:
    1. Md. Hasibur Rahman (212902018)
*/

/**
        Start Project
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure of Employee file
typedef struct
{
    char full_name[20];
    int employee_ID;
    float salary;

} EmployeeData;

// function prototype
void addEmployeeDetails(EmployeeData EmployeeDB[], int EmployeeCount);
void updateEmployee(EmployeeData EmployeeDB[], int EmployeeCount);
void findEmployee(EmployeeData EmployeeDB[], int EmployeeCount);
void countEmployees(int EmployeeCount);
void printDB(EmployeeData EmployeeDB[], int EmployeeCount);
void ReadDB(FILE *file, EmployeeData EmployeeDB[], int *EmployeeCount);
void WriteDB(FILE *file, EmployeeData EmployeeDB[], int EmployeeCount);
void menuDisplay();
void headerDisplay();

// main function
int main()
{
    system("color 70");

    EmployeeData EmployeeDB[1500];

    int EmployeeCount = 0, option;

    FILE *file;

    // open file from the database file
    file = fopen("employeeDB.txt", "r");

    if (file != NULL)
    {
        ReadDB(file, EmployeeDB, &EmployeeCount); // read file
        fclose(file);                             // close file
    }

    headerDisplay();

    // loop for display the menu
    while (true)
    {
        menuDisplay();

        printf("\t\t\tEnter option: ");
        scanf("%d", &option);

        if (option == 6)
            break;

        switch (option)
        {
        case 1:
            addEmployeeDetails(EmployeeDB, EmployeeCount);
            EmployeeCount++;
            break;

        case 2:
            updateEmployee(EmployeeDB, EmployeeCount);
            break;

        case 3:
            findEmployee(EmployeeDB, EmployeeCount);
            break;

        case 4:
            countEmployees(EmployeeCount);
            break;

        case 5:
            printDB(EmployeeDB, EmployeeCount);
            break;
        }
    }

    file = fopen("employeeDB.txt", "w+"); // open the file

    WriteDB(file, EmployeeDB, EmployeeCount); // write the file

    fclose(file); // close the file

    return 0;
}

// Displays

void headerDisplay()
{
    printf("\n\n\n");
    printf("\t\t\t***********************************************************************\n");
    printf("\t\t\t***                                                                 ***\n");
    printf("\t\t\t***    Employee Information Management System for 1500 Employees    ***\n");
    printf("\t\t\t***                                                                 ***\n");
    printf("\t\t\t***********************************************************************\n");

    printf("\n\n\n\n");
}

void menuDisplay()
{
    printf("\n\t\t\t1 >> Add Employee Info");
    printf("\n\t\t\t2 >> Update Employee Info");
    printf("\n\t\t\t3 >> Find Employee Info by ID");
    printf("\n\t\t\t4 >> Total Employees");
    printf("\n\t\t\t5 >> Print Database");
    printf("\n\t\t\t6 << Exit");

    printf("\n\n\n");
}

// function (addEmployeeDetails)
void addEmployeeDetails(EmployeeData EmployeeDB[], int EmployeeCount)
{
    EmployeeData employee;
    int fileCheck, i;

    // check for the uniqueness of the Employee
    do
    {
        printf("\n\t\t\tEmployee ID: ");
        scanf("%d", &employee.employee_ID);
        fileCheck = 0;
        for (i = 0; i < EmployeeCount; i++)
        {
            if (EmployeeDB[i].employee_ID == employee.employee_ID)
            {
                printf("\n\t\t\tThis employee's ID already exist! Please try again\n");
                fileCheck = 1;
            }
        }
    } while (fileCheck != 0);

    getchar();
    printf("\t\t\tName of the Employee: ");
    scanf("%[^\n]", employee.full_name);
    printf("\t\t\tEnter Employee salary: ");
    scanf("%f", &employee.salary);

    EmployeeDB[EmployeeCount] = employee;
}

// function (updateEmployee)
void updateEmployee(EmployeeData EmployeeDB[], int EmployeeCount)
{
    int id, i, option;

    printf("\t\t\tEnter Id to update info: ");
    scanf("%d", &id);

    for (i = 0; i < EmployeeCount; i++)
    {
        if (EmployeeDB[i].employee_ID == id)
        {
            printf("\n\t\t\t\t1 >> Update employee name: ");
            printf("\n\t\t\t\t2 >> Update salary: ");
            printf("\n\n\t\t\t\tEnter a option to update: ");
            scanf("%d", &option);

            if (option == 1)
            {
                printf("\t\t\t\t\t\tUpdated name: ");
                getchar();
                scanf("%[^\n]", EmployeeDB[i].full_name);
            }
            else
            {
                printf("\t\t\t\tUpdated salary: ");
                scanf("%f", &EmployeeDB[i].salary);
            }
            return;
        }
    }
    printf("\n\n\t\t\tNot found! Please Enter a valid ID\n");
}

// function (findEmployee)
void findEmployee(EmployeeData EmployeeDB[], int EmployeeCount)
{
    int i, id;

    printf("\n\t\t\tEnter employee ID to show Details Info: ");
    scanf("%d", &id);

    for (i = 0; i < EmployeeCount; i++)
    {
        if (EmployeeDB[i].employee_ID == id)
        {
            printf("\n\t\t\t\t\tEmployee Name:  %s\n", EmployeeDB[i].full_name);
            printf("\t\t\t\t\tEmployee ID :  %d\n", EmployeeDB[i].employee_ID);
            printf("\t\t\t\t\tSalary :  %.3f\n", EmployeeDB[i].salary);
            return;
        }
    }
    printf("\n\n\t\t\tNot found! Please Enter a valid ID\n");
}

// function (countEmployees)
void countEmployees(int EmployeeCount)
{
    printf("\n\t\t\t*****************************\n");
    printf("\t\t\t**                         **\n");
    printf("\t\t\t**   Total Employee = %d   **\n", EmployeeCount);
    printf("\t\t\t**                         **\n");
    printf("\t\t\t*****************************\n");
}

// function (printDB)
void printDB(EmployeeData EmployeeDB[], int EmployeeCount)
{
    int i;

    printf("\n\t\t\t********************************************************************\n");
    printf("\t\t\t EmployeeName                  EmployeeID                    Salary   \n");
    printf("\t\t\t********************************************************************\n\n");
    for (i = 0; i < EmployeeCount; i++)
    {
        printf("\t\t\t%d) %s%18d%26.3f\n", i + 1, EmployeeDB[i].full_name, EmployeeDB[i].employee_ID, EmployeeDB[i].salary);
    }
}

// function (ReadDB)
void ReadDB(FILE *file, EmployeeData EmployeeDB[], int *EmployeeCount)
{
    char line_for_employee_info[1500];
    int i = 0;

    while (!feof(file))
    {
        fgets(EmployeeDB[i].full_name, 20, file);
        if (feof(file))
            break;
        fscanf(file, "%d%f\n", &EmployeeDB[i].employee_ID, &EmployeeDB[i].salary);
        i++;
    }
    *EmployeeCount = i;
}

// function (WriteDB)
void WriteDB(FILE *file, EmployeeData EmployeeDB[], int EmployeeCount)
{
    int i;
    for (i = 0; i < EmployeeCount; i++)
    {
        fprintf(file, "%-20s%d\t%.2f\n", EmployeeDB[i].full_name, EmployeeDB[i].employee_ID, EmployeeDB[i].salary);
    }
}
