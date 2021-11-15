#include <stdio.h>
#include <math.h>

double f(int n){
	double a1 = (1 + sqrt(5))/2;
	double a2 = (1 - sqrt(5))/2;

	return (pow(a1, n) - pow(a2,n))/sqrt(5);

}

int main(void) {
	for (int i = -10; i < 10; i++)
		printf("%lf\n", f(i));
}