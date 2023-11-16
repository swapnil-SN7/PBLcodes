#include <iostream>
using namespace std;



class Complex{
    public:
    int real, imaginary;
    //constructor 1
    Complex(int r =0 , int i=0){
        this->real =r ;
        this->imaginary =i;
    }

  Complex operator+(const Complex& other){
    return Complex (this -> real +other.real , this -> imaginary+other.imaginary);
  }

  Complex operator*(const Complex& other){
    return Complex((this->real*other.real)-(this->imaginary*other.imaginary),(this->real *other.imaginary)+(this->imaginary*other.real));
  }


  friend ostream& operator <<(ostream& output,const Complex & comp){
            output << comp.real<<"+"<<comp.imaginary <<"i"<<endl;
            return output;
  }

  friend istream& operator >>(istream& input ,Complex &comp){
    cout<< "Enter the value of Real part and Imaginary part : ";
    input >> comp.real;
    input >>comp.imaginary;
    return input;
  }

};

int main(){
    Complex comp1,comp2;
    cout<<"Enter the data for first complex number"<<endl;
    cin >> comp1;
    cout<<"Enter the data for second complex number"<<endl;
    cin>>comp2;
    Complex sum = comp1+comp2;

    cout << "sum is :"<< sum <<endl;
    Complex prdt = comp1*comp2;
    cout<< "product is:"<<prdt<<endl;
}