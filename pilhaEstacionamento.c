#include <stdio.h>
#include <string.h>

#define MAX 10  

char Estacionamento1[MAX][10];
char Estacionamento2[MAX][10];
char Manobra[MAX][10];
int topo1 = 0;      
int topo2 = 0;     
int topoManobra = 0;
int n = 10;         
int vagasTotais;

void EstacionarCarro();
void RetirarCarro();

int main() {
    int opcao;
    
    vagasTotais = 2 * n;
    printf("Cada estacionamento tem %d vagas (1 a 10)\n", n);

    do {
        printf("\n=== Menu ===\n");
        printf("1 - Estacionar carro\n");
        printf("2 - Retirar carro\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                EstacionarCarro();
                break;
            case 2:
                RetirarCarro();
                break;
            case 3:
                printf("Programa encerrado\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 3);

    return 0;
}

void EstacionarCarro() {
    char placa[10];
    printf("Digite a placa do carro: ");
    scanf("%s", placa);

    if ((topo1 + topo2) >= vagasTotais) {
        printf("Estacionamentos cheios!\n");
    } else {
        if (topo1 < n) {
            strcpy(Estacionamento1[topo1], placa);
            printf("Carro estacionado no Estacionamento 1, vaga %d\n", topo1 + 1);
            topo1 = topo1 + 1;
        } else {
            strcpy(Estacionamento2[topo2], placa);
            printf("Carro estacionado no Estacionamento 2, vaga %d\n", topo2 + 1);
            topo2 = topo2 + 1;
        }
    }
}

void RetirarCarro() {
    char placa[10];
    int encontrado = 0;
    int i;

    printf("Digite a placa do carro a ser retirado: ");
    scanf("%s", placa);

    i = topo1 - 1;
    while (i >= 0 && encontrado == 0) {
        if (strcmp(Estacionamento1[i], placa) == 0) {
            encontrado = 1;
            printf("Carro %s encontrado no Estacionamento 1, vaga %d\n", placa, i + 1);
              
            while (topo1 > i + 1) {
                topo1 = topo1 - 1;
                topoManobra = topoManobra + 1;
                strcpy(Manobra[topoManobra - 1], Estacionamento1[topo1]);
                printf("Movendo %s para manobra\n", Manobra[topoManobra - 1]);
            }
         
            printf("Carro %s retirado do Estacionamento 1\n", Estacionamento1[i]);
            topo1 = topo1 - 1;
            
            while (topoManobra > 0) {
                strcpy(Estacionamento1[topo1], Manobra[topoManobra - 1]);
                printf("Retornando %s ao Estacionamento 1, vaga %d\n", 
                       Manobra[topoManobra - 1], topo1 + 1);
                topo1 = topo1 + 1;
                topoManobra = topoManobra - 1;
            }
        }
        i = i - 1;
    }

    if (encontrado == 0) {
        i = topo2 - 1;
        while (i >= 0 && encontrado == 0) {
            if (strcmp(Estacionamento2[i], placa) == 0) {
                encontrado = 1;
                printf("Carro %s encontrado no Estacionamento 2, vaga %d\n", placa, i + 1);
            
                while (topo2 > i + 1) {
                    topo2 = topo2 - 1;
                    topoManobra = topoManobra + 1;
                    strcpy(Manobra[topoManobra - 1], Estacionamento2[topo2]);
                    printf("Movendo %s para manobra\n", Manobra[topoManobra - 1]);
                }
                
                printf("Carro %s retirado do Estacionamento 2\n", Estacionamento2[i]);
                topo2 = topo2 - 1;
                
                
                while (topoManobra > 0) {
                    strcpy(Estacionamento2[topo2], Manobra[topoManobra - 1]);
                    printf("Retornando %s ao Estacionamento 2, vaga %d\n", 
                           Manobra[topoManobra - 1], topo2 + 1);
                    topo2 = topo2 + 1;
                    topoManobra = topoManobra - 1;
                }
            }
            i = i - 1;
        }
    }

    if (encontrado == 0) {
        printf("Carro nao encontrado!\n");
    }
}
