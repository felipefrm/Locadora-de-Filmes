#include <stdio.h>
#include <stdlib.h>

// .h

struct filme {
  char titulo[50];
  int ano;
  int locacao;
};

typedef struct lista Lista;
typedef struct filme Filme;

Lista* inicializaLista();
int insereFilme(Lista* li, struct filme f);
void liberaLista(Lista* li)

// .c

#define MAX 100

struct lista {
  int qtd;
  struct filme dados[MAX];
}

Lista* inicializaLista(){
  Lista* li = (Lista*)malloc(sizeof(struct lista));
  if(li != NULL)
      li->qtd = 0;
  return li;
}

void liberaLista(Lista* li){
  free(li);
}

int insereFilme(Lista* li, struct filme f){
  if (li == NULL)
    return 0;
  if (li->qtd == MAX) //lista cheia
    return 0;
  li->dados[li->qnt] = f;
  li->qtd++;
  return 1;
}

void consultaTitulo(Lista *li, char* title){
  if (li == NULL)
    return 0;
  int i = 0;
  while (i<li->qtd && li->dados[i].titulo != *title)
    i++;
  if (i == li->qtd)
    return 0;  //nao foi encontrado o elemento
  *title = li->dados[i];
  return 1;
}

void aluga(Filme *f){
  if (f != NULL)
    f->locacao++;
}

void imprimeFilme()

// main.c

int main(void){
  FILE *arq;
  arq = fopen("filmes.txt", "r");

  while (!feof(arq)){
    while ()
  }
}
