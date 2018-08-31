#include "locadora.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 5000

struct lista {
  int qtd;
  struct filme dados[MAX];
};

Lista* inicializaLista(){
  Lista *li;
  li = (Lista*)malloc(sizeof(Lista));
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
  li->dados[li->qtd] = f;
//  printf("%s, qtd: %d\n", li->dados[li->qtd].titulo, li->qtd);
  li->dados[li->qtd].locacao = 0;
  li->qtd++;
  return 1;
}

void consultaTitulo(Lista* li, char* title){
  if (li == NULL)
    return;
  for (int i=0; i < li->qtd; i++)
    if (!strcmp(li->dados[i].titulo, title)){
      printf("%s, %d\n", li->dados[i].titulo, li->dados[i].ano);
      return;
    }
  printf("\nNão foi encontrado filmes com este título em nosso banco de dados.\n");
  return;
}

void consultaAno(Lista *li, int ano){
  if (li == NULL)
    return;
    int i=0, flag=0;
  while (i<li->qtd) {
    if (li->dados[i].ano == ano){
      printf("%s, %d\n", li->dados[i].titulo, li->dados[i].ano);
      flag = 1;
    }
    i++;
  }
  if (flag == 0)
    printf("\nNão há filmes de %d em nosso banco de dados.\n", ano);
}

void aluga(Filme *f){
  if (f != NULL)
    f->locacao++;
  }


void alugaPorTitulo(char* titulo, Lista* li){
  int flag = 0;
  for (int i=0; i<li->qtd; i++)
    if (!strcmp(li->dados[i].titulo, titulo)){
      aluga(&(li->dados[i]));
      flag = 1;
      break;
    }
  if (flag == 0)
    printf("\nNão foi encontrado filmes com este título em nosso banco de dados.\n");
}

void imprimeFilmes(Lista* li){
  Filme aux;
  for(int i=0; i<li->qtd; i++){
    for (int j=i; j<li->qtd; j++){
      if (li->dados[i].locacao < li->dados[j].locacao) {
        aux = li->dados[i];
        li->dados[i] = li->dados[j];
        li->dados[j] = aux;
      }
    }
    printf("%s, %d, locações: %d\n", li->dados[i].titulo, li->dados[i].ano, li->dados[i].locacao);
  }
}

int convertChar(char c){
  return (c - 48);
}

int convertString(char* ano){
  int year = 0, tamanho = strlen(ano);
  for (int i=0, expoente=tamanho-1; i < tamanho; i++){
    year += convertChar(ano[i]) * pow(10, expoente);
    expoente --;
  }
  return year;
}
