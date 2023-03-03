#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pointer_parameters.h"

// Print an array with the following form: {1,2,3}
void print_array(int array[], int size);

// Test the simple_stats functions for an array and print the results.
void test_array(int array[], int size, int expected_min, int expected_max,
                int expected_sum, int expected_range, double expected_average);

void test_swap(int x, int y);

int main() {
    printf("Testing stats()\n");
    int ascending[] = {1, 2, 3};
    test_array(ascending, 3, 1, 3, 6, 2, 2.0);

    int descending[] = {3, 2, 1};
    test_array(descending, 3, 1, 3, 6, 2, 2.0);

    int max_repeated[] = {2, -4, 10, 3, 10};
    test_array(max_repeated, 5, -4, 10, 21, 14, 4.2);

    int min_repeated[] = {5, -100, 2, -100};
    test_array(min_repeated, 4, -100, 5, -193, 105, -48.25);

    int all_same[] = {1, 1, 1};
    test_array(all_same, 3, 1, 1, 3, 0, 1.0);

    int one[] = {1};
    test_array(one, 1, 1, 1, 1, 0, 1.0);

    printf("\nTesting swap()...");
    test_swap(1, 2);
    test_swap(1, 1);
    test_swap(2, 1);
    printf("PASSED!\n");
    
    return 0;
}

void print_array(int array[], int size) {
    printf("{");

    for(int i = 0; i < size; i++) {
        printf("%i", array[i]);
        if(i != size - 1)
            printf(",");
    }

    printf("}");
}

void test_array(int array[], int size, int expected_min, int expected_max,
                int expected_sum, int expected_range, double expected_average) {
    printf("Array: ");
    print_array(array, size);
    printf("...");

    int min, max, sum, range;
    double average;

    stats(array, size, &min, &max, &sum, &range, &average);

    if(min != expected_min) {
        printf("ERROR: expected %i for min but got %i\n", expected_min, min);
        exit(1);
    }

    if(max != expected_max) {
        printf("ERROR: expected %i for max but got %i\n", expected_max, max);
        exit(1);
    }

    if(sum != expected_sum) {
        printf("ERROR: expected %i for sum but got %i\n", expected_sum, sum);
        exit(1);
    }

    if(range != expected_range) {
        printf("ERROR: expected %i for range but got %i\n", expected_range, range);
        exit(1);
    }

    if(average != expected_average) {
        printf("ERROR: expected %lf for average but got %lf\n", expected_average, average);
        exit(1);
    }

    printf("PASSED!\n");
}

void test_swap(int x, int y) {
    int original_x = x;
    int original_y = y;

    swap(&x, &y);

    if(x != original_y || y != original_x) {
        printf("\nTried swapping values of variables containing %i and %i\n",
               original_x, original_y);
        printf("Expected the values to be %i and %i after swapping\n",
               original_y, original_x);
        printf("Instead they were %i and %i\n", x, y);
        exit(1);
    }
}

    
