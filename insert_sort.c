#include <stdio.h>

int main(int argc, char const *argv[]) {
	int vetor[] = {4, 3, 5, 8, 9, 1, 6, 2, 7, 0};
	int chave, i;
	for (int j = 1; j < 10; j++) {
		chave = vetor[j];
		i = j - 1;
		while (i >= 0 && vetor[i] > chave){
			vetor[i+1] = vetor[i];
			i = i-1;
		}
		vetor[i+1] = chave;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", vetor[i]);
	}
	return 0;
}