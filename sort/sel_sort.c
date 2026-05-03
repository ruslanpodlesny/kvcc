//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Selection sort algorithm (Algorithm SE)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define ARR_SIZE 50

void fill_arr(unsigned arr[], unsigned arr_size);
void fill_arr_rand(unsigned arr[], unsigned arr_size);
void print_arr(unsigned arr[], unsigned arr_size);
void swap(unsigned* a, unsigned* b);
void shuffle_arr(unsigned arr[], unsigned arr_size);
unsigned find_min(unsigned arr[], unsigned arr_size, unsigned start_pos);
void sel_sort(unsigned arr[], unsigned arr_size);


int main()
{
    srand(time(NULL));
    unsigned arr[ARR_SIZE];

    fill_arr(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    shuffle_arr(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    sel_sort(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);

    fill_arr_rand(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    sel_sort(arr, ARR_SIZE);
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
        printf("%3u ", arr[i]);
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

unsigned find_min(unsigned arr[], unsigned arr_size, unsigned start_pos) {
    unsigned min_val = arr[start_pos];
    unsigned min_val_pos = start_pos;
    for (unsigned i = start_pos; i < arr_size; ++i) {
        if (arr[i] < min_val) {
            min_val=arr[i];
            min_val_pos = i;
        }
    }
    return min_val_pos;
}

void sel_sort(unsigned arr[], unsigned arr_size) {
    unsigned min_val_pos;
    unsigned min_val;
    for (unsigned i = 0; i < arr_size; ++i) {
        min_val_pos = find_min(arr, arr_size, i);
        swap(&arr[i], &arr[min_val_pos]);        
    }
}