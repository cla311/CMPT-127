#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.

  Make sure you validate the parameters before you use them.
*/

// return 0 means succeed, return 1 means fails
int intarr_save_binary(intarr_t *ia, const char *filename)
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

    // if array length is 0
    // output an empty array
    // operation succeed, return 0
    if (ia->len == 0)
    {
        fclose(f);
        return 0;
    }

    // size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
    // ptr points to the input file - ia->data
    // size is sizeof(elements type in ptr) - sizeof(int)
    // count is the number of elements in inputfile - ia->len
    // steam points to the output file - f
    // it returns The total number of elements successfully written into the output file
    // if the return values do not match with ia->len
    // operation failed
    // return 1
    // otherwise operation succeed
    // return 0
    if (fwrite(ia->data, sizeof(int), ia->len, f) != ia->len)
    {
        return 1;
    }

    fclose(f);
    return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.

  Make sure you validate the parameter before you use it.
*/

intarr_t *intarr_load_binary(const char *filename)
{
    // validate the parameters
    if (filename == NULL)
    {
        return NULL;
    }

    // open the filename file
    // read mode
    FILE *f = fopen(filename, "r");

    if (f == NULL)
    {
        return NULL;
    }

    // seek to end of file
    fseek(f, 0, SEEK_END);
    // get current file pointer
    int size = ftell(f) / sizeof(int);
    // seek back to beginning of file
    fseek(f, 0, SEEK_SET);

    intarr_t *new_arr = intarr_create(size);

    // size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
    // ptr points to a block of memory with a size * count bytes -> new_arr->data
    // size is each element to be read ->sizeof(int)
    // count is number of elements to read -> size
    // steaem points to the input file -> f
    // it returns the total number of elements successfully read from the 'filename'
    if (fread(new_arr->data, sizeof(int), size, f) != new_arr->len)
    {
        return NULL;
    }

    fclose(f);
    return new_arr;
}
