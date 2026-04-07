
//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// The Sieve of Eratosthenes (storing values in bits) (Problem PE)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DBG 0

void read_number(unsigned* pn);
int is_prime(unsigned n);
void init_binary_sieve(unsigned char* sieve, unsigned arr_size);
void print_binary_sieve(unsigned char* sieve, unsigned arr_size);
void test_binary_sieve(unsigned char* sieve, unsigned arr_size);

int main() {

	unsigned n, arr_size=0;
	
	read_number(&n);

	arr_size = (n / 8) + 1;
	unsigned char* sieve = calloc(arr_size, sizeof(unsigned char));
	if (sieve == NULL) {
		printf("error: memory not allocated");
		abort();
	}

	init_binary_sieve(sieve, arr_size);

#if DBG
	for (unsigned i = 0; i < arr_size; ++i) {
		printf("%hhu ", sieve[i]);
		if (i == (arr_size-1)) printf("\n");		
	}
#endif

	print_binary_sieve(sieve, arr_size);
	test_binary_sieve(sieve, arr_size);

	free(sieve);
	sieve = NULL;

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

void init_binary_sieve(unsigned char* sieve, unsigned arr_size) {
	unsigned number = 2;

	for (int i = (arr_size - 1); i >= 0; --i) {
		for (int j = 7; j >= 0; --j) {
			
			if (is_prime(number)) {
				++number;
				continue;
			}
			else {
				sieve[i] = sieve[i] | (1u << (7 - j));
				++number;
			}			
		}
	}
}

void print_binary_sieve(unsigned char* sieve, unsigned arr_size) {
	unsigned char binary_value;
	
	for (int i = (arr_size - 1); i >= 0; --i) {
		for (int j = 7; j >= 0; --j) {
			binary_value = (sieve[i] >> (7 - j)) & 1u;
			printf("%u ", binary_value);
						
			if ((i == 0) && (j == 0)) {
				printf("\n");
			}
		}		
	}
}

void test_binary_sieve(unsigned char* sieve, unsigned arr_size) {
	unsigned number = 2;
	unsigned char binary_value;

	for (int i = (arr_size - 1); i >= 0; --i) {
		for (int j = 7; j >= 0; --j) {
			binary_value = (sieve[i] >> (7 - j)) & 1u;
			if (is_prime(number) && (binary_value==0)) {
				printf("(%u) %u is primary\n",binary_value, number);
			}
			else {
				printf("(%u) %u is not primary\n", binary_value, number);
			}
			++number;
		}
	}
}
