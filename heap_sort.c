#include <stdlib.h>
#include <stdio.h>

//ESTRUTURAS DA HEAP

typedef struct {
	float *vetor;
	int tamanho;
} Heap;

//FUNÇÕES NECESSÁRIAS PARA A HEAP
int tamanho_da_heap(Heap *heap);
float elemento(Heap *heap, int i);
float chave(Heap *heap, int i);
void troca(Heap *heap, int a, int b);
void atribuir_elemento(Heap *heap, int a, int b);
void atribuir_valor(Heap *heap, int a, float valor);
void altera_tamanho(Heap *heap, int quantidade);

int pai(int i);
int esquerda(int i);
int direita(int i);

Heap *constroi_heap(float *A, int tamanhoA);
void conserta_heap(Heap *A, int i);
float remove_minimo(Heap *A);
void aumenta_prioridade(Heap *A, int i, float chav);
void inserir(Heap *A, float chav);

//HEAP SORT
void heap_sort(float *A, float tamanhoA);

int main(int argc, char const *argv[]) {
	float A[9] = {0, 5, 8, 4, 7, 3, 1, 6, 2};

	printf("Antes de ordenar\n");
	for (int i = 1; i <= 8; i++) {
		printf("%f ", A[i]);
	}

	heap_sort(A, 8);

	printf("\nDepois de ordenar\n");
	for (int i = 1; i <= 8; i++) {
		printf("%f ", A[i]);
	}
	printf("\n");
	return 0;
}

void heap_sort(float *A, float tamanhoA){
	Heap *heap = constroi_heap(A, tamanhoA);
	for (int i = tamanhoA; i > 1; i--) {
		troca(heap, 1, i);
		altera_tamanho(heap, 1);
		conserta_heap(heap, 1);
	}
}

//FUNÇÕES DA HEAP
int tamanho_da_heap(Heap *heap){ return heap->tamanho; }
float elemento(Heap *heap, int i){ return heap->vetor[i]; }
float chave(Heap *heap, int i){return heap->vetor[i]; }

void troca(Heap *heap, int a, int b){
	float auxiliar;
	auxiliar = heap->vetor[a];
	heap->vetor[a] = heap->vetor[b];
	heap->vetor[b] = auxiliar;
}

void atribuir_elemento(Heap *heap, int a, int b){
	heap->vetor[a] = heap->vetor[b];
}

void atribuir_valor(Heap *heap, int a, float valor){
	heap->vetor[a] = valor;
	
}

void altera_tamanho(Heap *heap, int quantidade){
	heap->tamanho = heap->tamanho - quantidade;
}

int pai(int i) { return i/2; }
int esquerda(int i){ return 2*i; }
int direita(int i){ return 2*i + 1; }

void conserta_heap(Heap *A, int i){
	int d = direita(i);
	int e = esquerda(i);
	float maior = 0;
	if (e <= tamanho_da_heap(A) && chave(A, e) > chave(A, i)) maior = e;
	else maior = i;

	if (d <= tamanho_da_heap(A) && chave(A, d) > chave(A, maior)) maior = d;

	if (maior != i) {
		troca(A, i, maior);
		conserta_heap(A, maior);
	}	
}

float remove_minimo(Heap *A){
	float minimo;
	minimo = elemento(A, 1);
	atribuir_elemento(A, 1, tamanho_da_heap(A));
	altera_tamanho(A, -1);
	conserta_heap(A, 1);
	return minimo;
}

void aumenta_prioridade(Heap *A, int i, float chav){
	atribuir_valor(A, i, chav);
	while (i > 1 && chave(A, pai(i)) > chave(A, i)){
		troca(A, i, pai(i));
		i = pai(i);
	}

}

void inserir(Heap *A, float chav){
	altera_tamanho(A, 1);
	aumenta_prioridade(A, tamanho_da_heap(A), chav);

}

Heap *constroi_heap(float *A, int tamanhoA){
	Heap *heap = (Heap*)malloc(sizeof(Heap));
	heap->tamanho = tamanhoA;
	heap->vetor = A;

	for (int i = heap->tamanho/2; i >= 1; i--) {
		conserta_heap(heap, i);
	}
	return heap;
}