#include <iostream>
using namespace std;

class Shape{
    public:
    virtual void area() = 0; //pure virtual function
};
class Triangle : public Shape{
    private:
    int base, height;

    public:
    Triangle(int b, int h){
        this->base=b;
        this->height=h;
    }

    void area(){
        cout<<"Area of triangle is "<< (this->base * this->height) /2 <<endl;
    }


};


class Rec : public Shape{
    private:
    int length;
    int width;
    public:
    Rec(int l, int w){
        this->length=l;
        this->width=w;

    }

    void area(){
         cout << "Area of Rectangle is:"<<(length*width)<<endl;
    }
};

int main(){
    int h,b;
    cout <<"Enter the height of the triangle"<<endl;
    cin >> h;
    cout <<"Enter the base of the triangle"<<endl;
    cin>>b;
    Triangle t1(b,h);


    int l,w;
    cout <<"Enter the length and width of rectangle"<<endl;
    cin>>l>>w;
    Rec r1(l,w);
}