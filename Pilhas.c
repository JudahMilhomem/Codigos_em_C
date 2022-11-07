// Operações em uma Pilha (lista encadeada)*
#include <stdio.h>
#include <stdlib.h>

// Definição de um elemento genérico pra ser inserido na pilha
typedef struct coisa{
  int item;
  // pode ser modificado ...
} Coisa;

// Estrutura da pilha
typedef struct pilha{
  Coisa elemento;
  struct pilha *proximo;
} Pilha;

// Cria-se um struct específico pra armazenar o TOPO da pilha (organização):
typedef struct{
  Pilha *topo;
} Topo;

void inicializaPilha(Topo *inicio){ // Inicializa uma pilha vazia 
  inicio->topo = NULL;
}

void insereNaPilha(Topo *inicio){ // Insere um nodo na PILHA (início/topo)* 
  Pilha *aux;
  aux = malloc(sizeof(Pilha));
  aux->elemento.item = 21;

  // Links:
  aux->proximo = inicio->topo;
  inicio->topo = aux;

  // Teste
  // int consulta;
  // consulta = inicio->topo->elemento.item;
  // printf("%d", consulta);

} // Obs.: só pode ser feito após inicializar uma lista

void removeDaPilha(Topo *inicio){ // remove um nodo da pilha (considerando pilha não vazia)* 
  Pilha *aux;
  
  // Armazena o valor do item removido pra confirmar o sucesso da operação
  int removido;
  removido = inicio->topo->elemento.item;
  
  aux = inicio->topo;
  inicio->topo = inicio->topo->proximo;

  free(aux);
  printf("O item removido foi: %d\n", removido);
}

void verificaPilha(Topo *inicio){ // Verifica se a pilha está vazia ou não 
  if (inicio->topo == NULL){
    printf("A pilha esta vazia!\n");
    return;
  } else{
    printf("A pilha nao esta vazia...\n");
    return;
  }
}

void liberaPilha(Topo *inicio){ // Libera toda a memória alocada para a pilha 
  Pilha *aux;

  // for(aux = inicio->topo; aux-> proximo != NULL; aux = aux->proximo){}
    while(inicio->topo != NULL){
    aux = inicio->topo;
    inicio->topo = inicio->topo->proximo;

    free(aux);
    printf("Um nodo foi liberado\n");
  }
  printf("Limpeza de memoria completa!\n");
}

int main(){
  Topo *inicio;
  inicializaPilha(&inicio);
  insereNaPilha(&inicio);
  removeDaPilha(&inicio);
  verificaPilha(&inicio);

  // Teste da função liberaPilha:
  insereNaPilha(&inicio);
  insereNaPilha(&inicio);
  insereNaPilha(&inicio);
  liberaPilha(&inicio);
  verificaPilha(&inicio);

  return 0;
}