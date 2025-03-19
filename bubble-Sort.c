#include <stdio.h>
#include <stdlib.h>

int ma[2][4] = {
	{7, 2, 8, 5},
	{9,1,10,5}
};

void imprime (int m, int n){
	for(int i=0; i < m; i++){
		for(int j=0; j < n-1; j++)
			printf("%d, ", ma[i][j]);
		printf("%d\n", ma[i][n-1]);
	}		
}

void bubble_linha(int m, int n){
	for(int i=0; i < m; i++){
		for(int j=0; j < n-1; j++){
			
			for (int k = 0; k < n - 1; k++){
				if (ma[i][k] > ma [i] [k + 1]){
					int aux = ma[i][k];
					ma[i][k] = ma [i][k + 1];
					ma[i][k + 1 ] = aux;
				}
			}
			printf ("\n\n%d e %d\n\n", ma[i][n-1], ma [i + 1][0]);	
		}
			
		
	}
}

int main(){
	bubble_linha(2,4);
	imprime(2,4);
	return 1;
}

