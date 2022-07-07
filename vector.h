//-----------------------------------------------------------------------------
// Shaan Mistry
// vector.h
// Interface for the vector class.
//-----------------------------------------------------------------------------

#ifndef VECTOR_H_INCLUDE_
#define VECTOR_H_INCLUDE_

#include <ostream>

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

    // Overriden Operators -----------------------------------------------------
    bool operator==(const vector &v);
    vector &operator+=(const vector &v);
    vector &operator*=(const double a);
    vector &operator/=(const double a);
    double operator[](int i) const;
    double &operator[](int i);

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
