#ifndef LOCADORA
#define LOCADORA

#define N 50

struct filme {
  char titulo[N];
  int ano;
  int locacao;
};

typedef struct lista Lista;
typedef struct filme Filme;

Lista* inicializaLista();
void liberaLista(Lista* li);
int insereFilme(Lista* li, Filme f);
void consultaTitulo(Lista *li, char* title);
void consultaAno(Lista *li, int ano);
void aluga(Filme *f);
void alugaPorTitulo(char* titulo, Lista* li);
void imprimeFilmes(Lista* li);
int converteChar(char c);
int convertString(char* ano);

#endif
