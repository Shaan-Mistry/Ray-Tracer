//-----------------------------------------------------------------------------
// Shaan Mistry
// scene.h
// Stores information for the ray tracing engine.
// //-----------------------------------------------------------------------------

#ifndef SCENE_H_INCLUDE_
#define SCENE_H_INCLUDE_

#include "vector.h"

class scene {

private:
    point cam;
    int w;
    int h;
    sphere *objects;
public:
    scene(point camera, int width, int height, sphere *spheres) {
        w = width;
        h = height;
        cam = camera;
        objects = spheres;
    }
    // Access functions --------------------------------------------------------
    int width() { return w; }
    int height() { return h; }
    point camera() { return cam; }
    sphere spheres() { return *objects; }
};
#endif
