//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Calculating the Least Common Multiple (LCM) via GCD (Problem LM)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define DBG 0

void read_number(unsigned* pn);
int is_prime(unsigned n);
unsigned gcd(unsigned a, unsigned b);
unsigned lcm(unsigned a, unsigned b, unsigned n);

int main() {

	unsigned n;									// lcm for 2...n inclusive range of numbers
	unsigned lcm_res;

	read_number(&n);

	lcm_res = lcm(2, 3, n);

	printf("lcm = %u\n", lcm_res);

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

unsigned gcd(unsigned a, unsigned b) {	
	while (b != 0) {
		unsigned tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

unsigned lcm(unsigned a, unsigned b, unsigned n) {
	unsigned lcm_res = (a * b) / gcd(a, b);
	if (b == n) return lcm_res;
	b += 1;
	lcm(lcm_res, b, n);
}
