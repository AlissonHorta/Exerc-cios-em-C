/*
 * Trabalho Prático 01 - Calculadora 
 * Nome do intregrante:
 *  - Alisson Leonardo Moreira Horta 
 */

#include <stdio.h>
#define SUCESSO 0
int main(int argc, char** argv) {
    float x, resultado, numero1, numero2;
	char operador;
        
    x = 1;
    resultado = 1;

    while (x == 1) {

        printf("Digite os numeros a serem calculados e as suas operacoes:\n");
        scanf("%f %c %f", &numero1, &operador, &numero2);


        switch (operador) {
        case '+':
            printf("%f %c %f = %f", numero1, operador, numero2, numero1 + numero2);
            break;
        case '-':
            printf("%f %c %f = %f", numero1, operador, numero2, numero1 - numero2);
            break;
        case '*':
            printf("%f %c %f = %f", numero1, operador, numero2, numero1 * numero2);
            break;
        case '/':
            printf("%f %c %f = %f", numero1, operador, numero2, numero1 / numero2);
            break;
        case '%':
            printf("%f %c %f = %d", numero1, operador, numero2, (int)numero1 % (int)numero2);
            break;
        case '#':
            if ((numero2 - (int)numero2) != 0) {
                printf("Numero inválido");
            }
            else if ("numero 2 == 0") {
                printf("1");
            }
            else if ("numero 2 < 0") {
                resultado = numero1;

                for (int i = (int)numero2; i > 1; i--) {
                    resultado = resultado * numero1;
                }
                resultado = 1;
                printf("%f %c %f = %f", numero1, operador, numero2, resultado);
            }
            else {
                resultado = numero1;

                for (int i = (int)numero2; i > 1; i--) {
                    resultado *= numero1;
                }
                printf("%f %c %f = %f", numero1, operador, numero2, resultado);
            }
            break;
        default:
            printf("Operacao invalida.\n");
            x = 0;
            break;
        }
    }
        printf("A reposta da operação e %f %c %f = %f.\n", numero1, operador, numero2, resultado);

        return SUCESSO;
}
