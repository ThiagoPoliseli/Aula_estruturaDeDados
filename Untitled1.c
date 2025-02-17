#include <stdio.h>

void inserction_sort( int A[]){
	int j;
	
	for(j=1; j<20; j++){
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
	int A[20] = {7,9,0,3,12,15,1,4,5,59,7,22,33,44,99,100,40,60,70,80};
	int i;
	inserction_sort(A);
	for(i=0; i<20; i++){
		printf("%d ", A[i]);
	}
	return 0;
}
