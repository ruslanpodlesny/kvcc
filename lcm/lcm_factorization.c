//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Calculating the Least Common Multiple (LCM) (Problem LM)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define DBG 0

void read_number(unsigned* pn);
int is_prime(unsigned n);


int main() {

	unsigned n;									// lcm for 2...n inclusive range of numbers
	unsigned lcm = 1;
	
	read_number(&n);

	for (unsigned i = 2; i <= n; ++i) {			// factorization method
		if (is_prime(i)) {
#if DBG
			printf("prime %u\n", i);
#endif 
			unsigned j = i;						// prime number transfer for processing (raising to a power)
			while (j <= n) {					// the cycle runs while prime number raised to a power <= n 
				lcm *= i;						// lcm - accumulated value of prime numbers 
#if DBG
				printf("j = %u\n", j);
				printf("lcm_calc = %u\n", lcm);
#endif 
				j *= i;							// raising a prime number to a power
			}		
		}
	}

	printf("lcm = %u\n", lcm);

	return 0;
}

int is_prime(unsigned n) {						
	if (n == 2) return 1;						
	if ((n < 2) || ((n % 2) == 0)) return 0;		

	for (unsigned i = 3; i * i <= n; i += 2) {	
		if ((n % i) == 0)
			return 0;
	}
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
