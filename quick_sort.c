#include <stdio.h>

void quick_sort(float *A, int p, int r);
int particao(float *A, int p, int r);


int main(int argc, char const *argv[]) {
	float A[9] = {7, 5, 8, 4, 1, 3, 0, 6, 2};
	printf("Antes de ordenar\n");
	for (int i = 0; i <= 8; i++) {
		printf("%f ", A[i]);
	}

	quick_sort(A, 0, 8);

	printf("\nDepois de ordenar\n");
	for (int i = 0; i <= 8; i++) {
		printf("%f ", A[i]);
	}
	printf("\n");
	return 0;
}

void quick_sort(float *A, int p, int r) {
	int q;
	if (p < r) {
		q = particao(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);	
	}
}

int particao(float *A, int p, int r){
	float x, auxTroca;
	int i;
	x = A[r];
	i = p - 1;

	for (int j = p; j <= r-1; j++) {
		if (A[j] <= x) {
			i = i + 1;
			auxTroca = A[i];
			A[i] = A[j];
			A[j] = auxTroca;
		}
	}

	auxTroca = A[i+1];
	A[i+1] = A[r];
	A[r] = auxTroca;

	return i + 1;
}