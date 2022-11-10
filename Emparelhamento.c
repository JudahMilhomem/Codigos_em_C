// Implementação de Pilhas utilizando Listas Encadeadas:
// Verificação de "Pareamento"
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
  char porta;
  struct pilha *proximo;
} Pilha;

typedef struct topo{
  Pilha *topo;
} Topo;

void inserePilha(Topo *start, char door){
    Pilha *aux;
    aux = malloc(sizeof(Pilha));
    aux->porta = door;

    aux->proximo = start->topo;
    start->topo = aux;
}

void removePilha(Topo *inicio){
  Pilha *aux;
  
  aux = inicio->topo;
  inicio->topo = inicio->topo->proximo;

  free(aux);
}

void verificaPareamento(Topo *start, vet[], tam_vet){
  // Leitura da string:
  for(int r = 0; r < tam_vet; r++){
    inserePilha(&start, vet[r]);
    if(start->topo == NULL){
      // Ação: armazena o elemento na memória e o insere na pilha
      // (Desse modo temos o controle do elemento anterior ao topo)
    } else{
      if(start->topo == ")" && memoria != "("){
        // Ação
      } else if(start->topo == "]" && memoria != "["){
        // Ação
      } else if(start->topo == "}" && memoria != "{"){
        // Ação
      } else{
        removePilha(/*topo*/);
        removePilha(/*memoria*/);
      }
    }
  }

  // Verificação Final:
  if(start->topo == NULL){
    printf("Pareamento correto!");
  } else{
    printf("Pareamento incorreto...");
  }
}

int main(){
  Topo *inicio;
  inicio->topo = NULL;

  char string[50];
  int n;
  printf("Defina um tamanho e digite a string a ser avaliada:\n");
  scanf("%d %s\n", n, string); //

  verificaPareamento(Topo *inicio, string[], n);

  return 0;
}