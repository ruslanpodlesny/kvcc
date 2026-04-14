
//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// The Sieve of Eratosthenes (two binary arrays) (Problem HWE)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define DBG 0

void read_number(unsigned* pn);
int is_prime(unsigned n);
unsigned sieve_bound(unsigned num);

struct sieve {
	unsigned size;
	unsigned char* plus_one;
	unsigned char* minus_one;
};

void init_double_sieve(struct sieve* s);
void find_prime(struct sieve* s, unsigned n);
void free_sieve(struct sieve* s);


int main() {

	unsigned n, bound;

	read_number(&n);
	bound = sieve_bound(n);

#if DBG
	printf("bound = %u\n",bound);
#endif 
	
	struct sieve s;
	s.size = bound / (2 * 8);
	s.plus_one = calloc(s.size, sizeof(unsigned char));
	s.minus_one = calloc(s.size, sizeof(unsigned char));
	
#if DBG
	printf("s.size = %u\n", s.size);
#endif 

	if ((s.minus_one == NULL) || (s.plus_one == NULL) ) {
		printf("error: memory not allocated");
		abort();
	}

	init_double_sieve(&s);
	find_prime(&s, n);
	free_sieve(&s);

	return 0;
}


int is_prime(unsigned n) {   
	if (n < 2) return 0;
	if ((n == 2) || (n == 3)) return 1;						
	if (((n % 2) == 0) || ((n % 3) == 0)) return 0;

	for (unsigned i = 5; i * i <= n; i += 6) {	
		if (((n % i) == 0) || ((n % (i + 2)) == 0))
			return 0;
	}

#if DBG
	printf("%u is prime\n", n);
#endif 

	return 1;
}

void read_number(unsigned* pn) {
	int numb;
	printf("enter the no. of the sought after prime number >");
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

unsigned sieve_bound(unsigned num) {
	if (num <= 20) return 100;
	double dnum = num;
	double dres = dnum * (log(dnum) + log(log(dnum)));
	if ((unsigned long long)dres > UINT_MAX) {
		printf("uint_max data type limit exceded!");
		abort();
	}
	return (unsigned) round(dres);
}

void free_sieve(struct sieve* s) {
	free(s->plus_one);
	free(s->minus_one);
	s->minus_one = NULL;
	s->plus_one = NULL;
	s->size = 0;	
}

void init_double_sieve(struct sieve* s) {
	unsigned number = 5;

	for (int i = (s->size - 1); i >= 0; --i) {
		for (int j = 7; j >= 0; --j) {

			if (is_prime(number)) {
				s->minus_one[i] = s->minus_one[i] | (1u << (7 - j));

			}
#if DBG
			else {
				printf("%u is not prime\n", number);
			}
#endif 
			if (is_prime(number + 2)) {
				s->plus_one[i] = s->plus_one[i] | (1u << (7 - j));
			}
#if DBG
			else {
				printf("%u is not prime\n", number+2);
			}
#endif 							
			number += 6;
		}
	}
}

void find_prime(struct sieve* s, unsigned n) {
	unsigned counter_prime_numbers;	
	
	if (n == 1) {
		printf("prime number no. %u is 2\n", n);
		return;
	}
	if (n == 2) {
		printf("prime number no. %u is 3\n", n);
		return;

	}

	counter_prime_numbers = 2;

	for (int i = (s->size - 1); i >= 0; --i) {
		for (int j = 7; j >= 0; --j) {
			if (((s->minus_one[i] >> (7 - j)) & 1u) == 1) {
				++counter_prime_numbers;
			}
			if (counter_prime_numbers == n) {
				printf("prime number no. %u is %u\n", n, 6 * (8*(s->size - i - 1) + (7 - j + 1) ) - 1); // 6k - 1 
				return;
			}

			if (((s->plus_one[i] >> (7 - j)) & 1u) == 1) {
				++counter_prime_numbers;
			}
			if (counter_prime_numbers == n) {
				printf("prime number no. %u is %u\n", n, 6 * (8 * (s->size - i - 1) + (7 - j + 1)) + 1); // 6k + 1 
				return;
			}

		}
	}
}












