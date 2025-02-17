#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct elemento {
	int num;
	struct Elemento *prox;
};
typedef struct Elemento Elemento;

struct Pilha{
	struct Elemento *topo;	
};
typedef struct Pilha Pilha;

Pilha* criar_pilha();
void inserir_elemento(Pilha *pi);
void listar_pilha(Pilha *pi);
void remover_elemento(Pilha *pi);
void esvaziar_pilha(Pilha *pi);

int main (){
	setlocale(LC_ALL, "Portuguese");
	Pilha *pi = criar_pilha();
		
	listar_pilha(pi);	
		
	return 0 ;
}

Pilha* criar_pilha(){
	Pilha* pi = (Pilha*) malloc (sizeof (Pilha));
	if(pi != NULL){
		pi->topo = NULL;
	}
	return pi;
}

void inserir_elemento(Pilha *pi){
	Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
	printf ("Digite um número:");
	scanf("%d", &novo->num);
	novo -> prox = pi -> topo;
	pi ->topo = novo ;
	printf ("\nInserido na Pilha");
}

void listar_pilha(Pilha *pi){
	if (pi->topo = NULL){
		printf("Pilha esta vazia!");
	}else{
		aux = pi->topo;
		do{
			printf("&d ", aux-> num)
			
		}while (aux != NULL);
	}
}
