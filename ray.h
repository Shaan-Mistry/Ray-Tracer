//-----------------------------------------------------------------------------
// Shaan Mistry
// ray.h
// Interface for the ray class.
//-----------------------------------------------------------------------------

#include <vector.h>

#ifndef RAY_H_INCLUDE_
#define RAY_H_INCLUDE_


class ray {

private:
    point origin;
    vector direction;

public:
    // Class Constructors & Destructors ----------------------------------------
    ray();
    ray(const point &origin, const vector &direction);

    // Access functions --------------------------------------------------------
    at(double t) const;
};

#endif