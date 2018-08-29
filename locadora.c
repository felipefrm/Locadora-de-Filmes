#include <locadora.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#define MAX 100
#define N 50

struct lista {
  int qtd;
  struct filme dados[MAX];
};

Lista* inicializaLista(){
  Lista* li = (Lista*)malloc(sizeof(struct lista));
  if(li != NULL)
      li->qtd = 0;
  return li;
}

void liberaLista(Lista* li){
  free(li);
}

int insereFilme(Lista* li, Filme f){
  if (li == NULL)
    return 0;
  if (li->qtd == MAX) //lista cheia
    return 0;
  li->dados[li->qnt] = f;
  li->qtd++;
  return 1;
}

void consultaTitulo(Lista* li, char* title){
  if (li == NULL)
    return 0;
  for (int i=0; i < li->qtd; i++){
    if (strcmp(li->dados[i].titulo, title) == 0){
      printf("%s, %d\n", li->dados[i].titulo, li->dados[i].ano);
      return i;
    }
  }
  return 0;  //nao foi encontrado o elemento
}

void consultaAno(Lista *li, int ano){
  if (li == NULL)
    return 0;
    int i=0, flag=0;
  while (i<li->qtd) {
    if (li->dados[i].ano == ano){
      printf("%s, %d\n", li->dados[i].titulo, li->dados[i].ano);
      flag = 1;
    }
    i++;
    if (flag = 0)
      printf("Não há filmes de %d em nosso banco de dados.\n", ano);
  }
}

void aluga(Filme *f){
  if (f != NULL)
    f->locacao++;
}

void imprimeFilme(){

}

int convertChar(char c){
  return (c - 48);
}

int convertString(char* ano){
  for (int j, expoente=i; j <= i; j++){
    year += convertChar(ano[j]) * pow(10, expoente);
    expoente --;
  }
  return year;
}
