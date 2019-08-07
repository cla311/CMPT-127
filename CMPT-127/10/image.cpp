#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image.hpp"
#include <cstddef>

// constructor
Image::Image() : cols(0), rows(0), pixels(NULL)
{
}

// destructor
Image::~Image()
{
    if (pixels != NULL)
    {
        delete[] pixels;
    }
}

/* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolour. Returns 0 on success, or a non-zero error code.*/
int Image::resize(unsigned int width, unsigned int height, uint8_t fillcolour)
{
    // delete the old pixels array
    if (pixels != NULL)
    {
        delete[] pixels;
    }

    // create new new size array
    pixels = new uint8_t[width * height];

    if (pixels != NULL)
    {
        for (int i = 0; i < width * height; i++)
        {
            // set the colour
            pixels[i] = fillcolour;
        }

        cols = width;
        rows = height;
        return 0;
    }

    return 1;
}

/* Sets the colour of the pixel at (x,y) to colour. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel(unsigned int x, unsigned int y, uint8_t colour)
{
    if (pixels != NULL)
    {
        if (x < cols && y < rows)
        {
            // index = (y*cols) + x
            pixels[y * cols + x] = colour;
            return 0;
        }
    }

    return 1;
}

/* Gets the colour of the pixel at (x,y) and stores at the address pointed to 
     by colourp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel(unsigned int x, unsigned int y, uint8_t *colourp)
{
    //check if (x,y is in range)
    if (x >= cols || y >= rows)
    {
        return 1;
    }
    //check if colourp is valid
    if (colourp == NULL)
    {
        return 1;
    }

    *colourp = pixels[y * (rows) + x];
    return 0;
}
