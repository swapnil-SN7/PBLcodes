#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Person {
    string name;
    string birthDate;
    string telephoneNo;
};

// Function to add or update a person record
void addOrUpdatePerson(map<string, Person>& records) {
    Person newPerson;
    
    cout << "Enter person details:\n";
    cout << "Name: ";
    cin >> newPerson.name;
    cout << "Birth Date: ";
    cin >> newPerson.birthDate;
    cout << "Telephone No: ";
    cin >> newPerson.telephoneNo;

    // Using insert to add or update the record in the map
    auto result = records.insert({newPerson.name, newPerson});

    // Check if the insertion was successful or if the name already exists
    if (result.second) {
        cout << "Record added successfully!\n";
    } else {
        // If the name already exists, update the existing record
        cout << "Record already exists. Updating the existing record.\n";
        result.first->second = newPerson;
    }
}

// Function to display all person records
void displayAllRecords(const map<string, Person>& records) {
    cout << "Person Records:\n";
    for (const auto& pair : records) {
        const Person& person = pair.second;
        cout << "Name: " << person.name << ", Birth Date: " << person.birthDate
             << ", Telephone No: " << person.telephoneNo << endl;
    }
}

// Function to search for a person record
void searchPerson(const map<string, Person>& records) {
    string searchName;
    cout << "Enter the name to search: ";
    cin >> searchName;

    auto it = records.find(searchName);
    if (it != records.end()) {
        const Person& person = it->second;
        cout << "Record found:\n";
        cout << "Name: " << person.name << ", Birth Date: " << person.birthDate
             << ", Telephone No: " << person.telephoneNo << endl;
    } else {
        cout << "Record not found!\n";
    }
}

// Function to delete a person record
void deletePerson(map<string, Person>& records) {
    string deleteName;
    cout << "Enter the name to delete: ";
    cin >> deleteName;

    auto it = records.find(deleteName);
    if (it != records.end()) {
        records.erase(it);
        cout << "Record deleted successfully!\n";
    } else {
        cout << "Record not found!\n";
    }
}

int main() {
    map<string, Person> personRecords;

    int choice;

    do {
        cout << "\nPerson Record Management\n";
        cout << "1. Add/Update Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addOrUpdatePerson(personRecords);
                break;
            case 2:
                displayAllRecords(personRecords);
                break;
            case 3:
                searchPerson(personRecords);
                break;
            case 4:
                deletePerson(personRecords);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout
