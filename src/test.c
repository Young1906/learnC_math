#include "mat.h"
#include "det.c"
#include <stdio.h>

int main(void) {
	Matrix a = Ones(3,4);
	a.print();

	double x[] = {1,2,3,4};
	Matrix b = M2(4,1,x);
	b.print();

	Matrix c = Mult(a, b);
	c.print();


	printf("%lf", Det(c));
}
