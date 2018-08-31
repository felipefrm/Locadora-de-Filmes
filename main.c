#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

int main(void){

  FILE *arq;
  arq = fopen("filmes.txt", "r");
  char c, ano[10], input_titulo[N];
  int i, opcao, input_ano, sair;
  Filme f;

  Lista* li = inicializaLista();

  while (1) {

    for (i=0, c = fgetc(arq); c != ','; i++)
      f.titulo[i] = fgetc(arq);

    for (i=0, c = fgetc(arq); c != '\n'; i++){
      ano[i] = fgetc(arq);
    }

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
        scanf("%d", &input_ano);
        consultaAno(li, input_ano);
        break;

      case 2:
        printf(">>> TÍTULO: ");
        fgets(input_titulo, sizeof(input_titulo), stdin);
        input_titulo[strcspn(input_titulo,"\0")] = NULL;
        consultaTitulo(li, input_titulo);
        break;

      case 3:
        printf(">>> TÍTULO: ");
        fgets(input_titulo, sizeof(input_titulo), stdin);
        input_titulo[strcspn(input_titulo,"\0")] = NULL;
        alugaPorTitulo(input_titulo, li);
        break;

      case 4:
        printf("Lista de filmes ordenados por locações: \n");
        imprimeFilmes(li);
        break;

      case 5:
        sair = 1;
        break;

      default:
        printf("Digite corretamente uma das opções acima.\n");
    }
    if (sair)
      break;
  }

  liberaLista(li);
}
