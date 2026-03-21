#include <stdio.h>
#include <assert.h>

int abs(int a) {
	return (a < 0) ? -a : a;
}

void read_values(int* pa, int* pb) {
	printf("enter a and b: ");
	int scanf_res = scanf_s("%d%d", pa, pb);	
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
	
	int r = a % b;	

	if (r == 0) {
		return b;
	}
	else {
		if (r < 0) r += abs(b); // check the logic behind this
		gcd(b, r);
	}
		
}


int main(void) {

	int a, b, res;

	read_values(&a, &b);
	res = gcd(a,b);
	printf("gcd = %d\n", res);
	
	return 0;
}