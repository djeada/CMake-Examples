#include <iostream>

class Vector {
public:
    Vector(double x = 0, double y = 0, double z = 0);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    double getX();
    double getY();
    double getZ();
    double magnitude();
    friend Vector operator+(const Vector& v1, const Vector& v2);
    friend Vector operator-(const Vector& v1, const Vector& v2);
    friend Vector operator*(const Vector& v1, const Vector& v2);
    friend std::ostream& operator<<(std::ostream& out, Vector& w);
    friend bool operator==(const Vector& p1, const Vector& p2);
    friend bool operator!=(const Vector& p1, const Vector& p2);

private:
    double x, y, z;
};
