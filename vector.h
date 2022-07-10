//-----------------------------------------------------------------------------
// Shaan Mistry
// vector.h
// Interface for the vector class.
//-----------------------------------------------------------------------------

#include <ostream>

#ifndef VECTOR_H_INCLUDE_
#define VECTOR_H_INCLUDE_

class vector {

private:
    double e[3];
public:
    // Class Constructors & Destructors ----------------------------------------
    vector();
    vector(double x, double y, double z);
    ~vector();

    // Access functions --------------------------------------------------------
    double x() const;
    double y() const;
    double z() const;

    double magnitude() const;
    double dot_product(const vector &v) const;
    vector normalized() const;

    // Overriden Operators -----------------------------------------------------
    bool operator==(const vector &v);
    vector &operator+=(const vector &v);
    vector &operator*=(const double a);
    vector &operator/=(const double a);
    double operator[](int i) const;
    double &operator[](int i);

    // Arithmetic Operations ---------------------------------------------------
    friend std::ostream& operator<<(std::ostream &stream, const vector &v);
    friend vector operator+(const vector &u, const vector &v);
    friend vector operator-(const vector &u, const vector &v);
    friend vector operator*(const vector &u, const vector &v);
    friend vector operator*(double a, const vector &v);
    friend vector operator*(const vector &v, double a);
    friend vector operator/(const vector &v, double a);
};
using color = vector;
using point = vector;
#endif

/*
#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vector {
    public:
        vector() : e{0,0,0} {}
        vector(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vector operator-() const { return vector(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        vector& operator+=(const vector &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vector& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vector& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length() const {
            return sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

    public:
        double e[3];
};

// Type aliases for vector
using point = vector;   // 3D point
using color = vector;    // RGB color

// vector Utility Functions

inline std::ostream& operator<<(std::ostream &out, const vector &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vector operator+(const vector &u, const vector &v) {
    return vector(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vector operator-(const vector &u, const vector &v) {
    return vector(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vector operator*(const vector &u, const vector &v) {
    return vector(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vector operator*(double t, const vector &v) {
    return vector(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vector operator*(const vector &v, double t) {
    return t * v;
}

inline vector operator/(vector v, double t) {
    return (1/t) * v;
}

inline double dot(const vector &u, const vector &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vector cross(const vector &u, const vector &v) {
    return vector(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vector unit_vector(vector v) {
    return v / v.length();
}
#endif

*/
