/*
 * Trabalho Prático 01 - Parte 2
 * Nome do intregrante:
 *  - Alisson Leonardo Moreira Horta 
 */

#include <stdio.h>
#define SUCESSO 0
int main(int argc, char** argv) {
	int opcao, quantidade;
	float refrigerante = 3.50, coxinha = 3.50, paodequeijo = 3.0, pasteldecarne = 1.50, aguamineral = 2.0, total = 0.0;


	do{

		printf("Cardapio:\n");
		printf("(1) Refrigerante... R$ 3.50\n");
		printf("(2) Coxinha........ R$ 3.50\n");
		printf("(3) Pao de queijo.. R$ 3.00\n");
		printf("(4) Pastel de carne R$ 1.50\n");
		printf("(5) Agua mineral... R$ 2.00\n");
		printf("(0) Total\n");

		printf("Digite a opcao: ");
		scanf("%d", &opcao);

		if (opcao != 0) {
			printf("Quantidade: ");
			scanf("%d", &quantidade);
		}
		switch (opcao) {
		case 1:
			total += refrigerante * quantidade;
			break;
		case 2:
			total += coxinha * quantidade;
			break;
		case 3:
			total += paodequeijo * quantidade;
			break;
		case 4:
			total += pasteldecarne * quantidade;
			break;
		case 5:
			total += aguamineral * quantidade;
			break;
		case 0:
			printf("Total.......: R$ %f \n", total);
			printf("Com desconto: R$ %f", total - (0.07 * total));
			break;
		default:
			printf("Opicao invalida");

		}
	} while ((opcao >= 1) || (opcao >= 5));
}