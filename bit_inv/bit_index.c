//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Invert a specific bit in an array (Problem BI)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void read_numbers(unsigned* arr_size, unsigned* a0, unsigned* a1, unsigned* a2, unsigned* a3, unsigned* bit_number);

int main() {

	unsigned arr_size, a0, a1, a2, a3, bit_number;
	unsigned char bit_number_char, target_cell, inv_mask;

	read_numbers(&arr_size, &a0, &a1, &a2, &a3, &bit_number);
	
	unsigned char* arr = calloc((unsigned char)arr_size, sizeof(unsigned char));
	if (arr == NULL) {
		printf("memory not allocated!\n");
		abort();
	}

	arr[0] = (unsigned char)a3;
	arr[1] = (unsigned char)a2;
	arr[2] = (unsigned char)a1;
	arr[3] = (unsigned char)a0;

	bit_number_char = (char)bit_number;

	target_cell = bit_number_char / 8; 
	inv_mask = (1u << (bit_number_char % 8));
	arr[3 - target_cell] = arr[3 - target_cell] ^ inv_mask;
	
	
	int i = 3;
	do {
		printf("%u ", arr[i]);
		if (i == 0) printf("\n");
		--i;
	} while (i >= 0);

	free(arr);
	arr = NULL;

	return 0;
}


void read_numbers(unsigned* arr_size, unsigned* a0, unsigned* a1, unsigned* a2, unsigned* a3, unsigned* bit_number) {
	int numb;
	printf("enter numbers >");
	numb = scanf("%u%u%u%u%u%u", arr_size, a0, a1, a2, a3, bit_number);
	if (numb != 6) {
		printf("wrong input!\n");
		abort();
	}
	
}
