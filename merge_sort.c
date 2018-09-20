#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int p, int q, int r);
void merge_sort(int *A, int p, int r);

int main(int argc, char const *argv[]) {
	int vetor[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	merge_sort(vetor, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", vetor[i]);
	}
	return 0;
}

void merge_sort(int *A, int p, int r){
	int q = (p + r) / 2;

	if (p < r) {
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}


void merge(int *A, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;

	int *L = (int*)malloc((n1+1)*sizeof(int));
	int *R = (int*)malloc((n2+1)*sizeof(int));

	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[q + i + 1];
	}

	L[n1] = L[n1-1]+R[n2-1];
	R[n2] = L[n1-1]+R[n2-1];

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; k++) {
		if (L[i] < R[j]) {
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}

	free(L);
	free(R);

}
