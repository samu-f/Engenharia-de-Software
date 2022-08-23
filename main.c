#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct pedidos {
	
	int codigo;
	char nome[50];
	char endereco[80];
	char pedido[150];
	float valor;	
};

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int i = 0, j, cont = 0,tam = 999, opcao, repetir, busca, acha;
	struct pedidos lista[999];
	
	do {
		
		printf("\n========== RESTAURANTE DO SAMUKA ==========\n\n");
		printf("O que deseja fazer:\n\n");
		printf("1 - Cadastrar Pedido\n");
		printf("2 - Consultar Pedido\n");
		printf("3 - Emitir Relatório\n");
		printf("4 - Sair\n\n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			
			case 1: { // CADASTRAR PEDIDO
				
				cont = i+1;
				
				for (i; i < cont; i++){
					
					system("cls");
					lista[i].codigo = i + 1;
					
					printf("======== CADASTRO DO PEDIDO ========");	
									
					printf("\n\nPedido %d", lista[i].codigo);
					
					printf("\n\nNome: ");
					fflush(stdin);
					gets(lista[i].nome);
					
					printf("Endereço: ");
					fflush(stdin);
					gets(lista[i].endereco);
					
					printf("Pedido: ");
					fflush(stdin);
					gets(lista[i].pedido);
					
					printf("Valor: R$");
					fflush(stdin);
					scanf("%f", &lista[i].valor);
					
					printf("\n\nDeseja cadastrar mais um Pedido?\n\n");
					printf("1 - Sim\n");
					printf("2 - Nao\n\n");
					fflush(stdin);
					scanf("%d", &repetir);
					
					if (repetir == 1) {
						cont = cont+1;						
					}
				
					}				
				
				break;				
			
			}
			
			case 2: { // CONSULTAR PEDIDO
				
				if (i==0 & lista[i].codigo == 0) {
					system("cls");
					printf("\nNenhum Pedido Cadastrado!\n\n");
				}
				
				else {
					system("cls");
					printf("========== CONSULTAR PEDIDO ==========\n\n");
					printf("Digite o código do pedido que deseja consultar: ");
					scanf("%d", &busca);				
				
					j = 0;
					if (lista[j].codigo == 0) {
						
						printf("Nenhum Pedido Encontrado!");
					}
					
					else
					
						j = 0;
						acha = 0;					
						
						while ((j < tam) && (acha == 0)) {
							
							if (lista[j].codigo == busca)
								acha = 1;
								
							else
								j++;					
						}
						
								if (acha == 1) {
								
									printf("\n-------------------------------------------------\n");									
									printf("\nCódigo: %d", j + 1);
									printf("\nNome: %s", lista[j].nome);
									printf("\nEndereço: %s", lista[j].endereco);
									printf("\nPedido: %s", lista[j].pedido);
									printf("\nValor: R$%.2f", lista[j].valor);
									printf("\n\n-------------------------------------------------\n\n");								
												
								}
								
								else
								printf("\n\n======= Pedido não encontrado! =========\n\n");					
				}
				
				break;
			}
			
			case 3: { // BUSCAR PEDIDO
				
				if (i==0 & lista[i].codigo == 0) {
					system("cls");
					printf("\nNenhum Pedido Cadastrado!\n\n");
				}
				
				else {
					system("cls");
					printf("========== RELATÓRIO ==========\n");						
					
					for (j = 0; j < cont; j++){
					
					printf("\nPedido: %d\n", lista[j].codigo);
					printf("\nNome: %s", lista[j].nome);					
					printf("\nEndereco: %s", lista[j].endereco);
					printf("\nPedido: %s", lista[j].pedido);
					printf("\nValor do Pedido: R$%.2f", lista[j].valor);				
					printf("\n\n-------------------------------------------------\n");
					
					}	
				}
				
				break;
			}	
			
			case 4: {
				
				system("cls");
				printf("\n===== Até a Próxima! :-) =====\n");
				
				break;
			}	
		
			default:
				
				system("cls");
				printf("Digite uma opção válida!\n\n");
				break;		
		}			
		
	}
	
	while (opcao != 4);	

	return 0;
}
