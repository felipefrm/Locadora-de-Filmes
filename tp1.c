#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// .h

struct filme {
  char titulo[50];
  int ano;
  int locacao;
};

typedef struct lista Lista;
typedef struct filme Filme;

Lista* inicializaLista();
int insereFilme(Lista* li, Filme f);
void liberaLista(Lista* li);
void consultaTitulo(Lista *li, char* title);
void aluga(Filme *f);
void imprimeFilme();
int converteChar(char c);

// .c

#define MAX 100

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

  if (strcmp(li->dados[i].titulo, title) == 0){
    printf("%s, %d", li->dados[i].titulo, li->dados[i].ano);
  }

  return 0;  //nao foi encontrado o elemento

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


// main.c

int main(void){

  int virgula;
  FILE *arq;
  arq = fopen("filmes.txt", "r");
  char c;
  char ano[10];
  int i;
  int year=0;
  Filme f;

  while(1) {

    for (i=0, c = fgetc(arq); c != ','; i++)
      f.titulo[i] = fgetc(arq);

    for (i=0, c = fgetc(arq); c != '\n'; i++)
      ano[i] = fgetc(arq);

    f.ano = convertString(ano);

    if (feof(arq) != 0)
      break;

    /*if (c == ','){
      virgula = i;
      printf("%d", virgula);
      break;*/
    }
  }
}
