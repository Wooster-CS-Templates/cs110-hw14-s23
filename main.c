#include <stdio.h>

#include "pointer_parameters.h"

int main() {
    size_t array_size;

    printf("Enter the size of the array: ");
    scanf("%zu", &array_size);

    int array[array_size];

    printf("Enter the values of the array: ");

    for(size_t i = 0; i < array_size; i++) {
        scanf("%i", &array[i]);
    }

    int min, max, sum, range;
    double average;

    stats(array, array_size, &min, &max, &sum, &range, &average);

    printf("Max: %i\n", max);
    printf("Min: %i\n", min);
    printf("Sum: %i\n", sum);
    printf("Average: %lf\n", average);
    printf("Range: %i\n", range);

    // Write your own code to test swap() here. Create 2 int variables, get
    // values for them from the user, call swap on their addresses, and print
    // them out to verify that the values were swapped.

    return 0;
}
