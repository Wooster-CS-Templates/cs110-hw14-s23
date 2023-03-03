#ifndef POINTER_PARAMETERS_H
#define POINTER_PARAMETERS_H

#include <stddef.h>

/**
 * Calculate the min, max, sum, range, and average of an array. Results are
 * returned through pointers.
 *
 * Parameters:
 *   array - the array on which to calculate the stats, must not be empty
 *   size - the number of elements in the array
 *   min - a pointer to a variable which will contain the min
 *   max - a pointer to a variable which will contain the max
 *   sum - a pointer to a variable which will contain the sum
 *   range - a pointer to a variable which will contain the range
 *   average - a pointer to a variable which will contain the average
 */
void stats(int array[], size_t size, int *min, int *max, int *sum, int *range,
           double *average);

/**
 * Swap the values of two variables using pointers.
 *
 * Parameters:
 *   a - a pointer to the first variable
 *   b - a pointer to the second variable
 */
void swap(int *a, int *b);

#endif
