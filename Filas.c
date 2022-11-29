#include <stdio.h>
#include <stdlib.h>

// Declaração dos tipos que serão usados:
typedef int Item;
typedef struct elemFila{
    Item item;
    struct elemFila *proximo;
} ElemFila;
typedef struct{
    ElemFila *primeiro;
    ElemFila *ultimo;
} Fila;

// Declaração das Funções:
void insereFila(Fila *fila, Item item){
    ElemFila *aux;
    aux = malloc(sizeof(ElemFila));
    aux->proximo = NULL;

    if(fila->primeiro == NULL){
        fila->primeiro = aux;
        fila->ultimo = aux;
    } else{
        fila->ultimo->proximo = aux;
        fila->ultimo = aux;
    }
}

void removeFila(Fila *fila, Item *item){
    ElemFila *aux;

    *item = fila->primeiro->item;

    aux = fila->primeiro;
    if(fila->primeiro == fila->ultimo){
        fila->primeiro == NULL;
        fila->ultimo == NULL;
    } else{
        fila->primeiro = fila->primeiro->proximo;
    }
}

void inicializaFila(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int filaVazia(Fila *fila){
    return (fila->primeiro == NULL);
}

void liberaFila(){

}

int main (){
    Fila fila;

    return 0;
}