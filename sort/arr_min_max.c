//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Finding min and max values in an array filled with random num (Problem MM)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define ARR_SIZE 100

void fill_arr_rand(unsigned arr[], unsigned arr_size);
void print_arr(unsigned arr[], unsigned arr_size);
void find_min_max(unsigned arr[], unsigned arr_size);

int main()
{
    srand(time(NULL));
    unsigned arr[ARR_SIZE];

    fill_arr_rand(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    find_min_max(arr, ARR_SIZE);
}

void fill_arr_rand(unsigned arr[], unsigned arr_size)
{
    for (unsigned i = 0; i < arr_size; ++i) {
        arr[i] = 1 + rand() % 99;
    }
}

void print_arr(unsigned arr[], unsigned arr_size)
{
    for (int i = 0; i < arr_size; ++i) {
        printf("%6u ", arr[i]);
        if (((i % 10) == 9) && (i != 0))
            printf("\n");
    }
    printf("\n");
}

void find_min_max(unsigned arr[], unsigned arr_size)
{
    unsigned min_val = arr[0];
    unsigned max_val = arr[0];
    for (unsigned i = 1; i < arr_size; ++i) {
        if (min_val > arr[i]) {
            min_val = arr[i];
        }
        if (max_val < arr[i]) {
            max_val = arr[i];
        }
    }
    printf("min value = %u\n", min_val);
    printf("max value = %u\n", max_val);
}
