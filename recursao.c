#include <stdio.h>
#include <locale.h>
int soma(int n){
	if(n == 1) return 1;
	else return n + (n - 1);
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	printf("A soma é %d", soma(7));
	
	
	return 0;
}
