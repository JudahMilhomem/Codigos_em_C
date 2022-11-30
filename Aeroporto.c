#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// - - - Tipos - - - //
typedef struct elemDec{
  char nome[10];
  int id;
  struct elemDec *proximo;
} ElemDec;

typedef struct decolagem{
  ElemDec *primeiro;
  ElemDec *ultimo;
} Decolagem;

// - - - Funções - - - //
void iniciaFila(Decolagem *fila){ // inicia uma fila sem nenhum elemento
  fila->primeiro = NULL;
  fila->ultimo = NULL;
}

void entra_naFila(Decolagem *fila, int id){ // adiciona um avião à fila de decolagem
  // Criando espaço e inserindo as informações do novo elemento
  ElemDec *aviao;
  aviao = malloc(sizeof(ElemDec));
  strcpy(aviao->nome, "LATAM");
  aviao->id = id;
  aviao->proximo = NULL;

  if(fila->primeiro == NULL){
    fila->primeiro = aviao;
    fila->ultimo = aviao;
  } else{
    fila->ultimo->proximo = aviao;
    fila->ultimo = aviao;
  }
}

void sai_daFila(Decolagem *fila, int id){ // autoriza a decolagem (o PRIMEIRO avião decola -> sai da fila)
  ElemDec *aviao;

  strcpy(fila->primeiro->nome, "AZUL");
  id = fila->primeiro->id;

  aviao = fila->primeiro;
      if (fila->primeiro == fila->ultimo) {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
    else {
        fila->primeiro = fila->primeiro->proximo;
    }
    free(aviao);
}

void contaAvioes(Decolagem *fila){ // conta o número de elementos na fila
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

void listaInfo(Decolagem *fila){ // mostra as informações do primeiro avião na fila
  printf("Nome: %s\nID: %d\n", fila->primeiro->nome, fila->primeiro->id);
}



int main(){
  // Inicialização da fila
  Decolagem fila;

  iniciaFila(&fila);
  entra_naFila(&fila, 6789);
  entra_naFila(&fila, 1234);
  sai_daFila(&fila, 1234);

  return 0;
}