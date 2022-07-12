//-----------------------------------------------------------------------------
// Shaan Mistry
// ray.h
// Interface for the ray class.
//-----------------------------------------------------------------------------


#include "vector.h"

#ifndef RAY_H_INCLUDE_
#define RAY_H_INCLUDE_

class ray {

private:
    point orig;
    vector dir;

public:
    // Class Constructors & Destructors ----------------------------------------
    ray();
    ray(const point &origin, const vector &direction);

    // Access functions --------------------------------------------------------
    point origin() const;
    vector direction() const;

    // Other Functions ---------------------------------------------------------
    point location(double t) const;
    color ray_color() const;
};

#endif
