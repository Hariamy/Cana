#include <stdio.h>
#include <stdlib.h>

void contagem(int *A, int tamanhoA, int *B, int k);

int main(int argc, char const *argv[]) {
	int A[9] = {0, 5, 7, 4, 1, 3, 0, 6, 2};
	int B[9];
	printf("Antes de ordenar\n");
	for (int i = 1; i <= 8; i++) {
		printf("%d ", A[i]);
	}

	contagem(A, 9, B, 10);

	printf("\nDepois de ordenar\n");
	for (int i = 1; i <= 8; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");
	return 0;	
	return 0;
}

void contagem(int *A, int tamanhoA, int *B, int k) {
	int *C = (int*)malloc(k*sizeof(int));
	for (int i = 0; i < k; i++) {
		C[i] = 0;
	}
	for (int i = 1; i < tamanhoA; i++) {
		C[A[i]]++;
	}
	for (int i = 1; i < k; i++) {
		C[i] += C[i-1];
	}
	for (int i = tamanhoA; i > 0; i--) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}