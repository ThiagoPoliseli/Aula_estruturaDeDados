


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void imprimir(int A[], int n, int tempo);
void delay(int number_of_seconds);
int* criarArranjo(int n);
void troca(int *x, int *y);
void select_min(int A[], int n);
void merge_sort(int A[], int n);
void merge_recursao(int A[], int p, int r);
void merge(int A[], int p, int q, int r);

int main(){
    int n = 10;
    clock_t tempo;
    int* A = criarArranjo(n);
    printf("-------------- Lista Inicial --------------\n");
    imprimir(A,n,0);
    tempo = clock;
	merge_sort(A,n);
	tempo = clock() - tempo;
	printf("\n\n-------------- Lista Final --------------\n");
    imprimir(A,n,0);
    printf("\nTempo de execucao: %lf",((double)tempo) / ((CLOCKS_PER_SEC)/1000));
    return 0;
}
void merge_sort(int A[], int n){
	merge_recursao(A,0,n-1);
}
void merge_recursao(int A[], int p, int r){
	if(p < r){
		int q = (p + r)/2;
		merge_recursao(A,p,q);
		merge_recursao(A,q+1,r);
		merge(A,p,q,r);
	}
}

void merge(int A[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1];
	int R[n2];
	int i,j,k;
	for (i = 0; i < n1; i++) L[i] = A[p+i];
	for (i = 0; i < n2; i++) R[i] = A[q+i+1];
	for (i=0,j=0,k=p; k <= r; k++){
		if ((i < n1) && (j >= n2 || L[i] <= R[j]) ){
			A[k] = L[i];
			i++;
		}else {
			A[k] = R[j];
			j++;
		}
	}
}

void troca(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}
void imprimir(int A[], int n, int tempo){
    for(int k=0; k < n; k++){
        printf("%d ", A[k]);
    }
    delay(tempo);
    printf("\n");
}
void delay(int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int* criarArranjo(int n){
    int* arrajo = (int*)malloc(n * sizeof(int));
    if (arrajo == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arrajo[i] = rand() % (n*2);
    }
    return arrajo;
}

void select_min(int A[], int n){
    for(int i=0; i < n; i++){
        int pos = i;
        for(int j=i+1; j < n; j++){
            if(A[j] < A[pos]){
                pos = j;
            }
        }
        troca(&A[i],&A[pos]);
        imprimir(A,n,100);
    }
}
