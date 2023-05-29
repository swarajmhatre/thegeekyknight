#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 50

struct Employee {
    char name[50];
    int id;
    float performance_rating;
};

 Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Function to add an employee
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Maximum employee limit reached.\n");
        return;
    }

    struct Employee newEmployee;

    printf("Enter the name of the employee: ");
    scanf("%s", newEmployee.name);

    printf("Enter the employee ID: ");
    scanf("%d", &newEmployee.id);

    printf("Enter the performance rating (0-10): ");
    scanf("%f", &newEmployee.performance_rating);

    employees[employeeCount] = newEmployee;
    employeeCount++;

    printf("Employee added successfully.\n");
}

// Function to find an employee by employee ID
void findEmployee() {
    int empId;
    printf("Enter the employee ID: ");
    scanf("%d", &empId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == empId) {
            printf("Employee Details:\n");
            printf("Name: %s\n", employees[i].name);
            printf("Employee ID: %d\n", employees[i].id);
            printf("Performance Rating: %.2f\n", employees[i].performance_rating);
            return;
        }
    }

    printf("Employee not found.\n");
}

// Function to calculate the average performance rating of all employees
void calculateAverageRating() {
    if (employeeCount == 0) {
        printf("No employees found.\n");
        return;
    }

    float totalRating = 0;

    for (int i = 0; i < employeeCount; i++) {
        totalRating += employees[i].performance_rating;
    }

    float averageRating = totalRating / employeeCount;
    printf("Average Performance Rating: %.2f\n", averageRating);
}

// Function to display all employees and their details
void displayAllEmployees() {
    if (employeeCount == 0) {
        printf("No employees found.\n");
        return;
    }

    printf("Employee Details:\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Employee ID: %d\n", employees[i].id);
        printf("Performance Rating: %.2f\n\n", employees[i].performance_rating);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nEmployee Performance Evaluation System\n");
        printf("1. Add Employee\n");
        printf("2. Find Employee\n");
        printf("3. Calculate Average Rating\n");
        printf("4. Display All Employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                findEmployee();
                break;
            case 3:
                calculateAverageRating();
                break;
            case 4:
                displayAllEmployees();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
