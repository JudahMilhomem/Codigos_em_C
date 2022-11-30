#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemDec{
  char nome[10];
  int id;
  struct elemDec *proximo;
} ElemDec;
typedef struct{
  ElemDec *primeiro;
  ElemDec *ultimo;
} Decolagem;

void listaAvioes(Decolagem *fila){ // conta o número de elementos na fila
  int counter = 0;
  if(fila->primeiro == NULL){
    printf("Não ha nenhum aviao aguardando para decolar");
  } else{
    while(fila->primeiro != NULL){
      counter++;
      fila->primeiro = fila->primeiro->proximo;
    }
    printf("Atualmente, existem %d avioes esperando na fila de decolagem", counter);
  }
}

void entra_naFila(Decolagem *fila, int id){ // adiciona um avião à fila de decolagem
  // Criando espaço e inserindo as informações do novo elemento
  ElemDec *aviao;
  aviao = malloc(sizeof(ElemDec));
  strcpy(aviao->nome, "LATAM");
  aviao->id = 1234;
  aviao->proximo = NULL;

  if(fila->primeiro == NULL){
    fila->primeiro = aviao;
    fila->ultimo = aviao;
  } else{
    fila->ultimo->proximo = aviao;
    fila->ultimo = aviao;
  }
}

int main(){
  // Inicialização da fila
  Decolagem *fila;
  fila->primeiro = NULL;
  fila->ultimo = NULL;

  
}