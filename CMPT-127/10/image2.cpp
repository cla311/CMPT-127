#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image2.hpp"

// constructor
Image::Image() : cols(0), rows(0), pixels(NULL)
{
}

// destructor
Image ::~Image()
{
    if (pixels != NULL)
    {
        delete[] pixels;
    }
}

/* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/
int Image ::resize(unsigned int width, unsigned int height, uint8_t fillcolour)
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

/* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image ::set_pixel(unsigned int x, unsigned int y, uint8_t colour)
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

/* Gets the color of the pixel at (x,y) and stores at the address pointed to 
     by colorp. Returns 0 on success, else a non-zero error code. */
int Image ::get_pixel(unsigned int x, unsigned int y, uint8_t* colourp)
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

/* Saves the image in the file filename. In a format that can be
     loaded by load().  Returns 0 on success, else a non-zero error
     code. */
int Image ::save(const char *filename)
{
    //write the contents of filename into a format that can be saved and loaded
    //LAB 6 has most of algorithm
    printf("i got here\n");
    if (filename == NULL)
    {
        return 1;
    }
    printf("I got to this part\n");

    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("failed to open\n");
        return 1;
    }
    //if image is blank write a blank file
    if (this->pixels == NULL)
    {
        fclose(f);
        return 0;
        printf("empty file\n");
    }
    //write onto f from contents of filename
    //write len, cols, rows, pixel info
    int len = (this->cols * this->rows);
    fwrite(&len, sizeof(int), 1, f);
    printf("wrote len\n");

    fwrite(&(this->rows), sizeof(int), 1, f);
    printf("wrote rows\n");

    fwrite(&(this->cols), sizeof(int), 1, f);
    printf("wrote cols\n");

    fwrite(this->pixels, sizeof(uint8_t), len, f);
    printf("wrote pixels\n");

    fclose(f);
    return 0;
}

/* Load the an image from the file filename, replacing the current
     image size and data. The file is in a format that was saved by
     save().  Returns 0 success, else a non-zero error code . */
int Image::load(const char *filename)
{
    if (filename == NULL)
    {
        return 1;
    }

    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        return 1;
    }
    //read from filename replacing data/pixels
    int len2 = 0;
    //check length if 0, reset and return
    fread(&len2, sizeof(int), 1, f);
    if (len2 == 0)
    { //empty filename
        this->cols = 0;
        this->rows = 0;
        this->pixels = NULL;
        fclose(f);
        return 0;
    }
    //read and store row/col vals
    //should not be 0, empty already dealt with
    int row2 = 0;
    int col2 = 0;
    fread(&row2, sizeof(int), 1, f);
    fread(&col2, sizeof(int), 1, f);

    //resize pixel size based off filename pixel size
    this->resize(col2, row2, 0);
    fread(this->pixels, sizeof(uint8_t), len2, f);
    if (this->pixels == NULL)
    {
        return 1;
    }

    fclose(f);
    return 0;
}