#include <stdio.h>
#include <stdlib.h>


typedef struct Matrices {
	double * entries;
	int m, n;

	void init(int m, int n){
		// Init a matrix with size (m, n)
		this->m = m;
		this->n = n;

		this->entries = (double*)malloc(m*n*sizeof(double));
		
		for (int i = 0; i < m*n; i++)
			this->entries[i] = (double) 0.0;
	}

	void init2(int m, int n, double v[]){
		this->m = m;
		this->n = n;

			

		this->entries = (double*)malloc(m*n*sizeof(double));

		for (int i = 0; i < m * n; i++)
			this->entries[i] = v[i];
	}

	double at(int i, int j){
		this->valid_index(i, j);
		return this->entries[j + i * this->n];

	}

	void set(int i, int j, double v){
		this->valid_index(i, j);
		this->entries[ i*this->n + j ] = v;
	}

	void valid_index(int i, int j){
		// Validating index
		if (i < 0 | i >= this->m | j < 0 | j >= this->n)
		{

			printf("Invalid index, program exiting with error code != 0\n");
			exit(1);
		}
	}

	void print(){
		for (int i = 0; i < this->m; i++){
			for (int j = 0; j < this->n; j++){
				printf("%lf | ", this->at(i, j));
			}

			printf("\n");
		}
	}

	void free_this(){
		free(this->entries);	
	}


} Matrix ;

// Short hand to create new matrix
Matrix M(int m, int n) {
	Matrix arr;
	arr.init(m, n);

	return arr;
}

// Function to init new matrix with entries
Matrix M2(int m, int n, double v[]){
	Matrix arr;
	arr.init2(m, n, v);

	return arr;
}

// One
Matrix Ones(int m, int n) {
	Matrix ones = M(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			ones.set(i, j, (double) 1.0);

		}
	}
	return ones;
}

Matrix Mult(Matrix a, Matrix b){
	// Check if valid matrix size
	if ( a.n != b.m ) {
		printf("Invalid matrix size\n");
		exit(1);
	}
	
	// Matrix multiplication
	Matrix c;
	c.init(a.m, b.n);
	
	double cij;

	for (int i = 0; i < a.m; i++) {
		for (int j = 0; j < b.n; j++) {
			cij = 0;
			for (int k = 0; k < a.n; k++) {
				cij += a.at(i,k) * b.at(k, j);
			};

			c.set(i, j, cij);
		}
	}

	return c;

};

