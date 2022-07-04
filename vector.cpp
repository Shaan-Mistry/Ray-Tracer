//-----------------------------------------------------------------------------
// Shaan Mistry
// vec3.cpp
// Implementtaion of a 3D Vector.
//-----------------------------------------------------------------------------
#include "vector.h"
#include <cmath>

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

vec3::~vec3() {
    return;
}

// Access functions --------------------------------------------------------

// Return the dot product of the current vec3.
double vec3::dot_product(const vec3 &V) const {
    return e[0] * V.e[0] + e[1] * V.e[1] + e[2] * V.e[2];
}

// Return the magnitude of the current vec3.
double vec3::magnitude() const {
    return std::sqrt(dot_product(*this));
}


// Overriden Operators -----------------------------------------------------

bool vec3::operator==(const vec3 &V) {
    return e[0] == V.e[0] && e[1] == V.e[1] && e[0] == V.e[0];
}

vec3& vec3::operator+=(const vec3 &V) {
    e[0] += V.e[0];
    e[1] += V.e[1];
    e[2] += V.e[2];
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
std::ostream& operator<<(std::ostream &stream, const vec3 &V) {
    std::string s = "{";
    s.append(std::to_string(V.e[0]));
    s.append(", ");
    s.append(std::to_string(V.e[1]));
    s.append(", ");
    s.append(std::to_string(V.e[2]));
    s.append("}");
    return stream << s;
}



