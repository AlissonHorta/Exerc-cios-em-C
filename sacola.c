//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "sacola.h"

//Funções de criação
lista* lista_cria(){
    return NULL;
}

pilha* pilha_cria(){
    pilha* new = (pilha*)malloc(sizeof(pilha));
    new->ini = lista_cria();
    return new;
}

fila* fila_cria(){
    fila *new = (fila*)malloc(sizeof(fila));
    new->ini = lista_cria();
    new->end = lista_cria();
    return new;
}

//Funções de Pilha
void push(pilha* p, int value){
    lista *new = (lista*)malloc(sizeof(lista));
    new->info = value;
    new->prox = p->ini;
    p->ini = new;
}

int pop(pilha* p){
    lista *temp;
    int retorno;

    if(PILHAFIM(p)){
        (void)printf("Pilha vazia\n");
        return -1;
    }else{
        temp = p->ini->prox;
        retorno = p->ini->info;
        free(p->ini);
        p->ini = temp;
        return retorno;
    }
}

void pilha_liberar(pilha* p){
    lista *temp = p->ini;
    while(!PILHAFIM(p)){
        temp = temp->prox;
        free(p->ini);
        p->ini = temp;
    }
    free(p);
}

//Funções de Fila
void fila_insere(fila* f, int value){
    lista *new = (lista*)malloc(sizeof(lista));
    new->info = value;
    new->prox = NULL;
    if(!FILAVAZIA(f)){
        f->end->prox = new;
        f->end = new;
    }else {
        f->ini = new;
        f->end = new;
    }
}

int fila_retira(fila *f){
    lista *temp;
    int retorno;
    if(!FILAVAZIA(f)){
        temp = f->ini->prox;
        retorno = f->ini->info;
        free(f->ini);
        f->ini = temp;
        return retorno;
    }else{
        (void)printf("Fila vazia.\n");
        return -1;
    }
}

void fila_liberar(fila *f){
    lista *temp;
    while(!FILAVAZIA(f)){
        temp = f->ini->prox;
        free(f->ini);
        f->ini = temp;
    }
    free(f);
}

//Função de Fila de Prioridade
void fila_prior_insere(fila* f, int value){
    lista *new = (lista*)malloc(sizeof(lista));
    lista *temp;
    lista *ant = NULL;
    new->info = value;
    new->prox = NULL;
    if(!FILAVAZIA(f)){
        temp = f->ini;
        while(!FILAFIM(temp)){
            if(temp->info < value){
                if(ant != NULL){
                    ant->prox = new;
                    new->prox = temp;
                }else{
                    new->prox = temp;
                    f->ini = new;
                }
                break;
            }else{
                ant = temp;
                temp = temp->prox;
            }
        }
    }else {
        f->ini = new;
        f->end = new;
    }
}

//Funções do Tipo Sacola
void sacola_inserir(pilha *stack, fila *queue, fila *prior, int value){
    push(stack, value);
    fila_insere(queue, value);
    fila_prior_insere(prior, value);
}