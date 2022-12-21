//Constantes
#define TRUE (1==1)
#define FALSE (!TRUE)
#define INSERIR (1)
#define REMOVER (2)
#define IMPOSSIBLE (0)
#define NORMAL (1)
//Macros
#define PILHAFIM(p) ((p->ini == NULL) ? TRUE : FALSE)
#define FILAVAZIA(f) ((f->ini == NULL) ? TRUE : FALSE)
#define FILAFIM(f) ((f == NULL) ? TRUE : FALSE)

//Structs
typedef struct Lista_r{
    int info;
    struct Lista_r* prox;
}lista;

typedef struct Pilha_r{
    lista *ini;
}pilha;

typedef struct Fila_r{
    lista *ini;
    lista *end;
}fila;

//Funções
lista* lista_cria();
pilha* pilha_cria();
fila* fila_cria();
void push(pilha* p, int value);
int pop(pilha* p);
void pilha_liberar(pilha* p);
void fila_insere(fila* f, int value);
int fila_retira(fila *f);
void fila_liberar(fila *f);
void fila_prior_insere(fila* f, int value);
void sacola_inserir(pilha *stack, fila *queue, fila *prior, int value);