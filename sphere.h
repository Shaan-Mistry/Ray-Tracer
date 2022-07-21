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
#include "object.h"
#include <cmath>

#ifndef SPHERE_H_INCLUDE_
#define SPHERE_H_INCLUDE_

class sphere : public object {

private:
    point center;
    double radius;

public:
std::string material;
    sphere(point center, double radius, std::string material) {
        this->center = center;
        this->radius = radius;
        this->material = material;
    }
    // Checks if the inputted ray intersects the sphere.
    // If there is an intersection, it returns the distance point from the
    // origin ray. If there is no intersection, function returns -1.
    virtual bool hit(ray &r, double t_min, double t_max, hit_record &record) const {
        vector sphere_to_ray = r.origin() - center;
        auto a = r.direction().dot_product(r.direction());
        auto b = 2 * r.direction().dot_product(sphere_to_ray);
        auto c = sphere_to_ray.dot_product(sphere_to_ray) - radius * radius;
        auto discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return false;
        }
        auto sqrtd = sqrt(discriminant);

        // Find nearest root between t_min and t_max.
        auto root = (-b - sqrt(discriminant)) / (2 * a);
        if (root < t_min || t_max < root) {
            //root = (-half_b + sqrtd) / a;
            if (root < t_min || t_max < root) {
                return false;
            }
        }
        // Update hit record values.
        record.t = root;
        record.p = r.location(rec.t);
        record.normal = (record.p - center) / radius;
        vector outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        return true;

    }
};
#endif


