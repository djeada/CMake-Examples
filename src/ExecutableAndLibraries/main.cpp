#include "complex.h"
#include "vector.h"
#include <iostream>

int main() {

    Complex c1;
    Complex c2(9, 12);

    std::cout << c1;
    std::cout << c2;

    std::cout << c1 * c2;

    Complex c3(-3, -3);

    std::cout << c3 + c2;
    std::cout << c3 / c2;

    c2.conjugate();

    std::cout << c2;

    std::cout << c3.magnitude() << std::endl;

    Vector vectorA(5, 5, 5);
    Vector vectorB(-3, -3, -3);

    auto sum = vectorA + vectorB;
    auto diff = vectorA - vectorB;
    auto crossProd = vectorA * vectorB;

    std::cout << "For vectors: A \n"
              << vectorA << "and B \n"
              << vectorB << "sum: \n"
              << sum << "difference: \n"
              << diff << "cross product: \n"
              << crossProd << std::endl;

    return 0;
}
