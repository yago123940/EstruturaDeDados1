#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*OBJETIVO: Vetor Est�tico*/

int vazio_vet(int*vet){
	return vet == NULL;
}

int* incluir_valor(int *v, int valor, int *qtd, int *max){
	if(vazio_vet(v)){ //ou poderia ser if(qtd==0) ou if(!qtd)
		printf("\nO vetor estava vazio - primeira alocacao!");
		v = (int*) malloc(2*sizeof(int));
		if(!v){ //n�o conseguiu espa�o em mem�ria
			return NULL;
		}
		*max = 2;
	}
	if(*qtd == *max){ //meu vetor est� cheio
		printf("\nO vetor precisa de realocacao!");
		v = (int*) realloc(v, (*max+2)*sizeof(int));
		if(!v){ //n�o conseguiu espa�o em mem�ria
			return NULL;
		}
		*max = *max + 2;
	}
	v[*qtd] = valor;	
	*qtd = *qtd + 1;
	getch();
	return v;
		
}

void imprimir_vetor(int *vet,int qtd){
	printf("\nTotal de elementos do vetor = %d",qtd);
	int i;
	for(i=0;i<qtd;i++){
		printf("\nVET[%d] = %d",i,vet[i]);		
	}
	getch();	
}
/*Objetivo: buscar um elemento no vetor
entrada: vetor, a quantidade de elementos do vetor e o elemento a ser procurado
saida: se encontrou o elemento, retornar o �ndice onde o mesmo est� localizado.
Caso contr�rio, retornar -1
*/
int buscar_elemento(int* vet, int qtd, int elem){
	int i;
	for(i=0;i<qtd;i++){
		if(vet[i]==elem){
			return i;
		}
	}
	return -1;
}

int maior(int* vet,int qtd){
	int maior = vet[0];
	int i;
	for(i=1;i<qtd;i++){
		if(vet[i]>maior){
			maior = vet[i];
		}
	}
	return maior;
}

int menor(int* vet,int qtd){
	int menor = vet[0];
	int i;
	for(i=1;i<qtd;i++){
		if(vet[i]<menor){
			menor = vet[i];
		}
	}
	return menor;
}

void bubble_sort (int *vet, int qtd) {
    int i, j, aux;

    for (i = qtd - 1; i > 0; i--) {       
        for (j = 0; j < i; j++) {
            if (vet[j] > vet[j + 1]) {
				aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

int main(int argc, char *argv[]) {

	int opcao;	
	int sair;
	int qtd = 0;
	int max = 0;
	int elem, valor;
	
	int *vet = NULL;
	
	do{		
		system("cls");		
		printf("\n(1) Incluir numero");
		printf("\n(2) Imprimir os elementos do vetor");
		printf("\n(3) Buscar um elemento no vetor");
		printf("\n(4) Buscar o maior elemento do vetor");
		printf("\n(5) Buscar o menor elemento do vetor");		
		printf("\n(6) Ordenar o vetor");		
		printf("\n(7) Sair");
		printf("\n\nDigite uma opcao: ");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				printf("\nInforme o valor a ser incluido: ");
				scanf("%d",&valor);
				vet = incluir_valor(vet,valor,&qtd,&max);
				if(!vet){
					printf("\nO vetor estava cheio e nao foi possivel realoca-lo");
				}
				printf("\nquantidade de elementos = %d",qtd);				
				getch();
				break;
			case 2:
				imprimir_vetor(vet,qtd);
				getch();
				break;
			case 3:				
				printf("\nInforme o numero a ser procurado: ");
				scanf("%d",&elem);				
				int ind = buscar_elemento(vet, qtd, elem);
				if(ind != -1){
					printf("Elemento encontrado na posicao %d",ind);					
				}else{
					printf("Elemento nao encontrado no vetor!");
				}
				getch();					
				break;

			case 4:
				printf("\nO maior elemento do vetor eh: %d",maior(vet,qtd));
				getch();				
				break;
			case 5:
				printf("\nO menor elemento do vetor eh: %d",menor(vet,qtd));
				getch();				
				break;
			case 6:
				bubble_sort (vet,qtd);
				break;
			
			case 7:
				printf("Sair");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
	return 0;
}
