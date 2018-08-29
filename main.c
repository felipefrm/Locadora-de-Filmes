#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void){

  FILE *arq;
  arq = fopen("filmes.txt", "r");
  char c, ano[10], title[N];
  int i, opcao, year;
  Filme f;

  Lista* li = inicializaLista()

  while(1) {

    for (i=0, c = fgetc(arq); c != ','; i++)
      f.titulo[i] = fgetc(arq);

    for (i=0, c = fgetc(arq); c != '\n'; i++)
      ano[i] = fgetc(arq);

    f.ano = convertString(ano);

    if (insereFilme(li, f) == 0)
      fprintf(stderr, "Lista de filmes cheia!\n");

    if (feof(arq) != 0)
      break;
    }
    fclose(arq);


    while (1) {

    printf("----------- LOCADORA -----------");
    printf("O que deseja fazer?");
    printf("[1] Buscar filmes por ano;\n[2] Buscar filmes pelo título;");
    printf("[3] Alugar filme;\n[4] Mostrar todos os filmes;\n[5] Sair");
    scanf("%d", &opcao);

    switch (opcao) {

      case 1:
        printf(">>> ANO: ");
        scanf("%d", year)
        consultaAno(li, year);
        break;

      case 2:
        printf(">>> TÍTULO: ");
        fgets(title, sizeof(title), stdin);
        consultaTitulo(li, title);
        break;

      case 3:
      printf(">>> TÍTULO: ");
      fgets(title, sizeof(title), stdin);
        aluga()
        break;

      case 4:
        //mostrar todos os filmes

      case 5:
        //sair??
    }
  }
  liberaLista(li);
}
