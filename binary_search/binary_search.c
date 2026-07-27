//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Binary search algorithm (Problem SCB)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define ARR_SIZE 40

typedef int (*cmp_t) (void const*, void const*);

void fill_arr_rand(unsigned arr[], unsigned arr_size);
void print_arr(unsigned arr[], unsigned arr_size);
void swap(unsigned* a, unsigned* b);
unsigned find_min(unsigned arr[], unsigned arr_size, unsigned start_pos);
void sel_sort(unsigned arr[], unsigned arr_size);
unsigned bin_search(void* pv_arr, size_t arr_size, unsigned elem_size, unsigned value, cmp_t cmp);
int cmp(void const* lhs, void const* rhs);

int main()
{
    srand(time(NULL));
    
    unsigned arr[ARR_SIZE];
    void* pv_arr = &arr;
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    fill_arr_rand(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    sel_sort(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    bin_search(arr, ARR_SIZE, sizeof(arr[0]), 11, cmp);

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

unsigned find_min(unsigned arr[], unsigned arr_size, unsigned start_pos) {
    unsigned min_val = arr[start_pos];
    unsigned min_val_pos = start_pos;
    for (unsigned i = start_pos; i < arr_size; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
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

unsigned bin_search(void * pv_arr, size_t arr_size, unsigned elem_size, unsigned value, cmp_t cmp) {
    unsigned lhs = 0;
    unsigned rhs = arr_size - 1;
    unsigned m;

    unsigned* arr = (unsigned*)pv_arr;

    while (lhs <= rhs) {
        m = lhs + (rhs - lhs) / 2;
        if (cmp(&arr[m], &value) == 0) {
            printf("value %u has an index of %u\n", value, m);
            return m;
        }            
        if (cmp(&arr[m],&value)==-1)
            lhs = m + 1;
        if (cmp(&arr[m], &value) == 1)
            rhs = m - 1;
    }
    printf("value %u not found!\n", value);
    return arr_size;
}

int cmp(void const* lhs, void const* rhs) {
    unsigned const lval = *(const unsigned*)lhs;
    unsigned const rval = *(const unsigned*)rhs;

    if (lval < rval)
        return -1;
    else if (lval > rval)
        return 1;
    else return 0; // l == r  

}
