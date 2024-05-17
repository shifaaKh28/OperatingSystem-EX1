#include <limits.h>  // For INT_MIN
#include <stdio.h>   // For printf and fprintf
#include <stdlib.h>  // For atoi, malloc, free, and srand
#include <time.h>    // For time (if needed for srand)

// Constants for the minimum and maximum values in the array
#define MIN_VAL -25
#define MAX_VAL 74

/**
 * Brute Force Algorithm O(n^3) to find the maximum subarray sum.
 *
 * @param array Pointer to the array of integers.
 * @param size The size of the array.
 * @return The maximum sum of any contiguous subarray.
 */
int max_subarray_sum_n3(int *array, int size) {
    int best = MIN_VAL;
    for (int a = 0; a < size; a++) {
        for (int b = a; b < size; b++) {
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += array[k];
            }
            if (sum > best) {
                best = sum;
            }
        }
    }
    return best;
}

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments are provided
    if (argc != 3) {
        printf("Usage: %s <random_seed> <array_size>\n", argv[0]);
        return 1;
    }

    // Convert command-line arguments to integers
    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    // Allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the random number generator with the provided seed
    srand(seed);
    printf("Generated array: ");
    for (int i = 0; i < size; i++) {
        // Generate random numbers within the range [MIN_VAL, MAX_VAL]
        array[i] = MIN_VAL + rand() % (MAX_VAL - MIN_VAL + 1);
        printf("%d ", array[i]);  // Print the generated array
    }
    printf("\n");

    // Calculate the maximum subarray sum using the O(n^3) algorithm
    int result = max_subarray_sum_n3(array, size);
    printf("Max Subarray sum using Algorithm 1 is: %d\n", result);

    // Free the allocated memory
    free(array);

    return 0;
}
