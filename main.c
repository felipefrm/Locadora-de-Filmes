#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

int main(void){

  FILE *arq;
  arq = fopen("filmes.txt", "r");
  char c, ano[10], input_titulo[N];
  int opcao, input_ano, sair;
  Filme f;

  Lista* li = inicializaLista();

  while (1) {

    int i;
    for (i=0, c = fgetc(arq); c != ','; c = fgetc(arq), i++){
      if (feof(arq) != 0)
          break;
      f.titulo[i] = c;
    }
    f.titulo[i] = '\0';

    if (feof(arq) != 0)
      break;

    for (i=0, c = fgetc(arq); c != '\n'; c = fgetc(arq), i++)
      ano[i] = c;
    ano[i] = '\0';

    f.ano = convertString(ano);

    if (insereFilme(li, f) == 0)
      fprintf(stderr, "Lista de filmes cheia!\n");
    }

    fclose(arq);

    printf("\n----------- LOCADORA -----------\n");

    while (1) {

    printf("\nO que deseja fazer?\n");
    printf("\n[1] Buscar filme pelo ano;\n[2] Buscar filme pelo título;\n");
    printf("[3] Alugar filme;\n[4] Visualizar lista de filmes;\n[5] Sair\n>>> ");
    scanf("%d", &opcao);

    switch (opcao) {

      case 1:
        printf("\n>>> ANO: ");
        scanf("%d", &input_ano);
        consultaAno(li, input_ano);
        break;

      case 2:
        printf("\n>>> TÍTULO: ");
        setbuf(stdin, NULL);
        fgets(input_titulo, sizeof(input_titulo), stdin);
        input_titulo[strcspn(input_titulo,"\n")] = NULL;   //substitui '\n' por NULL
        consultaTitulo(li, input_titulo);
        break;

      case 3:
        printf("\n>>> TÍTULO: ");
        setbuf(stdin, NULL);
        fgets(input_titulo, sizeof(input_titulo), stdin);
        input_titulo[strcspn(input_titulo,"\n")] = NULL;
        alugaPorTitulo(input_titulo, li);
        break;

      case 4:
        printf("\nLista de filmes ordenados por locações: \n");
        imprimeFilmes(li);
        break;

      case 5:
        sair = 1;
        printf("\nObrigado pela preferência, volte sempre!\n");
        break;

      default:
        printf("\nDigite corretamente uma das opções acima.\n");
    }

    if (sair)
      break;
    printf("\n--------------------------------\n");
  }

  liberaLista(li);
}
