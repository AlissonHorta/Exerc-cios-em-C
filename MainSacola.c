/*
 * Prova Trimestral de AEDS
 * Data: 06/10/2022
 * 
 * Nome dos intregrantes:
 *  - Thales Davi de Souza
 *  - Alisson Leonardo Moreira Horta 
 */

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sacola.h"

//Contantes
#define SUCESS (0)

//Main
int main(int argc, char** argv){
    //Variáveis
    char* inPath = "leitura.txt";
    FILE* inFile = fopen(inPath, "r");
    int numLinha, op, valor;

    //Estruturas para integrar a sacola
    pilha *stack;
    fila *queue;
    fila *prior;

    //Controladores
    int sCtrl, qCtrl;
    int pCtrl, outCtrl;

    //Se o arquivo não existir criamos um para testes
    if(inFile == NULL){
        inFile = fopen(inPath, "w");
        (void)fprintf(inFile, "6\n");
        (void)fprintf(inFile, "1 1\n");
        (void)fprintf(inFile, "1 2\n");
        (void)fprintf(inFile, "1 3\n");
        (void)fprintf(inFile, "2 1\n");
        (void)fprintf(inFile, "2 2\n");
        (void)fprintf(inFile, "2 3");
        (void)fclose(inFile);
        inFile = fopen(inPath, "r");
    }

    //Lendo o arquivo
    (void)fseek(inFile, 0, SEEK_SET); //Para ter certeza que está no início
    while(!feof(inFile)){
        //Criando as estruturas
        stack = pilha_cria();
        queue = fila_cria();
        prior = fila_cria();
        //Definindo um valor padrao para os controladores
        sCtrl = 1;
        qCtrl = 1;
        pCtrl = 1;

        //Leitura do arquivo
        (void)fscanf(inFile, "%d%*c", &numLinha);
        for(int i = 0; i < numLinha; i++){
            (void)fscanf(inFile, "%d %d%*c", &op, &valor);
            switch(op){
                case INSERIR:
                    sacola_inserir(stack, queue, prior, valor);
                    break;
                case REMOVER:
                    //Removendo da Pilha
                    if(!PILHAFIM(stack) && sCtrl == 1){
                        if(pop(stack) != valor){
                            sCtrl = 0;
                        }
                    }
                    //Removendo da Fila
                    if(!FILAVAZIA(queue) && qCtrl == 1){
                        if(fila_retira(queue) != valor){
                            qCtrl = 0;
                        }
                    }
                    //Removendo da Fila de Prioridade
                    if(!FILAVAZIA(prior) && pCtrl == 1){
                        if(fila_retira(prior) != valor){
                            pCtrl = 0;
                        }
                    }
                    break;
            }
        }

        //outCtrl = Controlador de saida
        outCtrl = sCtrl + qCtrl + pCtrl;

        switch(outCtrl){
            case IMPOSSIBLE: 
                (void)printf("impossible\n");
                break;

            case NORMAL:
                if(sCtrl == 1){
                    (void)printf("stack\n");
                    break;
                }
                if(qCtrl == 1){
                    (void)printf("queue\n");
                    break;
                }
                if(pCtrl == 1){
                    (void)printf("priority queue\n");
                    break;
                }
                break;

            default:
                //Caso a soma do valor dos controladores for maior que 1
                (void)printf("not sure\n");
                break;
        }
        pilha_liberar(stack);
        fila_liberar(queue);
        fila_liberar(prior);
    }

    (void)fclose(inFile);
    return SUCESS;
}