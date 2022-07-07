//-----------------------------------------------------------------------------
// Shaan Mistry
// image.h
// Interface for creating an image.
//-----------------------------------------------------------------------------

#include <iostream>

#ifndef IMAGE_H_INCLUDE_
#define IMAGE_H_INCLUDE_

// Exported type  -------------------------------------------------------------
class image {
    private:
        int width;
        int height;
        color **pixels;

    public:
    // Class Constructors & Destructors ----------------------------------------
    image(int width, int height);
    ~image();

    // Manipulation procedures -------------------------------------------------
    void set_pixel(int x, int y, color c);

    // Other Functions ---------------------------------------------------------
   void write_ppm(std::ostream &stream) const;
};
#endif



