#include <iostream>
using namespace std;

class Shape {
public:
    virtual void info() = 0; // pure virtual function
};

class Triangle : public Shape {
private:
    int base, height;

public:
    Triangle(int b, int h) : base(b), height(h) {}

    void info() {
        cout << "This is a triangle" << endl;
    }

    friend ostream& operator<<(ostream& output, const Triangle& t) {
        output << "The area of the triangle is: " << (0.5 * t.base * t.height) << endl;
        return output;
    }
};

class Rectangle : public Shape {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w) : length(l), width(w) {}

    void info() {
        cout << "This is a rectangle" << endl;
    }

    friend ostream& operator<<(ostream& output, const Rectangle& r) {
        output << "The area of the rectangle is: " << (r.length * r.width) << endl;
        return output;
    }
};

int main() {
    int h, b;
    cout << "Enter the height of the triangle: ";
    cin >> h;
    cout << "Enter the base of the triangle: ";
    cin >> b;
    Triangle t1(b, h);

    int l, w;
    cout << "Enter the length and width of the rectangle: ";
    cin >> l >> w;
    Rectangle r1(l, w);

    // Output information and areas
    t1.info();
    cout << t1;

    r1.info();
    cout << r1;

    return 0;
}
