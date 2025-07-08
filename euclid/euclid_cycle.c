#include <stdio.h>
#include <assert.h>

int abs(int a) {
	return (a < 0) ? -a : a;
}

void read_values(int* pa, int* pb) {
	
	printf("enter a and b: ");
	int scanf_res;
	scanf_res = scanf_s("%d%d", pa, pb);
	
	printf("scanf_res = %d\n", scanf_res);

	if (scanf_res != 2) {
		printf("invalid input!\n");
		abort();
	}
	else if (*pb == 0) {
		printf("division by zero!\n");
		abort();
	}
}

int gcd(int a, int b) {
	int r;
#if 0
	printf("a = %d\nb = %d\n", a, b);
#endif
	do {
		r = a % b;
		printf("r = %d\n", r);
		if (r == 0) return b;
		if (r < 0) r += abs(b);
		a = b;
		b = r;
	} while (r != 0);
}


int main(void) {
	int a, b;

	read_values(&a, &b);
	printf("gcd = %d\n", gcd(a, b));

	return 0;
}