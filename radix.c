#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void contagem(int *A, int tamanhoA, int *B, int coluna, int totalColuna);
void radix(int *A, int tamanhoA, int *B, int totalColuna );


int main(int argc, char const *argv[]) {
	int A[9] = {0, 119, 704, 443, 199, 327, 816, 655, 240};
	int B[9];
	printf("Antes de ordenar\n");
	for (int i = 1; i <= 8; i++) {
		printf("%d ", A[i]);
	}

	radix(A, 9, B, 3);

	printf("\nDepois de ordenar\n");
	for (int i = 1; i <= 8; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");
	return 0;	
	return 0;
}

void radix(int *A, int tamanhoA, int *B, int totalColuna ) {
	for (int i = totalColuna; i > 0; i--) {
		contagem(A, tamanhoA, B, i, totalColuna);
	}
}

int numero(int num, int coluna, int totalColuna){
	int aux = num/pow(10, totalColuna-coluna);
	return  aux % 10;
}

void contagem(int *A, int tamanhoA, int *B, int coluna, int totalColuna) {
	int C[10];
	for (int i = 0; i < 10; i++) {
		C[i] = 0;
	}
	for (int i = 1; i < tamanhoA; i++) {
		C[numero(A[i], coluna, totalColuna)]++;
	}
	for (int i = 1; i < 10; i++) {
		C[i] += C[i-1];
	}
	for (int i = tamanhoA; i > 0; i--) {
		B[C[numero(A[i], coluna, totalColuna)]] = A[i];
		C[numero(A[i], coluna, totalColuna)]--;
	}
}