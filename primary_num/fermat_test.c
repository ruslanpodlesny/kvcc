//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Fermat test (Problem FT)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define DBG 0

void read_number(unsigned* pn);
unsigned sieve_bound(unsigned n);
void init_sieve(char* sieve, unsigned size);

struct sieve {
	unsigned size;
	char* sieve;
};

void check_number(struct sieve* s, unsigned n);
void free_sieve(struct sieve* s);

unsigned fast_pow_mod(unsigned base, unsigned exp, unsigned mod);
void fermat_test(unsigned n);


int main() {
	unsigned num;
	unsigned counter = 0;
	unsigned bound;
	srand(time(NULL));

	read_number(&num);
	bound = sieve_bound(num);

	struct sieve s;
	s.size = bound;
	s.sieve = calloc(bound, sizeof(char));

	if (s.sieve == NULL) {
		printf("memory not allocated\n");
		abort();
	}

	init_sieve(s.sieve, s.size);
	check_number(&s, num);
	free_sieve(&s);

	fermat_test(num);
	
}


void read_number(unsigned* pn) {
	printf("enter a number >");
	int numb = scanf("%u", pn);
	if (numb != 1) {
		printf("invalid input!\n");
		abort();
	}
	else if (*pn > (UINT_MAX / 2)) {
		printf("you may have entered a negative number!\n");
		abort();
	}
}

unsigned  sieve_bound(unsigned n) {
	if (n <= 20) return 100;
	double dnum = n;
	double dres = dnum * (log(dnum) + log(log(dnum)));
	return (unsigned long long) round(dres);
}

void init_sieve(char* sieve, unsigned size) {

	unsigned lim = (unsigned)sqrt(size);

#if DBG
	printf("init_sieve lim = %u\n", lim);
#endif	
	sieve[0] = 1;											// zero and one are not primary 
	sieve[1] = 1;

	for (unsigned i = 2; i <= lim; ++i) {					// 1st primary is 2
		if (sieve[i] == 1) continue;						// skip numbers that are already checked
		if (sieve[i] == 0) {
			for (unsigned j = i * i; j < size; j += i) {
				sieve[j] = 1;
			}
		}
	}
}

void check_number(struct sieve* s, unsigned n) {
	if (s->sieve[n] == 0) 	{
		printf("number %u is prime (e-sieve)\n", n);
	}
	else {
		printf("number %u is not prime (e-sieve)\n", n);
	}

}

void free_sieve(struct sieve* s) {
	free(s->sieve);
	s->sieve = NULL;
	s->size = 0;
}

unsigned fast_pow_mod(unsigned base, unsigned exp, unsigned mod) {
	unsigned res = 1;
	unsigned mult = base % mod;
	while (exp > 0) {
		if ((exp % 2) == 1) {
			res = (res*mult)%mod;
			exp -= 1;
		}
		mult = (mult*mult)%mod;
		exp /= 2;
	}
	return res;
}

void fermat_test(unsigned n) {
	unsigned a;  // random number

	for (unsigned i = 1; i <= 7; ++i) {
		a = 2 + rand() % (n-3);		
		if (fast_pow_mod(a, n - 1, n) != 1) {
			printf("number %u is not prime (fermat)\n",n);
			return;
		}
	}
	printf("number %u is prime (fermat)\n", n);
}
