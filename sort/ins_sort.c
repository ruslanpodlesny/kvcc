//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Insertion sort algorithm (Algorithm I)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define ARR_SIZE 100

void fill_arr(unsigned arr[], unsigned arr_size);
void fill_arr_rand(unsigned arr[], unsigned arr_size);
void print_arr(unsigned arr[], unsigned arr_size);
void swap(unsigned* a, unsigned* b);
void shuffle_arr(unsigned arr[], unsigned arr_size);
unsigned linear_search(unsigned arr[], unsigned arr_size, unsigned search_value);
void move(unsigned arr[], unsigned start_pos, unsigned len);
void ins_sort(unsigned arr[], unsigned arr_size);


int main()
{
    srand(time(NULL));
    unsigned arr[ARR_SIZE];

    fill_arr(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    
    shuffle_arr(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    
    ins_sort(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);

    fill_arr_rand(arr, ARR_SIZE);
    ins_sort(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
}

void fill_arr(unsigned arr[], unsigned arr_size)
{
    for (unsigned i = 0; i < arr_size; ++i) {
        arr[i] = i + 1;
    }
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

void swap(unsigned* a, unsigned* b) {
    unsigned tmp = *a;
    *a = *b;
    *b = tmp;
}

void shuffle_arr(unsigned arr[], unsigned arr_size) {
    unsigned j;
    for (int i = arr_size - 1; i >= 1; --i) {
        j = rand() % i;
        swap(&arr[i], &arr[j]);
    }
}

unsigned linear_search(unsigned arr[], unsigned arr_size, unsigned checked_value) {
    for (unsigned i = 0; i < arr_size; ++i) {
        if (arr[i] >= checked_value) {
            return i;
        }
    }
}

void move(unsigned arr[], unsigned start_pos, unsigned steps) {
    for (unsigned i = start_pos; steps > 0; --i, --steps) {
        arr[i] = arr[i - 1];
    }
}

void ins_sort(unsigned arr[], unsigned arr_size) {
    unsigned tmp;
    unsigned destination_pos;

    for (unsigned i = 1; i < arr_size; ++i) {
        if (arr[i] >= arr[i - 1]) {
            continue;
        }        
        destination_pos = linear_search(arr, arr_size, arr[i]); // find the first value larger or equal to sorted_value
        tmp = arr[i]; // save the value for moving to the destination position
        move(arr, i, i-destination_pos);
        arr[destination_pos] = tmp;  
    }
}