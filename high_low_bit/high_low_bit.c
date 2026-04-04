//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Find the position of the high and low set bits in a number (Problem BP)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define DBG 0

#define YES 1
#define NO  0

void read_number(unsigned* pn);

int main() {

	unsigned n, n_shift, lim;
	unsigned low_bit=0, high_bit=0, lowbit_is_set=NO;


	read_number(&n);
	n_shift = n;
	lim = 8 * sizeof(unsigned);

#if DBG
	printf("llu in bytes = %u", lim);
#endif
	
	for (unsigned i = 0; i < lim; ++i) {
		if (((n_shift & 1u) == 1) && (lowbit_is_set == NO)) {
			low_bit = i;
			high_bit = i;
			lowbit_is_set = YES;
		}		

		if (((n_shift & 1u) == 1) && (lowbit_is_set == YES) && (high_bit < i)) {
			high_bit = i;
		}

		n_shift = n_shift >> 1;

	}

	printf("high bit %u low bit %u\n", high_bit, low_bit);

	return 0;
}


void read_number(unsigned* pn) {
	int numb;
	printf("enter a number >");
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
