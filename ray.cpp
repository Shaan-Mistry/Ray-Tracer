//-----------------------------------------------------------------------------
// Shaan Mistry
// ray.h
// Interface for the ray class.
//-----------------------------------------------------------------------------

#include "ray.h"




ray::ray() {
    origin = point();
    direction = vector();
}
ray::ray(const point &origin, const vector &direction){
    this->origin = origin;
    this->direction = direction;
}

point ray::location(double t) const {
    return origin + t * direction;

}

