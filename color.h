//-----------------------------------------------------------------------------
// Shaan Mistry
// color.h
// Interface for writing RBG colors in PPM format.
//-----------------------------------------------------------------------------

#include "vector.h"
#include <iostream>

#ifndef COLOR_H_INCLUDE_
#define COLOR_H_INCLUDE_

void write_color(std::ostream &stream, color pixel_color) {
    stream << (int) (255.999 * pixel_color.x()) << " "
           << (int) (255.999 * pixel_color.y()) << " "
           << (int) (255.999 * pixel_color.z()) << "\n";
}

#endif
