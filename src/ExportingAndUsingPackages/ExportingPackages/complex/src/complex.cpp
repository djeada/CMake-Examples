#include <cmath>

#include "complex.h"

Complex::Complex() {
    Re = 0;
    Im = 0;
}

Complex::Complex(double a, double b) {
    Re = a;
    Im = b;
}

double Complex::magnitude() {
    return sqrt(Re * Re + Im * Im);
}

void Complex::conjugate() {
    Im *= -1;
}

Complex operator+(const Complex &c1, const Complex &c2) {
    Complex c3(c1.Re + c2.Re, c1.Im + c2.Im);
    return c3;
}

Complex operator-(const Complex &c1, const Complex &c2) {
    Complex c3(c1.Re - c2.Re, c1.Im - c2.Im);
    return c3;
}

Complex operator*(const Complex &c1, const Complex &c2) {
    Complex c3(c1.Re * c2.Re - c1.Im * c2.Im, c1.Im * c2.Re + c2.Im * c1.Re);
    return c3;
}

Complex operator/(const Complex &c1, const Complex &c2) {
    double a = (c1.Re * c2.Re + c1.Im * c2.Im) / (c2.Re * c2.Re + c2.Im * c2.Im);
    double b = (c1.Re * c2.Im - c1.Im * c2.Re) / (c2.Re * c2.Re + c2.Im * c2.Im);
    Complex c3(a, b);
    return c3;
}

ostream &operator<<(ostream &out, const Complex &c) {
    if (c.Im >= 0)
        cout << c.Re << " + j" << c.Im << endl;
    else
        cout << c.Re << " - j" << abs(c.Im) << endl;
    return out;
}

bool operator==(const Complex &c1, const Complex &c2) {
    return c1.Re == c2.Re && c1.Im == c2.Im;
}
