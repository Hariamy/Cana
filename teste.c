#include <stdio.h>
#include <math.h>

int numero(int num, int coluna, int total){
	int aux = num/pow(10, total-coluna);
	return  aux % 10;
}

int main(int argc, char const *argv[]) {
	int num = 67890;
	for (int i = 5; i > 0; i--) {
		printf("Coluna %d - Valor %d\n", i, numero(num, i, 5));
	}
	return 0;
}