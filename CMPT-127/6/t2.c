#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.

  Make sure you validate the parameters before you use them.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json(intarr_t *ia, const char *filename)
{
    // validate the parameters
    if (ia == NULL || filename == NULL)
    {
        return 1;
    }

    // open a 'filename' file
    // 'filename' the file I want to open
    // "w" is the write mode
    FILE *f = fopen(filename, "w");

    // if f is NULL, then operation failed
    // return 1
    if (f == NULL)
    {
        return 1;
    }

    // print the js start bracket to f
    // int fprintf(FILE *stream, const char *format, ...)
    fprintf(f, "[");

    for (int i = 0; i < ia->len; i++)
    {
        fprintf(f, " %d", ia->data[i]);

        // add comma to the js array
        if (i != ia->len - 1)
        {
            fprintf(f, ",");
        }
    }

    // print the js end bracket to f
    fprintf(f, "]");

    fclose(f);
    return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_json(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t *intarr_load_json(const char *filename)
{
    // validate the parameters
    if (filename == NULL)
    {
        return NULL;
    }

    FILE *f = fopen(filename, "r");

    // if f is NULL, then operation failed
    // return NULL
    if (f == NULL)
    {
        return NULL;
    }

    unsigned int len = 0;
    // skip the first '[' char
    fseek(f, 1, SEEK_SET);
    int buffer;

    // Assume that .json file has content in below format
    // [1, 2, 3, 4, 5]
    // count numbers of elements in the array
    while (fscanf(f, "%d,", &buffer))
    {
        len++;
    }

    // create the ptr points to the new allocated arr
    intarr_t *new_arr = intarr_create(len);

    // if allocation failed
    // return NULL
    if (!new_arr)
    {
        return NULL;
    }

    // if len == 0, just return the pointer
    if (len > 0)
    {
        // seek back to beginning of file (skip '[')
        fseek(f, 1, SEEK_SET);
        int j;
        // len -1 to skip ']' char
        for (j = 0; j < len - 1; j++)
        {
            // Assume that .json file has content in below format
            // [1, 2, 3, 4, 5]
            // always %d with a comma except the last one
            fscanf(f, "%d,", &new_arr->data[j]);
        }
        // the last element in the array new_arr->data[len-1] 
        // would be a integer without comma
        fscanf(f, "%d", &new_arr->data[j]);
    }

    fclose(f);
    return new_arr;
}