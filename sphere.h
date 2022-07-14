//-----------------------------------------------------------------------------
// Shaan Mistry
// sphere.h
// Module for rendering 3D spheres on a 2D plane.
//-----------------------------------------------------------------------------

//  Ray-Sphere Intersection Formulas
//  a = ray_direction * ray_direction
//  b = 2 * ray_direction * sphere_to_ray
//  c = sphere_to_ray * sphere_to_ray - radius^2
//  discriminant = b^2 - 4ac
//
//  discriminant > 0: Intersection at 2 points
//  discriminant = 0: Intersection at 1 point
//  discriminant < 0: No intersection
//
//  Distance to point of intersection from origin ray.
//  dist = (-b - sqrt(discriminant)) / 2a

#include "ray.h"
#include <cmath>

#ifndef SPHERE_H_INCLUDE_
#define SPHERE_H_INCLUDE_

class sphere {

private:
    point center;
    double radius;
    std::string material;

public:
    sphere(point center, double radius, std::string material) {
        this->center = center;
        this->radius = radius;
        this->material = material;
    }
    // Checks if the inputted ray intersects the sphere.
    // If there is an intersection, it retunrs the distance point from the
    // origin ray. If there is no intersection, function returns -1.
    double intersects(ray r) {
        vector sphere_to_ray = r.origin() - center;
        auto a = r.direction().dot_product(r.direction());
        auto b = 2.0 * r.direction().dot_product(sphere_to_ray);
        auto c = sphere_to_ray.dot_product(sphere_to_ray) - radius * radius;
        auto discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return -1.0;
        } else {
            return (-b - sqrt(discriminant)) * 2.0 * a;
        }
    }
};
#endif


