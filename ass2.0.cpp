#include <bits/stdc++.h>
#include <string>
using namespace std;

void sortAlphabetically(string names[], int n) {
    sort(names, names + n);
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of names you want to add:" << endl;
    cin >> n;
    cin.ignore(); // Clear the newline character from the input buffer

    string names[n];
    for (int i = 0; i < n; i++) {
        cout << "Name: ";
        getline(cin, names[i]);
    }

    cout << "Before sorting:" << endl;
    for (int j = 0; j < n; j++) {
        cout << names[j] << endl;
    }

    cout << "After sorting:" << endl;
    sortAlphabetically(names, n);

    return 0;
}
