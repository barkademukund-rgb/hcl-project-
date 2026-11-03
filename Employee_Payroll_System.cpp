#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    int id;
    string name, department;
    float salary, bonus, tax, netSalary;

    void addEmployee()
    {
        cout << "\nEnter Employee ID: ";
        cin >> id;

        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Department: ";
        cin >> department;

        cout << "Enter Basic Salary: ";
        cin >> salary;

        cout << "Enter Bonus: ";
        cin >> bonus;

        calculateSalary();

        cout << "\nEmployee Added Successfully!" << endl;
    }

    void calculateSalary()
    {
        float grossSalary = salary + bonus;
        tax = grossSalary * 0.05;
        netSalary = grossSalary - tax;
    }

    void displayDetails()
    {
        cout << "\n========== EMPLOYEE PAYSLIP ==========" << endl;
        cout << "Employee ID : " << id << endl;
        cout << "Name        : " << name << endl;
        cout << "Department  : " << department << endl;
        cout << "Basic Salary: Rs. " << salary << endl;
        cout << "Bonus       : Rs. " << bonus << endl;
        cout << "Tax         : Rs. " << tax << endl;
        cout << "Net Salary  : Rs. " << netSalary << endl;
        cout << "======================================" << endl;
    }

    void updateSalary()
    {
        cout << "\nEnter New Basic Salary: ";
        cin >> salary;

        calculateSalary();

        cout << "\nSalary Updated Successfully!" << endl;
    }
};

// Search employee using ID
int findEmployee(Employee employees[], int count, int searchID)
{
    for (int i = 0; i < count; i++)
    {
        if (employees[i].id == searchID)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    Employee employees[100];

    int count = 0;
    int choice, searchID, index;

    do
    {
        cout << "\n========================================" << endl;
        cout << "          EMPLOYEE PAYROLL SYSTEM" << endl;
        cout << "========================================" << endl;

        cout << "1. Add Employee" << endl;
        cout << "2. Calculate Salary" << endl;
        cout << "3. Display Payslip" << endl;
        cout << "4. Update Salary" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (count < 100)
                {
                    employees[count].addEmployee();
                    count++;
                }
                else
                {
                    cout << "\nEmployee Limit Reached!" << endl;
                }
                break;

            case 2:
                cout << "\nEnter Employee ID: ";
                cin >> searchID;

                index = findEmployee(employees, count, searchID);

                if (index != -1)
                {
                    employees[index].calculateSalary();
                    cout << "\nSalary Calculated Successfully!" << endl;
                    employees[index].displayDetails();
                }
                else
                {
                    cout << "\nEmployee Not Found!" << endl;
                }
                break;

            case 3:
                cout << "\nEnter Employee ID: ";
                cin >> searchID;

                index = findEmployee(employees, count, searchID);

                if (index != -1)
                {
                    employees[index].displayDetails();
                }
                else
                {
                    cout << "\nEmployee Not Found!" << endl;
                }
                break;

            case 4:
                cout << "\nEnter Employee ID: ";
                cin >> searchID;

                index = findEmployee(employees, count, searchID);

                if (index != -1)
                {
                    employees[index].updateSalary();
                }
                else
                {
                    cout << "\nEmployee Not Found!" << endl;
                }
                break;

            case 5:
                cout << "\nThank You for Using Employee Payroll System!" << endl;
                break;

            default:
                cout << "\nInvalid Choice! Please Try Again." << endl;
        }

    } while (choice != 5);

    return 0;
}
