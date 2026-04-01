//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Calculating the N-th prime number using the E-sieve (Problem PS)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define DBG 0

struct sieve {
	unsigned long long size;
	char* sieve;
};

void read_number(unsigned* pn);
unsigned long long sieve_bound(unsigned num);
void init_sieve(char* sieve, unsigned size);
void free_sieve(struct sieve* s);

int main() {

	unsigned num;
	unsigned counter =0;
	unsigned long long bound;

	unsigned primary_number;

	read_number(&num);

#if DBG
	printf("%u\n", num);
#endif

	bound = sieve_bound(num);

#if DBG
	printf("bound = %llu\n", bound);
#endif

	struct sieve s;
	s.size = bound;
	s.sieve = calloc(bound, sizeof(char));

	if (s.sieve == NULL) {
		printf("memory not allocated\n");
		abort();
	}

	init_sieve(s.sieve, s.size);

#if DBG
	printf("s.size = %llu\n", s.size);
#endif

	for (unsigned i = 0; i < s.size; ++i) {
		printf("%d ", s.sieve[i]);
		if ((i == (s.size - 1)) || ((i % 20 == 19) && (i != 0))) {
			printf("\n");
		}
	}
	
#if DBG

	for (unsigned i = 2; i < s.size; ++i) {
		s.sieve[i] == 0 ? printf("%u ", i ) : printf("<c> ");
		if ((s.sieve[i] == (s.size - 1)) || (i % 20 == 19) && (i != 0)) {
			printf("\n");
		}
	}

	printf("\n");

#endif

	for (unsigned i = 0; i < s.size; ++i) {
		if (s.sieve[i] == 0) ++counter;
		if (counter == (num)) {
			printf("primary number No. %u is %u\n", num, i);
			break;
		}

	}

	free_sieve(&s);

}


void read_number(unsigned* pn) {
	printf("enter ordinal number of a prime number >");
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

unsigned long long sieve_bound(unsigned num) {
	if (num <= 20) return 100;
	double dnum = num;
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
		if (sieve[i] == 1) continue;
		if (sieve[i] == 0) {
			for (unsigned j = i * i; j < size; j += i) {
				sieve[j] = 1;
			}
		}
	}
}

void free_sieve(struct sieve* s) {
	free(s->sieve);
	s->sieve = NULL;
	s->size = 0;
}
