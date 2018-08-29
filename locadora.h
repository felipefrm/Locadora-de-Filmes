#ifndef LOCADORA
#define LOCADORA

struct filme {
  char titulo[N];
  int ano;
  int locacao;
};

typedef struct lista Lista;
typedef struct filme Filme;

Lista* inicializaLista();
int insereFilme(Lista* li, Filme f);
void liberaLista(Lista* li);
void consultaTitulo(Lista *li, char* title);
void consultaAno(Lista *li, int ano);
void aluga(Filme *f);
void imprimeFilme();
int converteChar(char c);

#endif
