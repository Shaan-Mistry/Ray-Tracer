//-----------------------------------------------------------------------------
// Shaan Mistry
// vector.cpp
// Implementaion of the vec3 class. This class represents a 3D Vector.
//-----------------------------------------------------------------------------

#include "vector.h"
#include <cmath>
#include <iostream>

// Exported type  -------------------------------------------------------------

// Class Constructors & Destructors ----------------------------------------
vec3::vec3() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
}

vec3::vec3(double x, double y, double z) {
    e[0] = x;
    e[1] = y;
    e[2] = z;
}
vec3::~vec3(){
    return;
}

// Access functions --------------------------------------------------------

// Return x component of the current vec3.
double vec3::x() const {
    return e[0];
}
// Return y component of the current vec3.
double vec3::y() const {
    return e[1];
}
// Return z component of the current vec3.
double vec3::z() const {
    return e[2];
}

// Return the dot product of the current vec3.
double vec3::dot_product(const vec3 &v) const {
    return x() * v.x()
         + y() * v.y()
         + z() * v.z();
}

// Return the magnitude of the current vec3.
double vec3::magnitude() const {
    return std::sqrt(dot_product(*this));
}

// Overriden Operators -----------------------------------------------------

bool vec3::operator==(const vec3 &v) {
    return x() == v.x()
        && y() == v.y()
        && x() == v.y();
}

vec3& vec3::operator+=(const vec3 &v) {
    e[0] += v.x();
    e[1] += v.y();
    e[2] += v.z();
    return *this;
}

vec3& vec3::operator*=(const double a) {
    e[0] *= a;
    e[1] *= a;
    e[2] *= a;
    return *this;
}

vec3& vec3::operator/=(const double a) {
    e[0] /= a;
    e[1] /= a;
    e[2] /= a;
    return *this;
}

double vec3::operator[](int i) const {
    return e[i];
}

double& vec3::operator[](int i) {
    return e[i];
}

std::ostream& operator<<(std::ostream &stream, const vec3 &v) {
    return stream << v.x() << " " << v.y() << " " << v.z();
}


// Arithmetic Operations ---------------------------------------------------
vec3 operator+(const vec3 &u, const vec3 &v) {
   return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.y());
}
vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.y());
}
vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.y());
}
vec3 operator*(double a, const vec3 &v) {
    return vec3(a * v.x(), a * v.y(), a * v.z());
}
vec3 operator*(const vec3 &v, double a) {
    return a * v;
}
vec3 operator/(const vec3 &v, double a) {
    return (1 / a) * v;
}


