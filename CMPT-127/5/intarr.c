/* 
 * intarr.c
 *
 * Provides a bounds-checked, resizable array of integers with
 * random-access and stack interfaces, and several utility functions
 * that operate on them.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "intarr.h"

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t *intarr_create(unsigned int len)
{
    assert(len >= 0);
    intarr_t *ptr = malloc(sizeof(intarr_t));
    if (ptr != NULL)
    {
        // make sure pointer data also is not NULL
        ptr->data = malloc(len * sizeof(int));
        if (ptr->data != NULL)
        {
            ptr->len = len;
            return ptr;
        }
    }
    return NULL;
}

// Frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy(intarr_t *ia)
{
    if (ia != NULL && ia->data != NULL)
    {
        free(ia);
    }
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set(intarr_t *ia,
                           unsigned int index,
                           int val)
{
    if (ia != NULL)
    {
        if (index >= 0 && index < ia->len)
        {
            ia->data[index] = val;
            return INTARR_OK;
        }
        return INTARR_BADINDEX;
    }
    return INTARR_BADARRAY;
}

// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get(const intarr_t *ia,
                           unsigned int index,
                           int *val)
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    if (index >= 0 && index < ia->len && val != NULL)
    {
        *val = ia->data[index];
        return INTARR_OK;
    }

    return INTARR_BADINDEX;
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t *intarr_copy(const intarr_t *ia)
{
    if (ia == NULL)
    {
        return NULL;
    }

    intarr_t *duplicate = malloc(sizeof(intarr_t));

    if (duplicate != NULL)
    {
        duplicate->len = ia->len;

        // allocate a new pointer to perform a deep copy
        int numBytes = duplicate->len * sizeof(int);
        duplicate->data = malloc(numBytes);

        if (duplicate->data != NULL)
        {
            // copy numbytes from the orginal pointer to the new pointer
            memcpy(duplicate->data, ia->data, numBytes);
            return duplicate;
        }
    }

    return NULL;
}

/* LAB 5 TASK 4 */

// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_sort(intarr_t *ia)
{
    // bubble sort
    if (ia != NULL)
    {
        for (int i = 0; i < ia->len - 1; i++)
        {
            for (int j = 0; j < ia->len - 1 - i; j++)
            {
                if (ia->data[j] > ia->data[j + 1])
                {
                    // swap value for data[i] and data[i+1]
                    int temp = ia->data[j];
                    ia->data[j] = ia->data[j + 1];
                    ia->data[j + 1] = temp;
                }
            }
        }
        return INTARR_OK;
    }
    return INTARR_BADARRAY;
}

/* LAB 5 TASK 5 */

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find(intarr_t *ia, int target, int *i)
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }

    for (int index = 0; index < ia->len; index++)
    {
        if (target == ia->data[index])
        {
            *i = index;
            return INTARR_OK;
        }
    }

    return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// HINT: First, do TASK 7, since you will need to resize your array
//       by +1 in order to successfully push val.
// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push(intarr_t *ia, int val)
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }

    intarr_result_t result = intarr_resize(ia, ia->len + 1);
    if (result == INTARR_OK)
    {
        ia->data[ia->len - 1] = val;
        return INTARR_OK;
    }

    return INTARR_BADALLOC;
}

// HINT: You will need to decrement len so that it always represents
//       the number of int's stored in the array data.
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop(intarr_t *ia, int *i)
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }

    // array is empty
    if (ia->len == 0 || ia->data == NULL)
    {
        return INTARR_BADINDEX;
    }

    int temp = ia->data[ia->len - 1];
    // intarr_result_t result = intarr_resize(ia, ia->len - 1);

    ia->len--;

    // printf("Test: %d\n",result);

    // if (result == INTARR_OK)
    // {
    if (i != NULL)
    {
        *i = temp;
        // printf("INTARR_OK\n");
        return INTARR_OK;
    }
    // }
    return INTARR_OK;
    // return result;
}

/* LAB 5 TASK 7 */

// HINT: Do this task before doing TASK 6.
// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded.
// If newlen is greater than the original array length, the values
// of the new integers will be undefined
// (see https://en.cppreference.com/w/c/memory/realloc).
// If the allocation is successful, return INTARR_OK, otherwise
// return INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_resize(intarr_t *ia, unsigned int newlen)
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }

    // realloc is used to changed the size, and it returns a void pointer
    int original_len = ia->len;
    ia->data = (int *)realloc(ia->data, sizeof(int) * newlen);

    if (ia->data != NULL)
    {
        if (newlen < original_len)
        {
            ia->len = newlen;
        }
        else if (newlen > original_len)
        {
            for (int i = original_len; i < newlen; i++)
            {
                ia->len = newlen;
                ia->data[i] = 0;
            }
        }
        return INTARR_OK;
    }
    return INTARR_BADALLOC;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index 'first' to index 'last'
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, 'first' or 'last' are out of bounds,
// 'last' < 'first', or memory allocation fails, return a null pointer.
intarr_t *intarr_copy_subarray(intarr_t *ia,
                               unsigned int first,
                               unsigned int last)
{
    if (ia == NULL || first > ia->len || last > ia->len || last < first || first < 0)
    {
        return NULL;
    }

    intarr_t *copy = malloc(sizeof(intarr_t));

    if (copy == NULL)
    {
        return NULL;
    }

    int newlen = last - first + 1;
    copy->len = newlen;
    copy->data = malloc(newlen * sizeof(int));

    if (copy->data == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < newlen; i++)
    {
        copy->data[i] = ia->data[first];
        first++;
    }
    return copy;
}
