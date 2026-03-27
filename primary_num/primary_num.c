
//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Calculating the N-th Prime Number (Problem PN)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define DBG 0

void read_number(unsigned* pn);
int is_prime(unsigned n);

int main() {
	
	unsigned n;

	unsigned number = 2;
	unsigned prime_counter = 0;
	
	read_number(&n);

	if (n == 0) {
		printf("wrong input!\n");
		abort();
	}

#if DBG
	printf("%u\n", n);
#endif

	while (1) {
		if (is_prime(number)) {
			++prime_counter;
		}
		if (prime_counter == n) break;
		++number;
	}

	printf("%u\n", number);

	return 0;
}

int is_prime(unsigned n) {   // 1 for a prime number; 0 for a non-prime (composite) number
	if (n < 2) return 0;
	if (n == 2) return 1;
	if ((n % 2) == 0) return 0;					// checking for all even numbers	
	for (unsigned i = 3; i * i <= n; i+=2) {	// checking divisibility only by odd numbers
		if ((n % i) == 0)
			return 0;		
	}

#if DBG
	printf("%u is prime\n", n);
#endif 

	return 1;
}


void read_number(unsigned* pn) {
	int numb;
	printf("enter an ordinal number >");
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


