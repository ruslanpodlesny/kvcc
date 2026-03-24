//-----------------------------------------------------------------------------
//
// C Language Practice Course. MIPT 2023-2024.
//
//-----------------------------------------------------------------------------
//
// Calculating the the double area of a triangle (Problem TS)
//
//-----------------------------------------------------------------------------

#include <stdio.h>

#define DBG 0

int double_square(struct triangle tr);

struct point
{
	int x, y;
};

struct triangle {
	struct point pts[3];
};

int res;

int main() {

	struct triangle tr = { { { 1, 1 }, { 1,4 }, { 4,4 } } };

#if DBG
	for (int i = 0; i < 3; ++i) {
		printf("point %d (%d,%d)\n", (i + 1), tr.pts[i].x, tr.pts[i].y);
	}
#endif

	res = double_square(tr);

	printf("double area = %d", res);

}

int double_square(struct triangle tr) {

	return abs(tr.pts[0].x*(tr.pts[1].y - tr.pts[2].y) +tr.pts[1].x*(tr.pts[2].y - tr.pts[0].y)+tr.pts[2].x *(tr.pts[0].y - tr.pts[1].y));

}

