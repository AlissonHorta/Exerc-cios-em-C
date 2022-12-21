/*
 * Trabalho Final - Restaurante
 * Nome do intregrante:
 *  - Alisson Leonardo Moreira Horta 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO_NOME				 (100)
#define QUANTIDADE_MAX_INGREDIENTES  (20)
#define QUANTIDADE_MAX_RECEITAS		 (20)
#define VERDADEIRO					 (1 == 1)
#define FALSO						 (!VERDADEIRO)

struct ingrediente_s {
	int codigo;
	char nome[TAMANHO_NOME];
	int ordem;
};
typedef struct ingrediente_s INGREDIENTE_S;

struct receita_s {
	int codigo;
	char descricao[TAMANHO_NOME];
	char ingredientes[QUANTIDADE_MAX_INGREDIENTES][TAMANHO_NOME];
	int quantidades[QUANTIDADE_MAX_INGREDIENTES + 1];
	int ordem_ingredientes[QUANTIDADE_MAX_INGREDIENTES];
	int ordem;
};
typedef struct receita_s RECEITA_S;

//////////////////////////////////////////////////////
//                   INGREDIENTES                   //
//////////////////////////////////////////////////////

void imprimir_ingredientes(INGREDIENTE_S* li, int q) {
	int i;
	printf("\n");
	for (i = 0; i < q; i++)
		printf("%d: %s\n", li[i].codigo, li[i].nome);
	printf("------------\n");
	printf("TOTAL: %d\n", q);
}

void ordenacaoIPorCodigo(INGREDIENTE_S* li, int q) {

	int i, j;
	INGREDIENTE_S tmp;

	for (i = 0; i < (q - 1); i++) {
		for (j = 0; j < (q - 1); j++) {
			// Se estiver fora de ordem...
			if (li[j].codigo > li[j + 1].codigo) {
				// ... troca de posicao
				tmp = li[j];
				li[j] = li[j + 1];
				li[j + 1] = tmp;
			}
		}
	}

}

void ordenacaoIPorNome(INGREDIENTE_S* li, int q) {

	int i, j;
	INGREDIENTE_S tmp;

	for (i = 0; i < (q - 1); i++) {
		for (j = 0; j < (q - 1); j++) {
			// Se estiver fora de ordem...
			if (strcmp(li[j].nome, li[j + 1].nome) > 0) {
				// ... troca de posicao
				tmp = li[j];
				li[j] = li[j + 1];
				li[j + 1] = tmp;
			}
		}
	}

}

void ordenacaoIPorCriacao(INGREDIENTE_S* li, int q) {

	int i, j;
	INGREDIENTE_S tmp;

	for (i = 0; i < (q - 1); i++) {
		for (j = 0; j < (q - 1); j++) {
			// Se estiver fora de ordem...
			if (li[j].ordem > li[j + 1].ordem) {
				// ... troca de posicao
				tmp = li[j];
				li[j] = li[j + 1];
				li[j + 1] = tmp;
			}
		}
	}

}

int pesquisar_codigo_i(INGREDIENTE_S* li, int q, int codigo) {
	int i;
	for (i = 0; i < q; i++)
		if (li[i].codigo == codigo)
			return VERDADEIRO;
	return FALSO;
}

int pesquisar_ingrediente(INGREDIENTE_S* li, int q, char ingrediente[]) {
	int i;
	for (i = 0; i < q; i++)
		if (strcmp(li[i].nome, ingrediente) == 0)
			return VERDADEIRO;
	return FALSO;
}

char* retornar_descricao_ingrediente(INGREDIENTE_S* li, int q, int codigo) {
	int i;
	for (i = 0; i < q; i++)
		if (li[i].codigo == codigo)
			return li[i].nome;
	return NULL;
}

void cadastrar_ingrediente(INGREDIENTE_S* li, int q) {

	char ingrediente[20];
	int codigo, resultado;

	do {
		printf("\nInforme o codigo do ingrediente ......: ");
		
		scanf("%d", &codigo);

		resultado = pesquisar_codigo_i(li, q, codigo);

		if (resultado) printf("Codigo ja existe ........................\n");

	} while (resultado);

	do {
		printf("Informe o nome do ingrediente .: ");
		scanf("%s", ingrediente);
		resultado = pesquisar_ingrediente(li, q, ingrediente);

		if (resultado) {
			printf("Ingrediente ja existe ..........\n");
		}
	} while (resultado);

	li[q].codigo = codigo;
	strcpy(li[q].nome, ingrediente);
	li[q].ordem = q;

}

void listar_ingredientes(INGREDIENTE_S* li, int q) {

	int i, opcao, parar = 0;

	do {

		printf("\n1. Ordem de codigo");
		printf("\n2. Ordem de descricao");
		printf("\n3. Ordem de criacao");
		printf("\n4. Voltar");
		printf("\n>>> ");
		scanf("%d", &opcao);

		printf("\nEscolha uma opcao [1-4]: ");

		switch (opcao) {

		case 1: ordenacaoIPorCodigo(li, q);
			imprimir_ingredientes(li, q);
			break;
		case 2: ordenacaoIPorNome(li, q);
			imprimir_ingredientes(li, q);
			break;
		case 3: ordenacaoIPorCriacao(li, q);
			imprimir_ingredientes(li, q);
			break;
		case 4: parar = 1;
			break;

		}

	} while (!parar);

}

//////////////////////////////////////////////////////
//                     RECEITAS                     //
//////////////////////////////////////////////////////

void imprimir_receitas(RECEITA_S* lr, int q) {
	int i;
	printf("\n");
	for (i = 0; i < q; i++) {
		printf("%d: %s\n", lr[i].codigo, lr[i].descricao);
	}
	printf("------------\n");
	printf("TOTAL: %d\n", q);
}

void imprimir_receitas_e_ingredientes(RECEITA_S* lr, int qr) {
	int r, i, n;
	for (r = 0; r < qr; r++) {
		printf("\n============================");
		printf("\n[%d]: Pizza de %s\n", lr[r].codigo, lr[r].descricao);
		printf("============================\n");
		printf("Ingrediente | Quantidade\n");
		printf("------------------------\n");
		n = lr[r].quantidades[QUANTIDADE_MAX_INGREDIENTES];
		for (i = 0; i < n; i++)
			printf("%*s %*d\n", 8, lr[r].ingredientes[i], 15, lr[r].quantidades[i]);
		printf("============================\n");
	}
	printf("\nTOTAL de receitas: %d\n", qr);
}

void ordenacaoRPorCodigo(RECEITA_S* lr, int q) {

	int i, j;
	RECEITA_S tmp;

	for (i = 0; i < (q - 1); i++) {
		for (j = 0; j < (q - 1); j++) {
			// Se estiver fora de ordem...
			if (lr[j].codigo > lr[j + 1].codigo) {
				// ... troca de posicao
				tmp = lr[j];
				lr[j] = lr[j + 1];
				lr[j + 1] = tmp;
			}
		}
	}

}

void ordenacaoRPorDescricao(RECEITA_S* lr, int q) {

	int i, j;
	RECEITA_S tmp;

	for (i = 0; i < (q - 1); i++) {
		for (j = 0; j < (q - 1); j++) {
			// Se estiver fora de ordem...
			if (strcmp(lr[j].descricao, lr[j + 1].descricao) > 0) {
				// ... troca de posicao
				tmp = lr[j];
				lr[j] = lr[j + 1];
				lr[j + 1] = tmp;
			}
		}
	}

}

void ordenacaoRPorCriacao(RECEITA_S* lr, int q) {

	int i, j;
	RECEITA_S tmp;

	for (i = 0; i < (q - 1); i++) {
		for (j = 0; j < (q - 1); j++) {
			// Se estiver fora de ordem...
			if (lr[j].ordem > lr[j + 1].ordem) {
				// ... troca de posicao
				tmp = lr[j];
				lr[j] = lr[j + 1];
				lr[j + 1] = tmp;
			}
		}
	}

}

void ordenacaoIPorDescricao_R(INGREDIENTE_S* li, int qi, RECEITA_S* lr, int qr) {

	int r, i, j;
	int tmp_q, tmp_o;
	size_t n;
	char tmp_d[TAMANHO_NOME];

	for (r = 0; r < qr; r++) {

		n = lr[r].quantidades[QUANTIDADE_MAX_INGREDIENTES];

		for (i = 0; i < (n - 1); i++) {
			for (j = 0; j < (n - 1); j++) {
				// Se estiver fora de ordem...
				if (strcmp(lr[r].ingredientes[j], lr[r].ingredientes[j + 1]) > 0) {
					// ... troca de posicao
					strcpy(tmp_d, lr[r].ingredientes[j]);
					strcpy(lr[r].ingredientes[j], lr[r].ingredientes[j + 1]);
					strcpy(lr[r].ingredientes[j + 1], tmp_d);
					tmp_q = lr[r].quantidades[j];
					lr[r].quantidades[j] = lr[r].quantidades[j + 1];
					lr[r].quantidades[j + 1] = tmp_q;
					tmp_o = lr[r].ordem_ingredientes[j];
					lr[r].ordem_ingredientes[j] = lr[r].ordem_ingredientes[j + 1];
					lr[r].ordem_ingredientes[j + 1] = tmp_q;
				}
			}
		}

	}

}

void ordenacaoIPorCadastro_R(INGREDIENTE_S* li, int qi, RECEITA_S* lr, int qr) {

	int r, i, j;
	int tmp_q, tmp_o;
	size_t n;
	char tmp_d[TAMANHO_NOME];

	for (r = 0; r < qr; r++) {

		n = lr[r].quantidades[QUANTIDADE_MAX_INGREDIENTES];

		for (i = 0; i < (n - 1); i++) {
			for (j = 0; j < (n - 1); j++) {
				// Se estiver fora de ordem...
				if (lr[r].ordem_ingredientes[j] > lr[r].ordem_ingredientes[j + 1]) {
					// ... troca de posicao
					strcpy(tmp_d, lr[r].ingredientes[j]);
					strcpy(lr[r].ingredientes[j], lr[r].ingredientes[j + 1]);
					strcpy(lr[r].ingredientes[j + 1], tmp_d);
					tmp_q = lr[r].quantidades[j];
					lr[r].quantidades[j] = lr[r].quantidades[j + 1];
					lr[r].quantidades[j + 1] = tmp_q;
					tmp_o = lr[r].ordem_ingredientes[j];
					lr[r].ordem_ingredientes[j] = lr[r].ordem_ingredientes[j + 1];
					lr[r].ordem_ingredientes[j + 1] = tmp_q;
				}
			}
		}

	}

}

int pesquisar_codigo_r(RECEITA_S* lr, int q, int codigo) {
	int i;
	for (i = 0; i < q; i++)
		if (lr[i].codigo == codigo)
			return 1;
	return 0;
}

int pesquisar_descricao(RECEITA_S* lr, int q, char descricao[]) {

	int i;
	for (i = 0; i < q; i++)
		if (strcmp(lr[i].descricao, descricao) == 0)
			return 1;
	return 0;
}

void cadastrar_receita(RECEITA_S* lr, int qr, INGREDIENTE_S* li, int qi) {

	char descricao[TAMANHO_NOME];
	int i, codigo, resultado, n, quantidade;

	do {
		printf("\nInforme o codigo da receita ......................: ");
		scanf("%d", &codigo);

		resultado = pesquisar_codigo_r(lr, qr, codigo);

		if (resultado) {
			printf("Codigo ja existe ....................\n");
		}

	} while (resultado);

	do {

		printf("Informe uma descricao ..................: ");
		
		scanf("%s", descricao);

		resultado = pesquisar_descricao(lr, qr, descricao);

		if (resultado) {
			printf("Receita ja existe .......................\n");
		}
			
	} while (resultado);

	lr[qr].codigo = codigo;
	strcpy(lr[qr].descricao, descricao);

	do {

		printf("\nQuantidade de ingredientes (max de 20) .: ");
		scanf("%d", &n);

	} while ((n < 1) || (n > QUANTIDADE_MAX_INGREDIENTES));

	lr[qr].quantidades[QUANTIDADE_MAX_INGREDIENTES] = n;

	for (i = 0; i < n; i++) {

		imprimir_ingredientes(li, qi);

		do {
			printf("\nCodigo do ingrediente ..................: ");
			scanf("%d", &codigo);

			resultado = pesquisar_codigo_i(li, qi, codigo);

			if (!resultado) {
				printf("Digite um codigo valido...\n");
			}
		} while (!resultado);

		char* desc_ingrediente = retornar_descricao_ingrediente(li, qi, codigo);

		strcpy(lr[qr].ingredientes[i], desc_ingrediente);

		do {
			printf("\nQuantidade deste ingrediente ...........: ");
			scanf("%d", &quantidade);

		} while (quantidade < 1);

		lr[qr].quantidades[i] = quantidade;
		lr[qr].ordem_ingredientes[i] = i;

	}

	lr[qr].ordem = qr;

}

void listar_receitas(RECEITA_S* lr, int q) {

	int i, opcao, parar = 0;

	do {

		printf("\nPizzaria - Menu Listagem de Receitas\n");
		printf("--------------------------------------\n");
		printf("Opcoes:");
		printf("\n1. Ordem de codigo");
		printf("\n2. Ordem de descricao");
		printf("\n3. Ordem de criacao");
		printf("\n4. Voltar");
		printf("\n>>> ");

		printf("\nEscolha uma opcao [1-4]: ");
		scanf("%d", &opcao);

		switch (opcao) {

		case 1: ordenacaoRPorCodigo(lr, q);
			imprimir_receitas(lr, q);
			break;
		case 2: ordenacaoRPorDescricao(lr, q);
			imprimir_receitas(lr, q);
			break;
		case 3: ordenacaoRPorCriacao(lr, q);
			imprimir_receitas(lr, q);
			break;
		case 4: parar = 1;
			break;

		}

	} while (!parar);

}

void listar_RECEITA_S_e_ingredientes(INGREDIENTE_S* li, int qi, RECEITA_S* lr, int qr) {

	int i, opcao, parar = 0;

	do {

		printf("\nPizzaria - Menu Listagem de Receitas e de Ingredientes\n");
		printf("--------------------------------------------------------\n");
		printf("Opcoes:");
		printf("\n1. Ingredientes por ordem de descricao");
		printf("\n2. Ingredientes por ordem de cadastro");
		printf("\n3. Voltar");
		printf("\n>>> ");
		printf("\nEscolha uma opcao [1-3]: ");
		scanf("%d", &opcao);

		switch (opcao) {

		case 1: ordenacaoIPorDescricao_R(li, qi, lr, qr);
			imprimir_receitas_e_ingredientes(lr, qr);
			break;
		case 2: ordenacaoIPorCadastro_R(li, qi, lr, qr);
			imprimir_receitas_e_ingredientes(lr, qr);
			break;
		case 3: parar = 1;
			break;

		}

	} while (!parar);

}

//////////////////////////////////////////////////////
//                     ARQUIVOS                     //
//////////////////////////////////////////////////////

void ler_arquivos(INGREDIENTE_S* li, int* qi, RECEITA_S* lr, int* qr) {

	FILE* arqI = fopen("ingredientes.dat", "rb");
	if (arqI == NULL) return;
	while (1) {
		INGREDIENTE_S inputI;
		size_t r = fread(&inputI, sizeof(INGREDIENTE_S), 1, arqI);
		if (r < 1) break;
		else li[(*qi)++] = inputI;
	}
	fclose(arqI);

	FILE* arqR = fopen("receitas.dat", "rb");
	if (arqR == NULL) return;
	while (1) {
		RECEITA_S inputR;
		size_t r = fread(&inputR, sizeof(RECEITA_S), 1, arqR);
		if (r < 1) break;
		else lr[(*qr)++] = inputR;
	}
	fclose(arqR);

}

void salvar_arquivo(INGREDIENTE_S* li, int qi, RECEITA_S* lr, int qr) {

	FILE* arqI = fopen("ingredientes.dat", "wb");
	if (arqI == NULL) {
		fprintf(stderr, "\nErro na escrita do arquivo\n");
		exit(1);
	}
	fwrite(li, sizeof(INGREDIENTE_S), qi, arqI);
	fclose(arqI);

	FILE* arqR = fopen("receitas.dat", "wb");
	if (arqR == NULL) {
		fprintf(stderr, "\nErro na escrita do arquivo\n");
		exit(1);
	}
	fwrite(lr, sizeof(RECEITA_S), qr, arqR);
	fclose(arqR);

}

//////////////////////////////////////////////////////
//                PROGRAMA PRINCIPAL                //
//////////////////////////////////////////////////////

int main(int argc, char** argv) {

	int opcao, parar = 0;
	int qtd_ingredientes = 0, qtd_receitas = 0;
	int qru;
	int numReceitas = 0;
	int quantReceitas = 20;
	RECEITA_S* receitas;

	INGREDIENTE_S* lista_de_ingredientes;

	lista_de_ingredientes = (INGREDIENTE_S*)malloc(QUANTIDADE_MAX_INGREDIENTES * sizeof(INGREDIENTE_S));

	RECEITA_S* lista_de_receitas;

	lista_de_receitas = (RECEITA_S*)malloc(QUANTIDADE_MAX_RECEITAS * sizeof(RECEITA_S));

	ler_arquivos(lista_de_ingredientes, &qtd_ingredientes, lista_de_receitas, &qtd_receitas);

	receitas = (RECEITA_S*)malloc(qtd_receitas * sizeof(RECEITA_S));

	do {

		printf("\nPizzaria - Menu Principal\n");
		printf("---------------------------\n");
		printf("Opcoes:");
		printf("\n1 - Cadastrar ingrediente         ");
		printf("\n2 - Listar ingredientes           ");
		printf("\n3 - Cadastrar receita             ");
		printf("\n4 - Listar receitas               ");
		printf("\n5 - Listar receitas e ingredientes");
		printf("\n6 - Sair                          ");
		printf("\n>>> ");

		printf("\nEscolha uma opcao [1-6]: ");
		scanf("%d", &opcao);

		switch (opcao) {

		case 1: 

			printf("\nPizzaria - Menu Cadastro de Ingredientes\n");
			printf("--------------------------\n");

			if (qtd_ingredientes <= QUANTIDADE_MAX_INGREDIENTES)
			cadastrar_ingrediente(lista_de_ingredientes, qtd_ingredientes++);

			else printf("\n20 ingredientes cadastrados!\n");
			break;
		case 2: 

			printf("\nPizzaria - Menu Listagem de Ingredientes\n");
			printf("--------------------------\n");
			printf("Opcoes:");

			if (qtd_ingredientes > 0)
			listar_ingredientes(lista_de_ingredientes, qtd_ingredientes);

			else printf("\nNao ha ingrediente(s) cadastrado(s)...\n");
			break;

		case 3: 
			
			printf("\nPizzaria - Menu Cadastro de Receitas\n");
			printf("--------------------------\n");
			
			printf("Digite a quantidade de receitas que voce deseja: ");
			scanf("%d", &qru);

			if ((qru + numReceitas) <= quantReceitas) {

				cadastrar_receita(lista_de_receitas, qtd_receitas++, lista_de_ingredientes, qtd_ingredientes);
			}

			else printf("\n20 receitas cadastradas!\n");
			break;

		case 4: 
					
			if (qtd_receitas > 0) {
				listar_receitas(lista_de_receitas, qtd_receitas);
				printf("------------\n");
				printf("TOTAL: %d\n", qtd_receitas);
			}

			else printf("\nNao ha receita(s) cadastrada(s)...\n");

			break;

		case 5: 

			if ((qtd_ingredientes > 0) && ((qtd_receitas > 0))) {
				listar_RECEITA_S_e_ingredientes(lista_de_ingredientes, qtd_ingredientes, lista_de_receitas, qtd_receitas);
				printf("------------\n");
			}
			
			else printf("\nNao ha cadastro de ingrediente(s) ou receita(s)...\n");
			break;
		case 6: 

			if ((qtd_ingredientes > 0) || ((qtd_receitas > 0))) {
				salvar_arquivo(lista_de_ingredientes, qtd_ingredientes, lista_de_receitas, qtd_receitas);
			}

			parar = 1;

			free(lista_de_ingredientes);
			free(lista_de_receitas);
			printf("\nAplicacao finalizada! :D\n\n");
		
			break;

		}

	} while (!parar);

	return 0;

}
