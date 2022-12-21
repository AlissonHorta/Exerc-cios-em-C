/*
 * Trabalho Prático 02 - Parte 2 
 * Nome do intregrante:
 *  - Alisson Leonardo Moreira Horta 
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define SUCESSO 0
#define TAMANHO_MAXIMO_NOME  100
#define TAMANHO_MAXIMO_INGREDIENTES  20
#define TAMANHO_MAXIMO_INGRE  20

typedef struct ingredientes_e {
	int codigo;
	char nome[TAMANHO_MAXIMO_NOME];

}ingredientes_e;


typedef struct receita_e {
	char codigo_receita[TAMANHO_MAXIMO_NOME];
	int quantidade[TAMANHO_MAXIMO_INGRE];
}receita_e;

ingredientes_e* ListagemIngredientes( ) {

	int i;
	int lixo;

	ingredientes_e IngredientesOrdemCodigo[TAMANHO_MAXIMO_INGREDIENTES] = {
		{1,"Molho de tomate	   "},
		{2,"Farinha de trigo   "},
		{3,"Manjericao		   "},
		{4,"Mussarela		   "},
		{5,"Tomate cortado	   "},
		{6,"Oregano			   "},
		{7,"Acucar		       "},
		{8,"Sal				   "},
		{9,"Ervilha			   "},
		{10,"Fermento biologico"},
		{11,"Azeite            "},
		{12,"Frango desfiado   "},
		{13,"Lombinho fatiado  "},
		{14,"Linguica calabresa"},
		{15,"Catupiry          "},
		{16,"Cheddar           "},
		{17,"Cebola            "},
		{18,"Presunto          "},
		{19,"Ovo               "},
		{20,"Milho             "},
	};

	printf("Ingredientes em ordem de codigo: \n");

	for (i = 0; i < TAMANHO_MAXIMO_INGREDIENTES; i++) {
		printf("%02d  |  %s \n", IngredientesOrdemCodigo[i].codigo, IngredientesOrdemCodigo[i].nome);
	}

	ingredientes_e IngredientesOrdemAlfabetica[TAMANHO_MAXIMO_INGREDIENTES] = {
	{7,"Acucar"},
	{11,"Azeite"},
	{15,"Catupiry"},
	{17,"Cebola"},
	{16,"Cheddar"},
	{9,"Ervilha"},
	{2,"Farinha de trigo"},
	{10,"Fermento biologico"},
	{12,"Frango desfiado"},
	{14,"Linguica calabresa"},
	{13,"Lombinho fatiado"},
	{3,"Manjericao"},
	{20,"Milho"},
	{1,"Molho de tomate"},
	{4,"Mussarela"},
	{6,"Oregano"},
	{19,"Ovo"},
	{18,"Presunto"},
	{8,"Sal"},
	{5,"Tomate cortado"},
	};

	printf("\n\n");
	printf("Ingredientes em ordem alfabetica: \n");

	for (i = 0; i < TAMANHO_MAXIMO_INGREDIENTES; i++) {
		printf("%02d  |  %s \n", IngredientesOrdemAlfabetica[i].codigo, IngredientesOrdemAlfabetica[i].nome);
	}

	ingredientes_e IngredientesOrdemCriacao[TAMANHO_MAXIMO_INGREDIENTES] = {
		{18,"Presunto"},
		{4,"Mussarela"},
		{17,"Cebola"},
		{5,"Tomate cortado"},
		{1,"Molho de tomate"},
		{20,"Milho"},
		{19,"Ovo"},
		{3,"Manjericao"},
		{6,"Oregano"},
		{9,"Ervilha"},
		{7,"Acucar"},
		{11,"Azeite"},
		{2,"Farinha de trigo"},
		{10,"Fermento biologico"},
		{12,"Frango desfiado"},
		{14,"Linguica calabresa"},
		{13,"Lombinho fatiado"},
		{16,"Cheddar"},
		{15,"Catupiry"},
		{8,"Sal"},

	};

	printf("\n\n");
	printf("Ingredientes em ordem de criacao: \n");

	for (i = 0; i < TAMANHO_MAXIMO_INGREDIENTES; i++) {
		printf("%02d  |  %s \n", IngredientesOrdemCriacao[i].codigo, IngredientesOrdemCriacao[i].nome);
	}

	return IngredientesOrdemCodigo;
}


void cadastraReceita(receita_e* receitas, int numReceitas) {

	int i;
	int j;
	int r = 0;
	int verificaNome = 0;
	char Nome[TAMANHO_MAXIMO_NOME];

	char lixo;
	
	setbuf(stdin, 0); // Limpando o buffer

	for (i = 0; i < numReceitas; i++) {
		printf("\nDigite o nome da receita [%d]: ", (i + 1));
		fgets(receitas[i].codigo_receita, TAMANHO_MAXIMO_NOME, stdin);

		printf("\nVoce ira digitar a quantidade de cada ingrediente para fazer sua receita: \n");
		for (j = 0; j < TAMANHO_MAXIMO_INGREDIENTES; j++) {
			printf("Codigo: %02d  |  Quantidade: ", (j + 1));
			scanf("%d%c", &receitas[i].quantidade[j], &lixo);
		}

	}

}

void listaReceita(receita_e* receitas, int numReceitas) {

	int i;

	printf("\nEssas sao suas receitas:\n");
	printf("-----------------------\n\n");
	for (i = 0; i < numReceitas; i++)
		printf("Receita[%d] : %s\n", (i + 1), (receitas[i].codigo_receita));

}

void DetalharReceita(receita_e* receitas, int numReceitas, ingredientes_e* ingredientes) {

	int i, r;
	
	printf("\nEssas sao suas receitas:\n");
	printf("-----------------------\n\n");
	for (r = 0; r < numReceitas; r++) {
		
		printf("Receita[%d] : %s\n", (r + 1), (receitas[r].codigo_receita));
		printf("----------------------------\n");
		printf("QUANTIDADE  |  CODIGO  |  INGREDIENTE\n");
		printf("------------------------------------------\n");
		for (i = 0; i < TAMANHO_MAXIMO_INGREDIENTES; i++)
			printf("%d           |  %2d       |  %s\n", receitas[r].quantidade[i], ingredientes[i].codigo, ingredientes[i].nome);
		printf("---------------------\n");
	}
}


int main(int argc, char** argv) {

	// qru = quantidade de receitas do usuário.
	int opcao;
	int opcao_listagem;
	int qtd_receitas = 20;
	int numReceitas = 0;
	int i, qru;
	int opcao_listagem_Rec;
	char lixo;

	receita_e* receitas;

	receitas = (receita_e*)malloc(qtd_receitas * sizeof(receita_e));

	ingredientes_e IngredientesOrdemCodigo[TAMANHO_MAXIMO_INGREDIENTES] = {
		{1,"Molho de tomate	   "},
		{2,"Farinha de trigo   "},
		{3,"Manjericao		   "},
		{4,"Mussarela		   "},
		{5,"Tomate cortado	   "},
		{6,"Oregano			   "},
		{7,"Acucar		       "},
		{8,"Sal				   "},
		{9,"Ervilha			   "},
		{10,"Fermento biologico"},
		{11,"Azeite            "},
		{12,"Frango desfiado   "},
		{13,"Lombinho fatiado  "},
		{14,"Linguica calabresa"},
		{15,"Catupiry          "},
		{16,"Cheddar           "},
		{17,"Cebola            "},
		{18,"Presunto          "},
		{19,"Ovo               "},
		{20,"Milho             "},
	};

	ingredientes_e IngredientesOrdemAlfabetica[TAMANHO_MAXIMO_INGREDIENTES] = {
		{7,"Acucar"},
		{11,"Azeite"},
		{15,"Catupiry"},
		{17,"Cebola"},
		{16,"Cheddar"},
		{9,"Ervilha"},
		{2,"Farinha de trigo"},
		{10,"Fermento biologico"},
		{12,"Frango desfiado"},
		{14,"Linguica calabresa"},
		{13,"Lombinho fatiado"},
		{3,"Manjericao"},
		{20,"Milho"},
		{1,"Molho de tomate"},
		{4,"Mussarela"},
		{6,"Oregano"},
		{19,"Ovo"},
		{18,"Presunto"},
		{8,"Sal"},
		{5,"Tomate cortado"},
	};

	ingredientes_e IngredientesOrdemCriacao[TAMANHO_MAXIMO_INGREDIENTES] = {
		{18,"Presunto"},
		{4,"Mussarela"},
		{17,"Cebola"},
		{5,"Tomate cortado"},
		{1,"Molho de tomate"},
		{20,"Milho"},
		{19,"Ovo"},
		{3,"Manjericao"},
		{6,"Oregano"},
		{9,"Ervilha"},
		{7,"Acucar"},
		{11,"Azeite"},
		{2,"Farinha de trigo"},
		{10,"Fermento biologico"},
		{12,"Frango desfiado"},
		{14,"Linguica calabresa"},
		{13,"Lombinho fatiado"},
		{16,"Cheddar"},
		{15,"Catupiry"},
		{8,"Sal"},

	};

	printf("\n");

	do {

		printf("\nPizzaria - Menu Principal\n");
		printf("---------------------------\n");
		printf("Opcoes:\n");
		printf("1 - Listar ingredientes cadastrados\n");
		printf("2 - Cadastrar receita\n");
		printf("3 - Listar receitas cadastradas\n");
		printf("4 - Detalhar receita\n");
		printf("0 - Encerrar o sistema\n");

		printf("Escolha uma opcao [0-4]: ");
		scanf("%d", &opcao);

		switch (opcao) {

		case 1:
			printf("\nPizzaria - Menu Listagem de Ingredientes\n");
			printf("--------------------------\n");
			printf("Opcoes:\n");
			printf("1 - Em ordem de codigo\n");
			printf("2 - Em ordem alfabetica\n");
			printf("3 - Em ordem de criacao\n");
			printf("0 - Voltar\n");

			printf("Escolha uma opcao [0-3]: ");
			scanf("%d", &opcao_listagem);

			if (opcao_listagem == 1) {
				printf("\n");
				for (i = 0; i < TAMANHO_MAXIMO_INGREDIENTES; i++) {
					printf("%02d  |  %s \n", IngredientesOrdemCodigo[i].codigo, IngredientesOrdemCodigo[i].nome);
				}
			}
			else if (opcao_listagem == 2) {
				printf("\n");
				for (i = 0; i < TAMANHO_MAXIMO_INGREDIENTES; i++) {
					printf("%02d  |  %s \n", IngredientesOrdemAlfabetica[i].codigo, IngredientesOrdemAlfabetica[i].nome);
				}
			}
			else if (opcao_listagem == 3) {
				printf("\n");
				for (i = 0; i < TAMANHO_MAXIMO_INGREDIENTES; i++) {
					printf("%02d  |  %s \n", IngredientesOrdemCriacao[i].codigo, IngredientesOrdemCriacao[i].nome);
				}
			}
			break;

		case 2:
			printf("\nDeseja cadastrar quantas receitas? ");
			scanf("%d", &qru);
			if ((qru + numReceitas) <= qtd_receitas) {
				cadastraReceita(receitas, qru);
				numReceitas = numReceitas + qru;
			}
			else {
				printf("Quantidade ultrapassa a quantidade maxima a ser cadastrada...\n");
			}
			break;

		case 3:
			if (numReceitas > 0) {
			listaReceita(receitas, numReceitas);
			}
			else {
				printf("Nao existem receitas cadastradas...\n");
			}
			break;

		case 4:
			if (numReceitas > 0) {
				printf("\nPizzaria - Menu Listagem de Receitas\n");
				printf("--------------------------\n");
				printf("Opcoes:\n");
				printf("1 - Em ordem de codigo\n");
				printf("2 - Em ordem alfabetica\n");
				printf("3 - Em ordem de criacao\n");
				printf("0 - Voltar\n");

				printf("Escolha uma opcao [0-3]: ");
				scanf("%d", &opcao_listagem_Rec);

				if (opcao_listagem_Rec == 1) {
					printf("\n");
					
					DetalharReceita(receitas, numReceitas, IngredientesOrdemCodigo);
					
				}
				else if (opcao_listagem_Rec == 2) {
					printf("\n");
					
					DetalharReceita(receitas, numReceitas, IngredientesOrdemAlfabetica);
					
				}

				else if (opcao_listagem_Rec == 3) {
					printf("\n");
					
					DetalharReceita(receitas, numReceitas, IngredientesOrdemCriacao);
				
				}
			}
			
			break;

		}

	} while (opcao != 0);

	printf("\n");

	free(receitas);
	
	return SUCESSO;

	
}