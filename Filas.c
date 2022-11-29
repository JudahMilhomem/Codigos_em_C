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

void removeFila(){

}

void inicializaFila(){

}

int filaVazia(){

}

void liberaFila(){

}

int main (){
    Fila fila;

    return 0;
}