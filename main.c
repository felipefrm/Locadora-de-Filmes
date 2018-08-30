#include <stdio.h>
#include <stdlib.h>
#include "locadora.h"

int main(void){

  FILE *arq;
  arq = fopen("filmes.txt", "r");
  char c, ano[10], titulo[N];
  int i, opcao, ano;
  Filme f;

  Lista* li = inicializaLista()

  while(1) {

    for (i=0, c = fgetc(arq); c != ','; i++)
      f.titulo[i] = fgetc(arq);

    for (i=0, c = fgetc(arq); c != '\n'; i++)
      ano[i] = fgetc(arq);

    f.ano = convertString(ano, i);

    if (insereFilme(li, f) == 0)
      fprintf(stderr, "Lista de filmes cheia!\n");

    if (feof(arq) != 0)
      break;
    }
    fclose(arq);


    while (1) {

    printf("----------- LOCADORA -----------");
    printf("O que deseja fazer?");
    printf("[1] Buscar filme pelo ano;\n[2] Buscar filme pelo título;");
    printf("[3] Alugar filme;\n[4] Visualizar lista de filmes;\n[5] Sair");
    scanf("%d", &opcao);

    switch (opcao) {

      case 1:
        printf(">>> ANO: ");
        scanf("%d", ano)
        consultaAno(li, ano);
        break;

      case 2:
        printf(">>> TÍTULO: ");
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo,"\0")]=NULL;
        if (consultaTitulo(li, titulo) != -1)
        else
        break;

      case 3:
        printf(">>> TÍTULO: ");
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo,"\0")]=NULL;
        alugaPorTitulo(titulo);
        break;

      case 4:
        printf("Lista de filmes ordenados por locações: \n");
        imprimeFilmes(li);
        break;

      case 5:
        goto sair;
        break;

      default:
        printf("Digite corretamente uma das opções acima.\n");
    }
  }
  liberaLista(li);
  sair:
}
