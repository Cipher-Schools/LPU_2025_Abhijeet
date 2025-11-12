#include <iostream>
#include <cmath>
using namespace std;

class Complex {
public:
    double real;
    double img;

    // Constructor
    Complex(double real = 0, double img = 0) {
        this->real = real;
        this->img = img;
    }

    // Addition
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, img + other.img);
    }

    // Subtraction
    Complex operator-(const Complex &other) const {
        return Complex(real - other.real, img - other.img);
    }

    // Multiplication
    Complex operator*(const Complex &other) const {
        return Complex(real * other.real - img * other.img,
                       real * other.img + img * other.real);
    }

    // Equality
    bool operator==(const Complex &other) const {
        return (real == other.real && img == other.img);
    }

    // Inequality
    bool operator!=(const Complex &other) const {
        return !(*this == other);
    }

    // Magnitude (for comparison)
    double magnitude() const {
        return sqrt(real * real + img * img);
    }

    // Comparison based on magnitude
    bool operator<(const Complex &other) const {
        return magnitude() < other.magnitude();
    }

    bool operator>(const Complex &other) const {
        return magnitude() > other.magnitude();
    }

    bool operator<=(const Complex &other) const {
        return magnitude() <= other.magnitude();
    }

    bool operator>=(const Complex &other) const {
        return magnitude() >= other.magnitude();
    }

    // Print function
    void print() const {
        if (img >= 0)
            cout << real << " + " << img << "i" << endl;
        else
            cout << real << " - " << -img << "i" << endl;
    }
};

int main() {
    Complex *n1 = new Complex(10, 2);
    Complex *n2 = new Complex(-3, 4);

    Complex n3 = *n1 + *n2;
    Complex n4 = *n1 * *n2;

    cout << "n1 = "; n1->print();
    cout << "n2 = "; n2->print();

    cout << "\nAddition: ";
    n3.print();

    cout << "Multiplication: ";
    n4.print();

    cout << "\nComparisons:\n";
    cout << "n1 == n2 ? " << ((*n1 == *n2) ? "true" : "false") << endl;
    cout << "n1 != n2 ? " << ((*n1 != *n2) ? "true" : "false") << endl;
    cout << "n1 > n2 ? " << ((*n1 > *n2) ? "true" : "false") << endl;
    cout << "n1 < n2 ? " << ((*n1 < *n2) ? "true" : "false") << endl;

    delete n1;
    delete n2;

    return 0;
}
