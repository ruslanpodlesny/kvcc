
//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Calculating the Sieve of Eratosthenes (Problem SE)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DBG 0

void read_number(unsigned* pn);
int is_prime(unsigned n);

int main() {

	unsigned n;
	unsigned number = 2;
	
	read_number(&n);

	char* p = calloc(n, sizeof(char)); 
	
	if (p == NULL) {
		printf("error: memory not allocated");
		abort();
	}


#if DBG
	printf("%u\n", n);
#endif
	
	for (unsigned i = 0; i < n; ++i) {
		p[i] = is_prime(number) ? 0 : 1;
		++number;
	}

	for (unsigned i = 0; i < n; ++i) {
		printf("%d ", p[i]);
	}

    printf("\n");

	free(p);

	return 0;
}

int is_prime(unsigned n) {   // 1 for a prime number; 0 for a non-prime (composite) number
	if (n < 2) return 0;
	if (n == 2) return 1;						// first prime number
	if ((n % 2) == 0) return 0;					// checking for all even numbers	

	for (unsigned i = 3; i * i <= n; i += 2) {	// checking divisibility only by odd numbers
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
	printf("enter the sieve boundary >");
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


