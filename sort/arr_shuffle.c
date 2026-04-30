//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Shuffle an array using Fisher-Yates algorithm (Problem FY)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define ARR_SIZE 100

void fill_arr(unsigned arr[], unsigned arr_size);
void print_arr(unsigned arr[], unsigned arr_size);
void swap(unsigned* a, unsigned* b);
void shuffle_arr(unsigned arr[], unsigned arr_size);

int main()
{
    srand(time(NULL));
    unsigned arr[ARR_SIZE];

    fill_arr(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    shuffle_arr(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
}

void fill_arr(unsigned arr[], unsigned arr_size)
{
    for (unsigned i = 0; i < arr_size; ++i) {
        arr[i] = i+1;
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

void swap(unsigned* a, unsigned* b) {
    unsigned tmp = *a;
    *a = *b;
    *b = tmp;
}

void shuffle_arr(unsigned arr[], unsigned arr_size){
    unsigned j;
    for (int i = arr_size-1 ;i >= 1; --i) {
        j = rand() % i;
        swap(&arr[i], &arr[j]);        
    }
}
