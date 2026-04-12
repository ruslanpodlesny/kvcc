//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Calculating the Pisano Period (Problem PP)
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define ON 1
#define OFF 0

void read_numbers(unsigned* n, unsigned* m);
int fib_mod(unsigned long long n, unsigned m);
void pisano_period(unsigned m);

int main() {

	unsigned n, m;

	read_numbers(&n, &m);
	fib_mod(n, m);

}

void read_numbers(unsigned* pn, unsigned* pm) {
	int numb;

	printf("enter fib and mod >");
	numb = scanf("%u%u", pn, pm);

	if (numb != 2) {
		printf("invalid input!\n");
		abort();
	}
	else if ((*pn > (UINT_MAX / 2)) || (*pm > (UINT_MAX / 2))) {
		printf("you may have entered a negative number!\n");
		abort();
	}
	printf("\n");
}

int fib_mod(unsigned long long n, unsigned m) {
	unsigned long long	first = 0, second = 1;
	unsigned long long tmp = second;
	unsigned idx;

	for (unsigned i = 2;i <= m;++i) {			// modulo
		printf("mod %2d   ", i);
		for (idx = 0; idx <= n; ++idx) {		// range
			if (idx == 0) {
				printf("%2llu ", first);
				continue;
			}
			if (idx == 1) {
				printf("%2llu ", second);
				continue;
			}
			tmp = second;
			second = first + second;
			first = tmp;

			printf("%2llu ", second % i);
		}
		
#if ON
		pisano_period(i);
#endif
		
		printf("\n");
		first = 0;
		second = 1;		

	}
	return second;
}

void pisano_period(unsigned m) {
	unsigned long long first = 0, second = 1;
	unsigned long long tmp = second;

	for (int i = 2; ;++i) {
		tmp = second;
		second = first + second;
		first = tmp;
		if ((second%m) == 1 && (first%m) == 0) {
			printf(" pp = %d", i - 1);
			return;
		}
	}

}
