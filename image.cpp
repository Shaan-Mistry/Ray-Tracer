//-----------------------------------------------------------------------------
// Shaan Mistry
// image.cpp
//
//-----------------------------------------------------------------------------

#include "color.h"
#include "image.h"
#include "vector.h"

#include <iostream>


// Class Constructors & Destructors ----------------------------------------
image::image(const int width, const int height) {
    this->width = width;
    this->height = height;
    pixels = new color *[height];
    for (int i = 0; i < height; i += 1) {
        pixels[i] = new color[width];
    }
}
image::~image() {
    for (int i = 0; i < height; i += 1) {
         delete[] pixels[i];
    }
    delete[] pixels;
}

// Manipulation procedures -------------------------------------------------
void image::set_pixel(int x, int y, color c) {
    pixels[x][y] = c;
}

// Other Functions ---------------------------------------------------------
void image::write_ppm(std::ostream &stream) const {
    // Print Header of PPM file.
    stream << "P3\n" << width << " " << height << "\n255\n";

    // Write each pixel.
    for (int i = height - 1; i >= 0; i -= 1) {
        for (int j = 0; j < width; j += 1) {
            write_color(stream, pixels[i][j]);
        }
    }
}
