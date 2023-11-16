#include <iostream>
#include <fstream>

using namespace std;

struct Employee {
    int empId;
    char name[50];
    int age;
    char department[50];
    char post[50];
    double salary;
};

void addRecord() {
    Employee emp;
    cout << "Enter employee details:\n";
    cout << "Employee ID: ";
    cin >> emp.empId;
    cin.ignore();
    cout << "Name: ";
    cin.getline(emp.name, sizeof(emp.name));
    cout << "Age: ";
    cin >> emp.age;
    cin.ignore();
    cout << "Department: ";
    cin.getline(emp.department, sizeof(emp.department));
    cout << "Post: ";
    cin.getline(emp.post, sizeof(emp.post));
    cout << "Salary: ";
    cin >> emp.salary;

    ofstream outFile("employeeDatabase.dat", ios::binary | ios::app);
    outFile.write((char*)&emp, sizeof(Employee));
    outFile.close();

    cout << "Record added successfully!\n";
}

void displayAllRecords() {
    ifstream inFile("employeeDatabase.dat", ios::binary);
    Employee emp;

    while (inFile.read((char*)&emp, sizeof(Employee))) {
        cout << "Employee ID: " << emp.empId << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Age: " << emp.age << endl;
        cout << "Department: " << emp.department << endl;
        cout << "Post: " << emp.post << endl;
        cout << "Salary: " << emp.salary << endl;
        cout << "------------------------\n";
    }

    inFile.close();
}

void searchEmployee() {
    int searchId;
    cout << "Enter employee ID to search: ";
    cin >> searchId;

    ifstream inFile("employeeDatabase.dat", ios::binary);
    Employee emp;
    bool found = false;

    while (inFile.read((char*)&emp, sizeof(Employee))) {
        if (emp.empId == searchId) {
            cout << "Employee found!\n";
            cout << "Employee ID: " << emp.empId << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Age: " << emp.age << endl;
            cout << "Department: " << emp.department << endl;
            cout << "Post: " << emp.post << endl;
            cout << "Salary: " << emp.salary << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee not found!\n";
    }

    inFile.close();
}

void updateEmployee() {
    int updateId;
    cout << "Enter employee ID to update: ";
    cin >> updateId;

    fstream file("employeeDatabase.dat", ios::binary | ios::in | ios::out);
    Employee emp;
    bool found = false;

    while (file.read((char*)&emp, sizeof(Employee))) {
        if (emp.empId == updateId) {
            cout << "Enter new salary: ";
            cin >> emp.salary;
            cin.ignore();
            cout << "Enter new post: ";
            cin.getline(emp.post, sizeof(emp.post));

            file.seekp(file.tellg() - sizeof(Employee));
            file.write((char*)&emp, sizeof(Employee));

            cout << "Employee information updated!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee not found!\n";
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\nEmployee Database Management\n";
        cout << "1. Add New Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
