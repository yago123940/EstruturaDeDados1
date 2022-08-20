#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*OBJETIVO: Vetor Estático*/

void informar_dados_vetor(int *vet,int qtd){
	printf("\nTotal de elementos do vetor = %d",qtd);	
	int i;
	for(i=0;i<qtd;i++){
		printf("\nVET[%d] = ",i);
		scanf("%d",&vet[i]);
	}
	getch();	
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
saida: se encontrou o elemento, retornar o índice onde o mesmo está localizado.
Caso contrário, retornar -1
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
	int qtd;
	int elem;
	
	int *vet = NULL;
	
	do{		
		system("cls");
		printf("\n(1) Informar quantos elementos tem o vetor");
		printf("\n(2) Informar os elementos do vetor");
		printf("\n(3) Imprimir os elementos do vetor");
		printf("\n(4) Buscar um elemento no vetor");
		printf("\n(5) Buscar o maior elemento do vetor");
		printf("\n(6) Buscar o menor elemento do vetor");		
		printf("\n(7) Ordenar o vetor");		
		printf("\n(8) Sair");
		printf("\n\nDigite uma opcao: ");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:				
				do{					
					system("cls");
					printf("\nInforme a quantidade de elementos do vetor: ");
					scanf("%d",&qtd);					
				}while(qtd < 0);
				vet = (int*) malloc(qtd*sizeof(int)); 
				getch();			
				break;
			case 2:
				informar_dados_vetor(vet/*referencia- o nome do vetor, por definição já é um ponteiro*/,
				qtd/*valor*/);
				getch();
				break;
			case 3:
				imprimir_vetor(vet,qtd);
				getch();
				break;
			case 4:				
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

			case 5:
				printf("\nO maior elemento do vetor eh: %d",maior(vet,qtd));
				getch();				
				break;
			case 6:
				printf("\nO menor elemento do vetor eh: %d",menor(vet,qtd));
				getch();				
				break;
			case 7:
				bubble_sort (vet,qtd);
				break;
			
			case 8:
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
