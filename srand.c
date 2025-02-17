#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void inserction_sort( int A[]){
	
	for(int j=1; j<20; j++){
		int chave = A[j];
		int i = j - 1;
		while(i >= 0 && A[i] > chave ){
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = chave;
	}
}
int main(){
	int A[10];
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++){
		A[i] = (rand() % 50) + 1;
	}
	
	inserction_sort(A);
	for(int i = 0; i < 10; i++){
		printf("%d ", A[i]);
	}
	return 0;
}
