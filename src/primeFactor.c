#include <stdio.h>
#include <stdlib.h>

void primeFactor(int n, int p) {
	
	if ( p * p > n ) {
		printf("%d\n", n);
		return;
	}

	if (n % p == 0) {
		printf("%d * ", p);
		primeFactor(n/p, p);
		return;
	}

	primeFactor(n, p+1);
}


int main(int argc, char* argv[]) {
	if (argc != 2){
		printf("./primefactor <int>\n");
		exit(1);
	}
	// Number to be prime-factored
	int n;
	n = atoi(argv[1]);	
	primeFactor(n, 2);
	return 0;
}
