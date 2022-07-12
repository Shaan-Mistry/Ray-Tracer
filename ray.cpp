//-----------------------------------------------------------------------------
// Shaan Mistry
// ray.cpp
// Implementation the ray class.
//-----------------------------------------------------------------------------

#include "ray.h"

ray::ray() {
    orig = point();
    dir = vector();
}
ray::ray(const point &origin, const vector &direction){
    orig = origin;
    dir = direction;
}

point ray::origin() const {
    return orig;
}

vector ray::direction() const {
    return dir;
}

point ray::location(double t) const {
    return orig + t * dir;
}

color ray::ray_color() const {
    vector unit_dir = dir.normalized();
    double t = 0.5 * (unit_dir.y() + 1.0);
    return (1.0 - t) * color(1, 1, 1) + t * color(0.5, 0.7, 1.0);
}
