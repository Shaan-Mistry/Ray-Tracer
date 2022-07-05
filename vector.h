//-----------------------------------------------------------------------------
// Shaan Mistry
// vector.h
// Interface for the vec3 class.
//-----------------------------------------------------------------------------

#include <string>

#ifndef VECTOR_H_INCLUDE_
#define VECTOR_H_INCLUDE_

// Exported type  -------------------------------------------------------------
class vec3 {

private:
    double e[3];
public:
    // Class Constructors & Destructors ----------------------------------------
    vec3();
    vec3(double x, double y, double z);
    ~vec3();

    // Access functions --------------------------------------------------------
    double x() const;
    double y() const;
    double z() const;
    double magnitude() const;
    double dot_product(const vec3 &v) const;

    // Overriden Operators -----------------------------------------------------
    bool operator==(const vec3 &v);
    vec3& operator+=(const vec3 &v);
    vec3& operator*=(const double a);
    vec3& operator/=(const double a);
    double operator[](int i) const;
    double& operator[](int i);

    friend std::ostream& operator<<(std::ostream &stream, const vec3 &v);
    friend vec3 operator+(const vec3 &u, const vec3 &v);
    friend vec3 operator-(const vec3 &u, const vec3 &v);
    friend vec3 operator*(const vec3 &u, const vec3 &v);
    friend vec3 operator*(double a, const vec3 &v);
    friend vec3 operator*(const vec3 &v, double a);
    friend vec3 operator/(const vec3 &v, double a);
};
using color = vec3;
#endif
