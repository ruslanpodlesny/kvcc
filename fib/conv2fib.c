//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Converting an unsigned int to the Fibonacci number system (Problem SF)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define ARR_SIZE 29

void read_number(unsigned* n);
void fill_fib(unsigned arr[], int arr_size);
void reverse_arr(unsigned arr[], int arr_size);
void print_arr(unsigned arr[], int arr_size);
void conv2fib(unsigned n, int arr_size);

unsigned fib_arr[ARR_SIZE];

int main() {

	unsigned n;

	read_number(&n);
	fill_fib(fib_arr, ARR_SIZE);
	print_arr(fib_arr, ARR_SIZE);
	reverse_arr(fib_arr, ARR_SIZE);
	print_arr(fib_arr, ARR_SIZE);
	conv2fib(n, ARR_SIZE);
}

void read_number(unsigned* pn) {
	int numb;
	printf("enter number >");
	numb = scanf("%u", pn);
	if (numb != 1) {
		printf("invalid input!\n");
		abort();
	}
	else if (*pn > (UINT_MAX / 2)) {
		printf("you may have entered a negative number!\n");
		abort();
	}
}

void fill_fib(unsigned arr[], int arr_size) {
	
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= arr_size; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

void reverse_arr(unsigned arr[], int arr_size) {
	
	int j = arr_size;
	unsigned tmp;
	
	arr_size /= 2;
	
	for (int i = 0; i <= arr_size; ++i) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		--j;
	}
}

void print_arr(unsigned arr[], int arr_size) {
	for (int i = 0; i <= arr_size; ++i) {
		printf("%6u ", arr[i]);
		if (((i % 10) == 9) && (i != 0))
			printf("\n");
	}
	printf("\n");
}

void conv2fib(unsigned n, int arr_size) {
	unsigned j=0; // adder for checking the result

	for (int i = 0; i <= arr_size;++i) {
		if (fib_arr[i] <= n) {
			printf("%u ", fib_arr[i]);
			n -= fib_arr[i];
			j += fib_arr[i];
			++i;		//naf
		}
		if (n == 0) break;
	}
	printf("\n");
	printf("%u\n",j);
}
