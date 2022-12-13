#include "ordvetor.h"
#include "codebase.c"

// "codebase""Ordvetor" não pode ser modificado

int comparar(void* x, void* y) { //compara dos vetores
	int xx = *((int*) x);
	int yy = *((int*) y);

	return xx < yy ? 1 : xx == yy ? 0 : -1;
}	

int main() { 
	const int VETOR_SIZE = 10; // adicionar um valor para o vetor
	const int VETOR_REMOVE = 2; // remover o valor 2

	VETORORD* vetor = VETORD_create(VETOR_SIZE, comparar);

	int meuVetor[VETOR_SIZE];

	printf("VETOR INICIALIZADO: "); //determina o vetor
	for (int i = 0; i < VETOR_SIZE; i++) {
		meuVetor[i] = rand() % VETOR_SIZE;
		printf("%d - ", meuVetor[i]);
	}
	printf("FIM\n\n");

	for (int i = 0; i < VETOR_SIZE; i++) { // adiciona em cada parte no vetor
		VETORD_add(vetor, &meuVetor[i]);
	}

	printf("ITENS REMOVIDOS: "); //Removo logo depois printa
	for (int i = 0; i < VETOR_REMOVE; i++) {
		printf("%d - ", *((int*) VETORD_remove(vetor)));
	}
	printf("FIM\n\n");

	printf("VETOR FINAL: ");  //Printa os valores finais do vetor
	for (int i = 0; i < vetor->P; i++) {
		printf("%d - ", *((int*) vetor->elems[i]));
	}
	printf("FIM\n");

	return 0;
}