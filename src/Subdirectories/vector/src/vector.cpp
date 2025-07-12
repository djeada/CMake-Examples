#include "vector.h"
#include <cmath>

Vector::Vector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

void Vector::setX(double _x) {
    x = _x;
}

void Vector::setY(double _y) {
    y = _y;
}

void Vector::setZ(double _z) {
    z = _z;
}

double Vector::getX() {
    return x;
}

double Vector::getY() {
    return y;
}

double Vector::getZ() {
    return z;
}

double Vector::magnitude() {
    double squareX = pow(x, 2);
    double squareY = pow(y, 2);
    double squareZ = pow(z, 2);

    return sqrt(squareX + squareY + squareZ);
}

Vector operator+(const Vector &v1, const Vector &v2) {
    Vector w3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    return w3;
}

Vector operator-(const Vector &v1, const Vector &v2) {
    Vector w3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    return w3;
}

Vector operator*(const Vector &v1, const Vector &v2) {
    double x = v1.y * v2.z - v1.z * v2.y;
    double y = v1.z * v2.x - v1.x * v2.z;
    double z = v1.x * v2.y - v1.y * v2.x;

    return Vector(x, y, z);
}

std::ostream &operator<<(std::ostream &out, Vector &w) {
    std::cout << "X = " << w.x << std::endl;
    std::cout << "Y = " << w.y << std::endl;
    std::cout << "Z = " << w.z << std::endl;
    return out;
}

bool operator==(const Vector &v1, const Vector &v2) {
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

bool operator!=(const Vector &v1, const Vector &v2) {
    return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z;
}
