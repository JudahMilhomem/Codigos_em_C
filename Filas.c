#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct elemFila{
    Item item;
    struct elemFila *proximo;
} ElemFila;
typedef struct Fila{
    ElemFila *primeiro;
    ElemFila *ultimo;
}

int main (){

    return 0;
}