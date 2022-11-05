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

void insereNodo(Topo *inicio){ // Insere um nodo na PILHA (início*)
  Pilha *aux;
  aux = malloc(sizeof(Pilha));
  aux->elemento.item = 1;

  // Links:
  aux->proximo = inicio->topo;
  inicio->topo = aux;
} // Obs.: só pode ser feito após inicializar uma lista

int main(){
  Topo *inicio;
  inicializaPilha(&inicio);
  insereNodo(&inicio);
  int consulta;
  consulta = inicio->topo->elemento.item;
  printf(consulta);

  return 0;
}