#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Vector {
    vector<T> elements;

public:
    Vector(){
        
    }

    void addElement(T element) {
        elements.push_back(element);
    }

    void modifyElement(int index, T newValue) {
        if (index >= 0 && index < elements.size()) {
            elements[index] = newValue;
        } else {
            std::cout << "Index out of bounds" << std::endl;
        }
    }

    void multiplyByScalar(T scalar) {
        for (int i = 0; i < elements.size(); i++) {
            elements[i] *= scalar;
        }
    }

    void display() {
        std::cout << "(";
        for (int i = 0; i < elements.size(); i++) {
            std::cout << elements[i];
            if (i < elements.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }
};

int main() {
    Vector<int> v;
    v.addElement(10);
    v.addElement(20);
    v.addElement(30);

    v.display();

    v.modifyElement(1, 25);

    v.display();

    v.multiplyByScalar(2);

    v.display();

    return 0;
}