//-----------------------------------------------------------------------------
// Shaan Mistry
// vector.cpp
// Implementaion of the vector class. This class represents a 3D Vector.
//-----------------------------------------------------------------------------

#include "vector.h"
#include <cmath>
#include <iostream>

// Class Constructors & Destructors ----------------------------------------
vector::vector() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
}

vector::vector(double x, double y, double z) {
    e[0] = x;
    e[1] = y;
    e[2] = z;
}
vector::~vector(){
    return;
}

// Access functions --------------------------------------------------------

// Return x component of the current vector.
double vector::x() const {
    return e[0];
}
// Return y component of the current vector.
double vector::y() const {
    return e[1];
}
// Return z component of the current vector.
double vector::z() const {
    return e[2];
}

// Return the dot product of the current vector.
double vector::dot_product(const vector &v) const {
    return x() * v.x()
         + y() * v.y()
         + z() * v.z();
}

// Return the magnitude of the current vector.
double vector::magnitude() const {
    return std::sqrt(dot_product(*this));
}

vector vector::normalized() const {
    double mag = magnitude();
    return vector(x() / mag, y() / mag, z() / mag);
}

// Overriden Operators -----------------------------------------------------

bool vector::operator==(const vector &v) {
    return x() == v.x()
        && y() == v.y()
        && x() == v.y();
}

vector& vector::operator+=(const vector &v) {
    e[0] += v.x();
    e[1] += v.y();
    e[2] += v.z();
    return *this;
}

vector& vector::operator*=(const double a) {
    e[0] *= a;
    e[1] *= a;
    e[2] *= a;
    return *this;
}

vector& vector::operator/=(const double a) {
    e[0] /= a;
    e[1] /= a;
    e[2] /= a;
    return *this;
}

double vector::operator[](int i) const {
    return e[i];
}

double& vector::operator[](int i) {
    return e[i];
}

std::ostream& operator<<(std::ostream &stream, const vector &v) {
    return stream << v.x() << " " << v.y() << " " << v.z();
}

// Arithmetic Operations ---------------------------------------------------
vector operator+(const vector &u, const vector &v) {
   return vector(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}
vector operator-(const vector &u, const vector &v) {
    return vector(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}
vector operator*(const vector &u, const vector &v) {
    return vector(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}
vector operator*(double a, const vector &v) {
    return vector(a * v.x(), a * v.y(), a * v.z());
}
vector operator*(const vector &v, double a) {
    return a * v;
}
vector operator/(const vector &v, double a) {
    return (1 / a) * v;
}


