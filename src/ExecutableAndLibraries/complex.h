#ifndef zespolona_h
#define zespolona_h

#include <iostream>

using namespace std;

class Complex {
private:
    double Re;
    double Im;

public:
    Complex();
    Complex(double a, double b);

    double magnitude();
    void conjugate();

    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, const Complex& c2);
    friend Complex operator*(const Complex& c1, const Complex& c2);
    friend Complex operator/(const Complex& c1, const Complex& c2);
    friend bool operator==(const Complex& c1, const Complex& c2);

    friend ostream& operator<<(ostream& out, const Complex& c);
};

#endif
