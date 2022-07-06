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

color ray::ray_color() const {
    vector unit_direction = direction / direction.magnitude();
    double t = 0.5 * (unit_direction.y() + 1);
     return (1.0 - t) * color(1, 1, 1) + t * color(0.5, 0.7, 1.0);
}


