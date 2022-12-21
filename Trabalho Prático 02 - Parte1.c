/*
 * Trabalho Prático 02 - Parte 1 
 * Nome do intregrante:
 *  - Alisson Leonardo Moreira Horta 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCESSO                0
#define TAMANHO_MAXIMO_STRING  (100)

// At 4
#define VERDADEIRO             (1 == 1)
#define FALSO                  (! VERDADEIRO)

// At 2
#define NUMERO_DE_DIAS_ANO     (365)
#define NUMERO_DE_DIAS_MESES   (30)

// At 3
#define MINUTOS_EM_SEGUNDOS    (60)
#define HORAS_EM_SEGUNDOS      (60 * MINUTOS_EM_SEGUNDOS)

// At 1
#define TAMANHO_VETOR          (20)
#define MAIOR_VALOR            (0x5)

// At 2 | 4
#define MAIOR_VETOR            1000

// At 3
#define MAIOR_VETOR2           10

// At 1 | 2 | 3
#define NUMERO_DE_LINHAS       (5)
#define NUMERO_DE_COLUNAS      (5)

// At 3
#define DIMENSAO_VETOR         (5)
#define DIMENSAO_RESULTADO     (5)

// At 4
#define QUANT_DE_PRODUTOS       5
#define QUANT_DE_LOJAS          7

#define TAMANHO_MAXIMO_NOME     (100)
#define TAMANHO_MAXIMO_CURSO    (50)
#define NUMERO_MAXIMO_PROVAS    (3)

// At 2
#define NUMERO_MAXIMO_PROVAS    (3)
#define NOTA_MINIMA_APROVACAO   (60.0f)

/////////////////////////////////////////////////
//              Struct Lista 13                //
/////////////////////////////////////////////////

struct dadAlunos {
	char nome[TAMANHO_MAXIMO_NOME];
	char curso[TAMANHO_MAXIMO_CURSO];
	float notas[NUMERO_MAXIMO_PROVAS];
	int idade;
};
typedef struct dadAlunos dadAlunos;

/////////////////////////////////////////////////
//                  Lista 08                   //
/////////////////////////////////////////////////

// At 1
int Soma(int A, int B) {
	return A + B;
}

int Produto(int A, int B) {
	return A * B;
}

int Quociente(int dividendo, int divisor) {
	return dividendo / divisor;
}

void L8Exe01(void) {

	int opcao;
	int A, B, resultado;

	do {

		//Imprimindo o resultado para o usuário
		printf("Escolha a opcao: \n");
		printf(" 1 - Soma \n" " 2 - Produto \n" " 3 - Quociente \n" " 4 - Sair \n");
		printf("Digite a opcao [1 a 4]: ");
		scanf("%d", &opcao);

		if ((opcao >= 1) && (opcao <= 3)) {
			printf("Digite dois numeros: \n");
			scanf("%d %d", &A, &B);
		}

		switch (opcao) {
		case 1:
			resultado = Soma(A, B);
			break;
		case 2:
			resultado = Produto(A, B);
			break;
		case 3:
			resultado = Quociente(A, B);
			break;
		}

		printf("O resultado do calculo e: %d \n", resultado);

	} while (opcao != 4);

}

// At 2

int IdadeEmDias(int anos, int meses, int dias) {
	return ((int)anos * NUMERO_DE_DIAS_ANO) + ((int)meses * NUMERO_DE_DIAS_MESES) + dias;
}

void L8Exe02(void) {

	int anos, dias, meses;
	int diasTotais;

	printf("Digite sua idade em anos, meses e dias: Ex: (30 6 23): \n");
	scanf("%d %d %d", &anos, &meses, &dias);

	diasTotais = IdadeEmDias(anos, meses, dias);

	printf("Sua idade de %d anos, %d meses e %d dias, corresponde ao total de %d dias. \n", anos, meses, dias, diasTotais);

}

// At 3

void L8Exe03(void) {

	int tempo, tempoReal;
	int horas, minutos, segundos;

	printf("Digite o tempo de duracao do experimento em segundos: \n");
	scanf("%d", &tempo);

	tempoReal = tempo;

	horas = tempo / HORAS_EM_SEGUNDOS;
	tempo = tempo % HORAS_EM_SEGUNDOS;
	minutos = tempo / MINUTOS_EM_SEGUNDOS;
	tempo = tempo % MINUTOS_EM_SEGUNDOS;
	segundos = tempo;

	printf("Tempo %d segundos, equivalente a: %d horas, %d minutos, %d segundos. \n ", tempoReal, horas, minutos, segundos);

}

// At 4

int ePRIMO(int numero) {
	int i;

	if (numero == 1) return FALSO;

	for (i = 2; i < numero; i++)
		if ((numero % i) == 0) return FALSO;
	
	return VERDADEIRO;

}

void L8Exe04(void) {

	int numero;
	int ePrimo;

	printf("Digite um numero para saber se e primo: ");
	scanf("%d", &numero);

	ePrimo = ePRIMO(numero);

	//Imprimir o resultado para o usuário
	if (ePrimo) printf(" %d e PRIMO. \n", numero);
	else printf("%d nao e PRIMO. \n", numero);

}

// At 5

int fatorial(int numero) {

	int i;
	int fatorial;

	fatorial = 1;
	for (i = 2; i <= numero; i++)
		fatorial *= i;
	
	return fatorial;

}

void L8Exe05(void) {

	//Declaracao de variaveis
	int numero;
	int valorFatorial;

	printf("Digite o numero para calcular o fatorial: ");
	scanf("%d", &numero);

	// Calculando o fatorial
	valorFatorial = fatorial((int)numero);

	//Retornando o resultado para o usuário
	printf("O fatorial de %d e: %d \n", numero, valorFatorial);

}

void Lista08(void) {

	int NumExercicio;

	do {
		printf("Digite o numero do exercicio que deseja fazer [1 a 5]. 0 para sair: ");
		scanf("%d", &NumExercicio);

		switch (NumExercicio) {
		case 0:
			break;
		case 1:
			L8Exe01();
			break;
		case 2:
			L8Exe02();
			break;
		case 3:
			L8Exe03();
			break;
		case 4:
			L8Exe04();
			break;
		case 5:
			L8Exe05();
			break;
		}

		printf("--------------------------------------------------------------------------\n");

	} while (NumExercicio != 0);

}

/////////////////////////////////////////////////
//                  Lista 09                   //
/////////////////////////////////////////////////

// At 1

void L9Exe01(void) {

	int i, MenorValor, MenorIndice;
	int valores[TAMANHO_VETOR];

	//Obtendo os valores
	for (i = 0; i < TAMANHO_VETOR; i++) {
		printf("Digite o %d valor: ", (i + 1));
		scanf("%d", &valores[i]);
	}

	MenorValor = MAIOR_VALOR;

	for (i = 0; i < TAMANHO_VETOR; i++) {
		if (valores[i] < MenorValor) {
			MenorValor = valores[i];
			MenorIndice = (i + 1);
		}
	}

	printf("O menor valor existente e: %d e esta no indice %d: \n", MenorValor, MenorIndice);

}

// At 2

void L9Exe02(void) {

	int TamanhoVetor, i;
	float valores[MAIOR_VETOR], Escalar;

	//Obtendo os valores
	printf("Digite o tamanho do seu vetor [1 a %d]: ", MAIOR_VETOR);
	scanf("%d", &TamanhoVetor);

	//Lendo os valores
	for (i = 0; i < TamanhoVetor; i++) {
		printf("Digite o %do valor: ", (i + 1));
		scanf("%f", &valores[i]);
	}

	printf("Digite o valor do escalar: ");
	scanf("%f", &Escalar);

	for (i = 0; i < TamanhoVetor; i++)
		valores[i] *= Escalar;
	
	for (i = 0; i < TamanhoVetor; i++)
		printf("O Vetor[%d] x Escalar = %.1f \n", (i + 1), valores[i]);
	
}

// At 3

void L9Exe03(void) {

	int i;
	float Vetor1[MAIOR_VETOR2], Vetor2[MAIOR_VETOR2];
	float ProdutoEscalar = 0.0;

	//Obtendo os valores
	printf("Voce ira preencher dois vetores de 10 posicoes para calcular o produto escalar.\n");
	printf("Vetor1: \n");
	for (i = 0; i < MAIOR_VETOR2; i++) {
		printf("Vetor1[%d]: ", (i + 1));
		scanf("%f", &Vetor1[i]);
	}

	printf("Vetor2: \n");
	for (i = 0; i < MAIOR_VETOR2; i++) {
		printf("Vetor2[%d]: ", (i + 1));
		scanf("%f", &Vetor2[i]);
	}

	for (i = 0; i < MAIOR_VETOR2; i++)
		ProdutoEscalar += Vetor1[i] * Vetor2[i];
	
	//Imprimindo o escalar 
	printf("Vetor1 * Vator2 = %.1f\n", ProdutoEscalar);

}

// At 4

void L9Exe04(void) {

	int TamanhoVetor, i;
	int valores[MAIOR_VETOR], soma, MediaAritmetica;

	//Obtendo os valores
	printf("Digite o valor do vator [1 a %d]: ", MAIOR_VETOR);
	scanf("%d", &TamanhoVetor);

	//Lendo os valores
	for (i = 0; i < TamanhoVetor; i++) {
		printf("Digite o %do valor: ", (i + 1));
		scanf("%d", &valores[i]);
	}

	//Calculando a media aritmetica
	soma = 0.0;

	for (i = 0; i < TamanhoVetor; i++)
		soma += valores[i];
	
	MediaAritmetica = soma / TamanhoVetor;

	//Imprimindo a media
	printf("A media aritmetica dos valores e: %d \n", MediaAritmetica);

}

void Lista09(void) {

	int NumExercicio;

	do {

		printf("Digite o numero do exercicio que deseja fazer [1 a 4]. 0 para sair: ");
		scanf("%d", &NumExercicio);

		switch (NumExercicio) {
		case 0:
			break;
		case 1:
			L9Exe01();
			break;
		case 2:
			L9Exe02();
			break;
		case 3:
			L9Exe03();
			break;
		case 4:
			L9Exe04();
			break;
		}

		printf("--------------------------------------------------------------------------\n");

	} while (NumExercicio != 0);

}

/////////////////////////////////////////////////
//                  Lista 10                   //
/////////////////////////////////////////////////

// At 1

void L10Exe01(void) {

	int i;
	int numEspacos = 0;
	char texto[TAMANHO_MAXIMO_STRING];

	getchar();

	//Dados do usuario
	printf("Digite o seu texto(ate 100 caracteres): \n");
	fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

	for (i = 0; i < strlen(texto); i++)
		if (texto[i] == ' ') numEspacos++;

	printf("O numero de espaco(s) encontrado(s) no seu texto foi %d.\n ", numEspacos);

}

// At 2

void L10Exe02(void) {

	int i;
	char texto[TAMANHO_MAXIMO_STRING];

	getchar();

	//Dados do usuario
	printf("Digite o seu texto(ate 100 caracteres): \n");
	fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

	for (i = 0; i < strlen(texto); i++) {
		if (texto[i] == ' ') continue;
		printf("%c", texto[i]);
	}

}

// At 3

char SAO_VOGAIS[] = { 'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u' };

char eVogal(char letra) {

	int i;

	for (i = 0; i < strlen(SAO_VOGAIS); i++)
		if (letra == SAO_VOGAIS[i])
			return VERDADEIRO;
	
	return FALSO;

}

void L10Exe03(void) {

	int i;
	int numDeVogais = 0;
	char texto[TAMANHO_MAXIMO_STRING];

	getchar();

	//Dados do usuario
	printf("Digite o seu texto(ate 100 caracteres): \n");
	fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

	for (i = 0; i < strlen(texto); i++)
		if (eVogal(texto[i]))
			numDeVogais++;

	printf("O texto digitado possui %d vogal(is). \n", numDeVogais);

}

// At 4

void L10Exe04(void) {

	int i;
	int encontroEspaco = VERDADEIRO;
	char texto[TAMANHO_MAXIMO_STRING];

	getchar();

	//Dados do usuario
	printf("Digite seu texto(ate 100 caracteres): \n");
	fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

	for (i = 0; i < strlen(texto); i++) {
		if (texto[i] == ' ') {
			encontroEspaco = VERDADEIRO;
			continue;
		}
		if (encontroEspaco) {
			if (texto[i] >= 'a' && texto[i] <= 'z')
				texto[i] -= 32;
			encontroEspaco = FALSO;
		}
	}

	printf("O texto convertido ficou: %s", texto);

}

// At 5

void L10Exe05(void) {

	int ePalindromo = VERDADEIRO;
	char texto[TAMANHO_MAXIMO_STRING];
	int i;
	int indEsquerda = 0;
	int indDireita = 0;
	int tamanho;

	getchar();

	printf("Digite uma palavra (ate 100 caracteres) para saber se ela e um palindromo: \n");
	fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

	tamanho = strlen(texto);
	indDireita = tamanho - 2;

	for (i = 0; i < tamanho / 2; i++) {
		if (texto[indEsquerda] == texto[indDireita]) {
			indDireita--;
			indEsquerda++;
		}
		else {
			ePalindromo = FALSO;
			break;
		}
	}

	if (ePalindromo)
		printf("A palavra digitada e um palindromo.\n");
	else
		printf("A palavra digitada nao e um palindromo.\n");

}


// At 6

void L10Exe06(void) {

	int i;
	int ePalindromo = VERDADEIRO;
	char texto[TAMANHO_MAXIMO_STRING];
	char* indEsquerda;
	char* indDireita;
	char DaEsquerda, DaDireita;

	getchar();

	printf("Digite uma palavra (ate 100 caracteres) para saber se ela e um palindromo: \n");
	indEsquerda = fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

	indDireita = indEsquerda + strlen(indEsquerda) - 2;

	for (i = 0; i < strlen(texto) / 2; i++) {

		if (!isalnum(*indDireita)) {
			indDireita--;
			continue;
		}
		if (!isalnum(*indEsquerda)) {
			indEsquerda++;
			continue;
		}

		DaEsquerda = *indEsquerda;
		DaDireita = *indDireita;

		if (islower(DaEsquerda)) DaEsquerda -= 32;
		if (islower(DaDireita)) DaDireita -= 32;

		if (DaEsquerda != DaDireita) {
			ePalindromo = FALSO;
			break;
		}

		indDireita--;
		indEsquerda++;

	}

	if (ePalindromo)
		printf("A palavra digitada e um palindromo.\n");
	else
		printf("A palavra digitada nao e um palindromo.\n");
	
}

void Lista10(void) {

	int NumExercicio;

	do {

		printf("Digite o numero do exercicio que deseja fazer [1 a 6]. 0 para sair: ");
		scanf("%d", &NumExercicio);

		switch (NumExercicio) {
		case 0:
			break;
		case 1:
			L10Exe01();
			break;
		case 2:
			L10Exe02();
			break;
		case 3:
			L10Exe03();
			break;
		case 4:
			L10Exe04();
			break;
		case 5:
			L10Exe05();
			break;
		case 6:
			L10Exe06();
			break;
		}

		printf("--------------------------------------------------------------------------\n");

	} while (NumExercicio != 0);

}

/////////////////////////////////////////////////
//                  Lista 11                   //
/////////////////////////////////////////////////

// At 1

void imprimeTransposta(float Matriz[NUMERO_DE_LINHAS][NUMERO_DE_COLUNAS]) {

	int i, j;

	//Invertendo as linhas com as colunas
	for (i = 0; i < NUMERO_DE_LINHAS; i++) {
		for (j = 0; j < NUMERO_DE_COLUNAS; j++) {
			printf("Matriz[%d][%d]: %.1f \n", (i + 1), (j + 1), Matriz[j][i]);
		}
	}

}

void L11Exe01(void) {

	int i, j;
	float Matriz[NUMERO_DE_LINHAS][NUMERO_DE_COLUNAS];

	//Obtendo os valores do usuario
	printf("Digite os valores reais da matriz: \n");

	for (i = 0; i < NUMERO_DE_LINHAS; i++) {
		for (j = 0; j < NUMERO_DE_COLUNAS; j++) {
			printf("Matriz[%d][%d]: ", (i + 1), (j + 1));
			scanf("%f", &Matriz[i][j]);
		}
	}

	//Imprimindo a transposta para o usuario
	printf("\nA transposta da sua matriz e: \n");
	imprimeTransposta(Matriz);

}

// At 2

void L11Exe02(void) {

	int i, j;
	float SomaElementos = 0;
	float Matriz[NUMERO_DE_LINHAS][NUMERO_DE_COLUNAS];

	//Obtendo os valores do usuario
	printf("Digite os valores reais da matriz: \n");

	for (i = 0; i < NUMERO_DE_LINHAS; i++) {
		for (j = 0; j < NUMERO_DE_COLUNAS; j++) {
			printf("Matriz[%d][%d]: ", (i + 1), (j + 1));
			scanf("%f", &Matriz[i][j]);
		}
	}

	for (i = 0; i < NUMERO_DE_LINHAS; i++)
		for (j = 0; j < NUMERO_DE_COLUNAS; j++)
			SomaElementos += Matriz[i][j];

	//Imprimindo a transposta para o usuario
	printf("\nA soma dos valores da matriz e: %.1f.\n", SomaElementos);

}

// At 3

void MultiplicaVetorPelaMatriz(float Vetor[DIMENSAO_VETOR], float Matriz[NUMERO_DE_LINHAS][NUMERO_DE_COLUNAS], float Resultado[DIMENSAO_RESULTADO]) {

	int i, j;

	for (i = 0; i < NUMERO_DE_LINHAS; i++) {
		Resultado[i] = 0;
		for (j = 0; j < NUMERO_DE_COLUNAS; j++)
			Resultado[i] += Vetor[i] * Matriz[i][j];
	}

}

void L11Exe03(void) {

	int i, j;
	float Matriz[NUMERO_DE_LINHAS][NUMERO_DE_COLUNAS];
	float Vetor[DIMENSAO_VETOR];
	float Resultado[DIMENSAO_RESULTADO];

	//Obtendo os valores do vetor
	printf("Digite os valores do vetor: \n");

	for (i = 0; i < DIMENSAO_VETOR; i++) {
		printf("Vetor[%d]: ", (i + 1));
		scanf("%f", &Vetor[i]);
	}

	//Obtendo os valores da matriz
	printf("Digite os valores da matriz: \n");

	for (i = 0; i < DIMENSAO_VETOR; i++) {
		for (j = 0; j < NUMERO_DE_COLUNAS; j++) {
			printf("Matriz[%d][%d]: ", (i + 1), (j + 1));
			scanf("%f", &Matriz[i][j]);
		}
	}

	MultiplicaVetorPelaMatriz(Vetor, Matriz, Resultado);

	//Imprimindo o resultado para o usuario
	for (i = 0; i < NUMERO_DE_LINHAS; i++)
		printf("O resultado[%d] do vetor pela matriz e: %.1f \n", (i + 1), Resultado[i]);

}

// At 4

void L11Exe04(void) {

	int i, j;
	int MatrizLojProd[QUANT_DE_LOJAS][QUANT_DE_PRODUTOS];
	int TotalProdNasLojas, TotalProdNaLoja;
	int IndLojaComMenosProdutos;
	int TotalLojacomMenosProdutos = 0x7fffffff;

	//Obtendo os valores
	printf("Digite o numero de produtos por lojas: \n");
	for (i = 0; i < QUANT_DE_LOJAS; i++) {
		for (j = 0; j < QUANT_DE_PRODUTOS; j++) {
			printf("Loja [%d] / Produto [%d]: ", (i + 1), (j + 1));
			scanf("%d", &MatrizLojProd[i][j]);
		}
	}

	//Exibindo as informacoes para o usuario
	for (i = 0; i < QUANT_DE_PRODUTOS; i++) {
		TotalProdNasLojas = 0;
		for (j = 0; j < QUANT_DE_LOJAS; j++)
			TotalProdNasLojas += MatrizLojProd[j][i];
		printf("\nTotal de produtos <%d>: %d", (i + 1), TotalProdNasLojas);
	}

	//A loja que tem menos produtos
	for (i = 0; i < QUANT_DE_LOJAS; i++) {
		TotalProdNaLoja = 0;
		for (j = 0; j < QUANT_DE_PRODUTOS; j++)
			TotalProdNaLoja += MatrizLojProd[i][j];
		//Verificando se a loja atual possui menos produtos que a menor delas 
		if (TotalProdNaLoja < TotalLojacomMenosProdutos) {
			TotalLojacomMenosProdutos = TotalProdNaLoja;
			IndLojaComMenosProdutos = (i + 1);
		}
	}

	printf("\nA loja %d possui menos produtos com total de %d produtos.\n", IndLojaComMenosProdutos, TotalLojacomMenosProdutos);

}

void Lista11(void) {

	int NumExercicio;

	do {

		printf("Digite o numero do exercicio que deseja fazer [1 a 4]. 0 para sair: ");
		scanf("%d", &NumExercicio);

		switch (NumExercicio) {
		case 0:
			break;
		case 1:
			L11Exe01();
			break;
		case 2:
			L11Exe02();
			break;
		case 3:
			L11Exe03();
			break;
		case 4:
			L11Exe04();
			break;

		}

        printf("--------------------------------------------------------------------------\n");

	} while (NumExercicio != 0);

}

/////////////////////////////////////////////////
//                  Lista 12                   //
/////////////////////////////////////////////////

// At 1

int* AlocandoVetorInteiros(int tamanhoVetor) {
	return (int*)malloc(tamanhoVetor * sizeof(int));
}

//At 2

float** AlocandoMatrizReais(int NumeroDeLinhas, int NumeroDeColunas) {

	float** Matriz;
	int i;

	//Alocando as linhas da matriz
	Matriz = (float**)malloc(NumeroDeLinhas * sizeof(float*));

	//Alocando as colunas da matriz
	for (i = 0; i < NumeroDeLinhas; i++)
		Matriz[i] = (float*)malloc(NumeroDeColunas * sizeof(float));
	
	return Matriz;

}

// At 3

void L12Exe03(void) {

	int tamanhoVetor, i;
	int* Valores;
	float SomaDosValores = 0.0f, MediaAritmetica = 0.0f;

	//Obtendo os valores
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tamanhoVetor);

	Valores = AlocandoVetorInteiros(tamanhoVetor);

	//Lendo os valores
	for (i = 0; i < tamanhoVetor; i++) {
		printf("Digite o numero inteiro a ser quardado no vetor [%d]: ", (i + 1));
		scanf("%d", &Valores[i]);
	}

	//Calculando a media aritmetica
	for (i = 0; i < tamanhoVetor; i++)
		SomaDosValores += Valores[i];
	
	MediaAritmetica = SomaDosValores / tamanhoVetor;

	//Imprimindo a media aritmetica
	printf("A media aritmetica dos %d valores e: %1.2f\n", tamanhoVetor, MediaAritmetica);

	free(Valores);

}

// At 4

void L12Exe04(void) {

	int tamanhoVetor, i;
	int MenorIndice, MaiorIndice;
	float MenorValor = 0x7fffffff, MaiorValor = -0x7fffffff;
	float* valores;

	//Lendo dados do usuario
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tamanhoVetor);

	//Alocando espacos para os valores
	valores = (float*)malloc(tamanhoVetor * sizeof(float));

	//Lendo os numeros do usuario
	for (i = 0; i < tamanhoVetor; i++) {
		printf("Digite o numero real a ser quardado no vetor [%d]: ", (i + 1));
		scanf("%f", &valores[i]);
	}

	//Verificando qual e o menor valor e seu indice
	for (i = 0; i < tamanhoVetor; i++) {
		if (valores[i] < MenorValor) {
			MenorValor = valores[i];
			MenorIndice = (i + 1);
		}
		//Verificando qual e o maior valor e seu indice
		if (valores[i] > MaiorValor) {
			MaiorValor = valores[i];
			MaiorIndice = (i + 1);
		}
	}

	//Imprimindo o resultado para o usuario
	printf("O menor valor existente e: %1.2f e esta no indice: [%d]\n", MenorValor, MenorIndice);
	printf("O maior valor existente e: %1.2f e esta no indice: [%d]\n", MaiorValor, MaiorIndice);

	free(valores);

}

// At 5

void L12Exe05(void) {

	int i, j, NumeroDeLinhas, NumeroDeColunas;
	float** Matriz, SomaDosValores = 0.0f;

	//Obtendo os valores
	printf("Digite as dimensoes da matriz (numeroLinhas numeroColunas): \n");;
	scanf("%d %d", &NumeroDeLinhas, &NumeroDeColunas);

	Matriz = AlocandoMatrizReais(NumeroDeLinhas, NumeroDeColunas);

	printf("Digite os valores reais da matriz:\n");
	for (i = 0; i < NumeroDeLinhas; i++) {
		for (j = 0; j < NumeroDeColunas; j++) {
			printf("Matriz[%d][%d]: ", (i + 1), (j + 1));
			scanf("%f", &Matriz[i][j]);
		}
	}

	for (i = 0; i < NumeroDeLinhas; i++)
		for (j = 0; j < NumeroDeColunas; j++)
			SomaDosValores += Matriz[i][j];

	printf("A soma de todos os valores desta matriz e: %.2f \n", SomaDosValores);

	for (i = 0; i < NumeroDeLinhas; i++)
		free(Matriz[i]);
	
  free(Matriz);

}

// At 6

void L12Exe06(void) {

	int i, j, numeroDeProdutos, numeroDeLojas;
	int** MatrizLojasProdutos;
	int TotalProdutosNasLojas, TotalProdutosNaLoja;
	int IndiceLojaMenosProdutos;
	int TotalLojacomMenosProdutos = 0x7fffffff;

	//Obtendo as informacoes do usuario
	printf("Digite o numero de lojas: ");
	scanf("%d", &numeroDeLojas);
	printf("Digite o numero de produtos: ");
	scanf("%d", &numeroDeProdutos);

	//Alocando espaco para os valores
	MatrizLojasProdutos = (int**)malloc(numeroDeLojas * sizeof(int*));
	for (i = 0; i < numeroDeLojas; i++)
		MatrizLojasProdutos[i] = (int*)malloc(numeroDeProdutos * sizeof(int));
	
	//Obtendo os valores
	for (i = 0; i < numeroDeLojas; i++) {
		for (j = 0; j < numeroDeProdutos; j++) {
			printf("Loja [%d] / Produto [%d]: ", (i + 1), (j + 1));
			scanf("%d", &MatrizLojasProdutos[i][j]);
		}
	}

	//Exibindo as informacoes para o usuario
	for (i = 0; i < numeroDeProdutos; i++) {
		TotalProdutosNasLojas = 0;
		for (j = 0; j < numeroDeLojas; j++)
			TotalProdutosNasLojas += MatrizLojasProdutos[j][i];
		printf("O total de produtos [%d] eh %d\n", (i + 1), TotalProdutosNasLojas);
	}

	//A loja que tem menos produtos
	for (i = 0; i < numeroDeLojas; i++) {
		TotalProdutosNaLoja = 0;
		for (j = 0; j < numeroDeProdutos; j++)
			TotalProdutosNaLoja += MatrizLojasProdutos[i][j];
		//Verificando se a loja atual possui menos produtos que a menor delas 
		if (TotalProdutosNaLoja < TotalLojacomMenosProdutos) {
			TotalLojacomMenosProdutos = TotalProdutosNaLoja;
			IndiceLojaMenosProdutos = (i + 1);
		}
	}

	printf("A loja %d possui menos produtos com total de %d produtos.\n", IndiceLojaMenosProdutos, TotalLojacomMenosProdutos);

	for (i = 0; i < numeroDeLojas; i++)
		free(MatrizLojasProdutos[i]);
	
  free(MatrizLojasProdutos);

}

void Lista12(void) {

	int NumExercicio;

	do {

		printf("Digite o numero do exercicio que deseja fazer [3 a 6]. 0 para sair: ");
		scanf("%d", &NumExercicio);

		switch (NumExercicio) {
		case 0:
			break;
		case 3:
			L12Exe03();
			break;
		case 4:
			L12Exe04();
			break;
		case 5:
			L12Exe05();
			break;
		case 6:
			L12Exe06();
			break;
		}

		printf("--------------------------------------------------------------------------\n");

	} while (NumExercicio != 0);

}

/////////////////////////////////////////////////
//                  Lista 13                   //
/////////////////////////////////////////////////

// At 1

void lerDadosDoAluno(dadAlunos* aluno) {

	char lixo;

	//Obtendo os valores do aluno
	printf("Entre com os seus dados do aluno:\n");

  setbuf(stdin, 0); // Limpando o buffer
	
  //Nome
	printf("Nome: ");
	fgets(aluno->nome, TAMANHO_MAXIMO_NOME, stdin);
	aluno->nome[strlen(aluno->nome) - 1] = '\0';

  //Curso
	printf("Curso: ");
	fgets(aluno->curso, TAMANHO_MAXIMO_CURSO, stdin);
	aluno->curso[strlen(aluno->curso) - 1] = '\0';

	//Idade
	printf("Idade: ");
	scanf("%d%c", &aluno->idade, &lixo);
	fflush(stdin);

}

void imprimirDadosDoAluno(dadAlunos* aluno) {

	//Imprimindo os valores para o aluno
	printf("Nome: %s\n"\
		"Curso: %s\n"\
		"Idade: %d\n", aluno->nome, aluno->curso, aluno->idade);
}

void L13Exe01(void) {

	dadAlunos aluno;

	//Obtendo os valores do aluno
	lerDadosDoAluno(&aluno);

	//Imprindo os dados do aluno
	imprimirDadosDoAluno(&aluno);

}

// At 2

float calculaMediaNotas(dadAlunos* aluno) {

	int i;
	float SomaNotas = 0.0f;

	for (i = 0; i < NUMERO_MAXIMO_PROVAS; i++)
		SomaNotas += (aluno->notas[i]);
	
	return SomaNotas / NUMERO_MAXIMO_PROVAS;

}

void lendoNotasAluno(dadAlunos* aluno) {

	int i;
	char lixo;

	printf("Digite as notas do aluno:\n");
	for (i = 0; i < NUMERO_MAXIMO_PROVAS; i++) {
		printf("Prova %02d: ", (i + 1));
		scanf("%f%c", &(aluno->notas[i]), &lixo);
	}

}

void L13Exe02(void) {

	dadAlunos aluno;
	float Media;

	//Obtendo os valores do aluno
	lerDadosDoAluno(&aluno);

	//Imprindo os dados do aluno
	imprimirDadosDoAluno(&aluno);

	//Obtendo os valores do aluno
	lendoNotasAluno(&aluno);

	Media = calculaMediaNotas(&aluno);

	//Imprimindo o resultado do aluno
	printf("A media das notas do aluno: %.2f. Resultado: ", Media);
	if (Media >= NOTA_MINIMA_APROVACAO)
		printf("APROVADO");
	else
		printf("REPROVADO");
	
}

// At 3

void imprimeNotasAluno(dadAlunos* aluno) {

	int i;

	printf("Notas do aluno: ");
	for (i = 0; i < NUMERO_MAXIMO_PROVAS; i++)
		printf("[%d]: %.2f ", (i + 1), aluno->notas[i]);
	
  printf("\n");

}

void imprimeDadosDoAlunoNotasMedia(dadAlunos* aluno) {

	imprimirDadosDoAluno(aluno);
	imprimeNotasAluno(aluno);
	printf("Media das notas do aluno: %.2f	Resultado: ", calculaMediaNotas(aluno));
	
  if (calculaMediaNotas(aluno) >= NOTA_MINIMA_APROVACAO)
		printf("APROVADO");
	else
		printf("REPROVADO");
	
  printf("\n");

}

void L13Exe03(void) {

	dadAlunos aluno;
	float Media;
	int i;
	int numAlunos;
	dadAlunos* alunos;
	float SomaMedias = 0.0f;

	char lixo;

	printf("Digite o numero de alunos: ");
	scanf("%d%c", &numAlunos, &lixo);

	alunos = (dadAlunos*)malloc(numAlunos * sizeof(dadAlunos));

	for (i = 0; i < numAlunos; i++) {
		lerDadosDoAluno(&(alunos[i]));
		lendoNotasAluno(&(alunos[i]));
	}

	printf("\nDados dos alunos: \n");
	for (i = 0; i < numAlunos; i++) {
		imprimeDadosDoAlunoNotasMedia(&(alunos[i]));
		SomaMedias += calculaMediaNotas(&(alunos[i]));
	}

	printf("\nA media das notas da turma e: %.2f\n", (SomaMedias / numAlunos));

	free(alunos);

}

// At 4

void OrdenacaoMediaDasNotas(dadAlunos alunos[], int numAlunos) {

	int ConLinhas, ConColunas;
	dadAlunos novAlunos;

	for (ConLinhas = 0; ConLinhas < (numAlunos - 1); ConLinhas++) {
		for (ConColunas = 0; ConColunas < (numAlunos - 1); ConColunas++) {
			if (calculaMediaNotas(&(alunos[ConColunas])) > calculaMediaNotas(&(alunos[ConColunas + 1]))) {
				novAlunos = alunos[ConColunas];
				alunos[ConColunas] = alunos[ConColunas + 1];
				alunos[ConColunas + 1] = novAlunos;
			}
		}
	}

}

void L13Exe04(void) {

	int i;
	int numAlunos;
	dadAlunos* alunos;
	float SomaMedias = 0.0f;

	char lixo;

	printf("Digite o numero de alunos: ");
	scanf("%d%c", &numAlunos, &lixo);

	alunos = (dadAlunos*)malloc(numAlunos * sizeof(dadAlunos));

	for (i = 0; i < numAlunos; i++) {
		lerDadosDoAluno(&(alunos[i]));
		lendoNotasAluno(&(alunos[i]));
	}

	printf("\nDados dos alunos: \n");
	for (i = 0; i < numAlunos; i++) {
		imprimeDadosDoAlunoNotasMedia(&(alunos[i]));
		SomaMedias += calculaMediaNotas(&(alunos[i]));
	}

	printf("\nA media das notas da turma e: %.2f\n", (SomaMedias / numAlunos));

	OrdenacaoMediaDasNotas(alunos, numAlunos);

	printf("\nImprimindo media das notas em ordem crescente: \n");
	for (i = 0; i < numAlunos; i++)
		imprimeDadosDoAlunoNotasMedia(&(alunos[i]));

	free(alunos);

}

void Lista13(void) {

	int NumExercicio;

	do {

		printf("Digite o numero do exercicio que deseja fazer [1 a 4]. 0 para sair: ");
		scanf("%d", &NumExercicio);

		switch (NumExercicio) {
		case 0:
			break;
		case 1:
			L13Exe01();
			break;
		case 2:
			L13Exe02();
			break;
		case 3:
			L13Exe03();
			break;
		case 4:
			L13Exe04();
			break;
		}

		printf("--------------------------------------------------------------------------\n");

	} while (NumExercicio != 0);

}

////////////////////////////////////////////////////////////////////////////
//                           PROGRAMA PRINCIPAL                           //
////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {

	int NumLista;

	do {

		printf("Digite o numero da lista que deseja executar [8 a 13]. 0 para sair: ");
		scanf("%d", &NumLista);

		switch (NumLista) {
		case 0:
			break;
		case 8:
			Lista08();
			break;
		case 9:
			Lista09();
			break;
		case 10:
			Lista10();
			break;
		case 11:
			Lista11();
			break;
		case 12:
			Lista12();
			break;
		case 13:
			Lista13();
			break;
		
		}

		printf("--------------------------------------------------------------------------\n");

	} while (NumLista != 0);

	return SUCESSO;

}
