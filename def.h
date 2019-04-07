#ifndef DEF_H
#define DEF_H
// definições


#define MAX_NOME 10

// INICIO - prototipos das funções.

void gotoxy(int, int);
void display(void);
int menu();
void imprime_tabuleiro(char matriz[13][6]);
void jogo(int*, char matriz[13][6]);
void informacoes(int*, int*, char*, char*);
// FIM - prototipos das funções.

#endif // DEF_H
