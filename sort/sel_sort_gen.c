//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Generalized selection sort algorithm (Problem CSE)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define ARR_SIZE 20


typedef int (*cmp_t) (void const*, void const*);

void fill_arr_rand(unsigned arr[], size_t arr_size);
void print_arr(unsigned arr[], size_t arr_size);
void swap(unsigned* a, unsigned* b);
unsigned find_min(unsigned arr[], size_t arr_size, unsigned start_pos, cmp_t cmp);
void sel_sort(void* pv_arr, size_t arr_size, unsigned elem_size, cmp_t cmp);
int cmp(void const* lhs, void const* rhs);

int main()
{
    srand(time(NULL));
    unsigned arr[ARR_SIZE];
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);     // the number of the cells
    void* pv_arr = &arr;
  
    fill_arr_rand(arr, ARR_SIZE);
    printf(" array with random values\n");
    print_arr(arr, ARR_SIZE);
    sel_sort(pv_arr, arr_size, sizeof(unsigned), cmp);
    printf(" sorted array\n");
    print_arr(arr, ARR_SIZE);
}

void fill_arr_rand(unsigned arr[], size_t arr_size)
{
    for (unsigned i = 0; i < arr_size; ++i) {
        arr[i] = 1 + rand() % 99;
    }
}

void print_arr(unsigned arr[], size_t arr_size)
{
    for (size_t i = 0; i < arr_size; ++i) {
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

unsigned find_min(unsigned arr[], size_t arr_size, unsigned start_pos, cmp_t cmp) {
    unsigned min_val = arr[start_pos];
    unsigned min_val_pos = start_pos;
    for (unsigned i = start_pos; i < arr_size; ++i) {
        if (cmp(&arr[i], &min_val) == -1) {
            min_val = arr[i];
            min_val_pos = i;
        }
    }
    return min_val_pos;
}

void sel_sort(void* pv_arr, size_t arr_size, unsigned elem_size, cmp_t cmp) {
    unsigned min_val_pos;
    unsigned min_val;
    unsigned* arr = (unsigned*)pv_arr; 

    for (unsigned i = 0; i < arr_size; ++i) {
        min_val_pos = find_min(arr, arr_size, i, cmp); 
        swap(&arr[i], &arr[min_val_pos]); 
    }
}

 int cmp(void const* lhs, void const* rhs) {  
    unsigned const lval = *(const unsigned *)lhs;
    unsigned const rval = *(const unsigned *)rhs;
    
    if (lval < rval)
        return -1;
    else if (lval > rval)
        return 1;
    else return 0; // l == r  
                          
}