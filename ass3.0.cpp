#include<iostream>
using namespace std;

void check(char ch){
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        if (ch >= 'A' && ch <= 'Z') {
            cout << "The entered character is an Uppercase letter." << endl;
        } else {
            cout << "The entered character is a Lowercase letter." << endl;
        }
    } else if (ch >= '0' && ch <= '9') {
        cout << "The entered character is a Digit." << endl;
    } else {
        cout << "The entered character is a Special character." << endl;
    }
}
int main(){
    char ch;
    cout << "Enter the character you want to check:"<<endl;
    cin >> ch;
    check(ch);
    
}