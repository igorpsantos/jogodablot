// UNIVERSIDADE TUIUTI DO PARANA        //
// Curso: CIÊNCIA DA COMPUTAÇÃO         //
// Autor: IGOR PEREIRA DOS SANTOS       //
// Periodo: 3º PERIODO                  //
// Disciplina: PROGRAMAÇÃO ESTRUTURADA  //
// Tema: Jogo Dablot                    //
// // // // // // // // // // // // // //

// INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "def.h" // arquivo cabeçalho
#include <windows.h> // para utilização do textcolor
#include <time.h> // para uso do rand
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


// FUNÇÃO TEXTCOLOR

typedef char DOS_COLORS;

enum DOS_COLORS {
       BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
       LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
       LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };

//-------------------------------------------------------------

void textcolor (DOS_COLORS iColor)
{
       HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
       CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
       BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
       bufferInfo.wAttributes &= 0x00F0;
       SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

// -------------------------------------------------------------------------
void textbackground (DOS_COLORS iColor)
{
       HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
       CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
       BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
       bufferInfo.wAttributes &= 0x000F;
       SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}

//---------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------------------------
int main() {

    srand(time(NULL));
    // variaveis
    int op; // variavel de opcao
	char tab_jogo[13][6];
	int l, c;
	int cont = 1;
	int *result = 0;
	char nomearquivo[100];
    // variaveis

	// montando o tabuleiro --------------------------------------------------------------------------------

	for (l = 0; l < 13; ++l) {
		for (c = 0; c < 6; ++c) {
			tab_jogo[l][c] = 'C'; // camponeses
			if (cont == 12) {
				tab_jogo[l][c] = ' ';
			}
			if (cont == 24) {
				tab_jogo[l][c] = ' ';
			}
			if (cont == 31) {
				tab_jogo[l][c] = ' ';
			}
			if (cont == 32) {
				tab_jogo[l][c] = '*'; // filho do fazendeiro
			}
			if (cont > 32 && cont < 37) {
				tab_jogo[l][c] = ' '; // espaços vazios
			}
			if (cont == 37) {
				tab_jogo[l][c] = 'F'; //fazendeiro
			}
			if (cont > 37 && cont < 42) {
				tab_jogo[l][c] = ' '; // fazendeiro
			}
			if (cont == 42) {
				tab_jogo[l][c] = 'R'; // rei
			}
			if (cont > 42 && cont < 47) {
				tab_jogo[l][c] = ' '; // espaço vazio
			}
			if (cont == 47) {
				tab_jogo[l][c] = '^'; // principe
			}
			if (cont == 48) {
				tab_jogo[l][c] = ' '; // soldaddos
			}
			if (cont > 48) {
				tab_jogo[l][c] = 'S';
				if (cont == 60) {
					tab_jogo[l][c] = ' ';
				}
				if (cont == 72) {
					tab_jogo[l][c] = ' ';
				}
			}
			++cont;
			
		}
	}
	int voltajogo = 0;
	//------------------------------------------------------------------------------------------------------
INICIOTELA:
	
    display();
    textcolor(GREEN);
    gotoxy(8,20);
    printf("\t\t\t1 - INICIAR NOVO JOGO\t\n");
    textcolor(WHITE);
    op = _getch(); // pega qual tecla foi digitada e não aparece na tela
	system("cls");
	menu(op); // passando por parametros os nome dos jogadores
	system("cls");
	if (op == 49) {
		jogo(&result, tab_jogo); // passando para função para movimentar as peças
	}


	//-------- FIM ---------------------------------------------------------------
	system("PAUSE");
    return EXIT_SUCCESS;
}


//DESCRIÇÃO DA FUNÇÃO GOTOXY

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

// DESCRIÇÃO DA FUNÇÃO DISPLAY

void display(void) {
    textcolor(GREEN);
	printf("************************************************************************************\n");
	printf("*    _______     ___________   ________   ___        __________   _____________    *\n");
	printf("*   |       |    |  ____    |  |  __   |  |  |       |        |   |___      ___|   *\n");
	printf("*   |  ____  |   |  |___|   |  | |__|  |  |  |       |  ___   |       |    |       *\n");
	printf("*   | |    |  |  |   ___    |  |______|   |  |       |  |  |  |       |    |       *\n");
	printf("*   | |____|  |  |   |  |   |  |  __  |   |  |____   |  |__|  |       |    |       *\n");
	printf("*   |        |   |   |  |   |  | |__|  |  |       |  |        |       |    |       *\n");
	printf("*   |_______|    |___|  |___|  |_______|  |_______|  |________|       |____|       *\n");
	printf("*                                                                                  *\n");
	printf("************************************************************************************\n");
	textcolor(WHITE);
	putchar('\n');
	putchar('\n');
	putchar('\n');
	putchar('\n');

}

// DESCRIÇÃO DA FUNÇÃO DO JOGO

int menu(int opcao) {
     
    switch(opcao){
		// se for 1
        case 49:
			return opcao;
        break;
		// se for 2
		case 50:
			return opcao;
			break;
		case 51:
			return opcao;
			break;
    }
}

// DESCRIÇÃO DA FUNCAO IMPRIME TABULEIRO

void imprime_tabuleiro(char matriz[13][6]) {
	int space = 1;
	int l, c;
	gotoxy(1, 1);
	printf("| 0 || 1 || 2 || 3 || 4 || 5 |\n");
	for (l = 0; l < 13; ++l) {
		for (c = 0; c < 6; ++c) {
			printf("| %c |", matriz[l][c]);
			if (space == 6) {
				putchar('\n');
			}
			if (space == 12) {
				putchar('\n');
			}
			if (space == 18) {
				putchar('\n');
			}
			if (space == 24) {
				putchar('\n');
			}
			if (space == 30) {
				putchar('\n');
			}
			if (space == 36) {
				putchar('\n');
			}
			if (space == 42) {
				putchar('\n');
			}
			if (space == 48) {
				putchar('\n');
			}
			if (space == 54) {
				putchar('\n');
			}
			if (space == 60) {
				putchar('\n');
			}
			if (space == 66) {
				putchar('\n');
			}
			if (space == 72) {
				putchar('\n');
			}
			++space;
		}
	}
	gotoxy(31, 2);
	printf("| 0  |\n");
	gotoxy(31, 3);
	printf("| 1  |\n");
	gotoxy(31, 4);
	printf("| 2  |\n");
	gotoxy(31, 5);
	printf("| 3  |\n");
	gotoxy(31, 6);
	printf("| 4  |\n");
	gotoxy(31, 7);
	printf("| 5  |\n");
	gotoxy(31, 8);
	printf("| 6  |\n");
	gotoxy(31, 9);
	printf("| 7  |\n");
	gotoxy(31, 10);
	printf("| 8  |\n");
	gotoxy(31, 11);
	printf("| 9  |\n");
	gotoxy(31,12);
	printf("| 10 |\n");
	gotoxy(31, 13);
	printf("| 11 |\n");
	gotoxy(31, 14);
	printf("| 12 |\n");
	putchar('\n');
}

// DESCRIÇÃO DA FUNÇÃO DO JOGO

void jogo(int* result, char matriz[13][6]) {
	unsigned int sorteio, linha, coluna, direcao1, direcao2,aux1,aux2;
	char tabuleirojogo[13][6];
	int vezdejogada;
	char jogador1[MAX_NOME]; // player 1
	char jogador2[MAX_NOME]; // player 2
	int pecas_jogador1 = 30; // 30 pecas para cada jogador
	int pecas_jogador2 = 30; // 30 pecas para cada jogador
	bool jogada1 = false, jogada2 = false; // decisao de jogada utilizando bool
	char nomearquivo[100];
	char diretorio[200];
	// copiando a matriz do tabuleiro original
	int l, c;
	for (l = 0; l < 13; ++l) {
		for (c = 0; c < 6; ++c) {
			tabuleirojogo[l][c] = matriz[l][c];
		}
	}
	//-------------------------------------
	gotoxy(1, 1);
	display();
	gotoxy(1, 18);
	textcolor(BLUE);
	printf("Digite o nome do primeiro jogador(a): ");
	gets(jogador1);
	printf("Digite o nome do segundo jogador(a): ");
	gets(jogador2);
	gotoxy(1, 18);
	textcolor(BLACK);
	printf("Digite o nome do primeiro jogador:                  "); // para apagar a linha sem usar o system cls que limpa a tela inteira
	gotoxy(1, 19);
	textcolor(BLACK);
	printf("Digite o nome do segundo jogador:                   ");
	system("cls");
	Sleep(500);
	sorteio = rand() % 2 + 1; // 2 ou 1 para par ou impar, e decide quem joga primeiro..
	gotoxy(1, 1);
	textcolor(WHITE);
	imprime_tabuleiro(tabuleirojogo);
	informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
	
	textcolor(WHITE);
	gotoxy(1,15);
	// SORTEIO - PRIMEIRA JOGADA DE CADA JOGADOR, ATRIBUINDO O VALOR NA VARIAVEL JOGADA VEZ PARA NAO REPETIR QUEM VAI JOGAR DENOVO
	if (sorteio == 2) {
		
		printf("O jogador 1 %s comeca a jogar.\n", jogador1);
	INICIO1:
	
		aux1 = 0;
		aux2 = 0;
		printf("Jogador 1 %s escolha uma peca para mover e sua direcao: \n", jogador1);
		printf("linha 1 a 13: ");
		scanf("%u", &linha);
		printf("coluna 1 a 6: ");
		scanf("%u", &coluna);
		printf("Deseja mover a peca para qual direcao? \n");
		printf("linha 1 a 13: ");
		scanf("%u", &direcao1);
		printf("coluna 1 a 6: ");
		scanf("%u", &direcao2);
		char aux;
		
		if (tabuleirojogo[linha][coluna] == 'C' || tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') { // para escolher as pecas validas
			if (direcao1 > linha && direcao2 > coluna) {
				aux1 = direcao1 - linha;
				aux2 = direcao2 - coluna;
			}
			if (direcao1 > linha && direcao2 < coluna) {
				aux1 = direcao1 - linha;
				aux2 = coluna - direcao2;
			}
			if (direcao1 < linha && direcao2 > coluna) {
				aux1 = linha - direcao1;
				aux2 = direcao2 - coluna;
			}
			if (direcao1 < linha && direcao2 < coluna) {
				aux1 = linha - direcao1;
				aux2 = coluna - direcao2;
			}
			if (aux1 == 0 || aux1 == 1 && aux2 == 0 || aux2 == 1) {
				if (tabuleirojogo[direcao1][direcao2] == ' ') {
					aux = tabuleirojogo[linha][coluna]; // escolhe a peça que é para remover
					tabuleirojogo[direcao1][direcao2] = aux; // move a peca que escolheu para a posicao que deseja
					tabuleirojogo[linha][coluna] = ' '; // remove a peça
					gotoxy(1, 1);
					imprime_tabuleiro(tabuleirojogo);
					jogada1 = true;
					system("cls");
					informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
					gotoxy(1, 1);
					imprime_tabuleiro(tabuleirojogo);
					vezdejogada = 0;
				}
				else {
					printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
					Sleep(500);
					system("cls");
					informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
					gotoxy(1, 1);
					imprime_tabuleiro(tabuleirojogo);
					goto INICIO1;
				}
			}else {
				printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
				Sleep(500);
				system("cls");
				informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
				gotoxy(1, 1);
				imprime_tabuleiro(tabuleirojogo);
				goto INICIO1;
			}
			
		}else {
			printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
			system("cls");
			system("cls");
			informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
			gotoxy(1, 1);
			imprime_tabuleiro(tabuleirojogo);
			goto INICIO1;
		}
	}else {
		if (sorteio == 1) {
			
			printf("O jogador 2 %s comeca a jogar.\n", jogador2);
		INICIO2:
			
			aux1 = 0;
			aux2 = 0;
			printf("Jogador 2 %s escolha uma peca para mover e sua direcao: \n", jogador2);
			printf("linha 1 a 13: ");
			scanf("%u", &linha);
			printf("coluna 1 a 6: ");
			scanf("%u", &coluna);
			printf("Deseja mover a peca para qual direcao? \n");
			printf("linha 1 a 13: ");
			scanf("%u", &direcao1);
			printf("coluna 1 a 6: ");
			scanf("%u", &direcao2);
			char aux;
			
			if (tabuleirojogo[linha][coluna] == 'S' || tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
				if (direcao1 > linha && direcao2 > coluna) {
					aux1 = direcao1 - linha;
					aux2 = direcao2 - coluna;
				}
				if (direcao1 > linha && direcao2 < coluna) {
					aux1 = direcao1 - linha;
					aux2 = coluna - direcao2;
				}
				if (direcao1 < linha && direcao2 > coluna) {
					aux1 = linha - direcao1;
					aux2 = direcao2 - coluna;
				}
				if (direcao1 < linha && direcao2 < coluna) {
					aux1 = linha - direcao1;
					aux2 = coluna - direcao2;
				}
				// condicao para jogadas invalidas
				if (aux1 == 0 || aux1 == 1 && aux2 == 0 || aux2 == 1) {
					if (tabuleirojogo[direcao1][direcao2] == ' ') {
						aux = tabuleirojogo[linha][coluna]; // escolhe a peça que é para remover
						tabuleirojogo[direcao1][direcao2] = aux; // move a peca que escolheu para a posicao que deseja
						tabuleirojogo[linha][coluna] = ' '; // remove a peça
						imprime_tabuleiro(tabuleirojogo);
						jogada2 = true;
						vezdejogada = 1; // para nao repetir a jogada quando entrar no laço
						system("cls");
						informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
						gotoxy(1, 1);
						imprime_tabuleiro(tabuleirojogo);
					}
					else {
						printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
						Sleep(500);
						system("cls");
						informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
						gotoxy(1, 1);
						imprime_tabuleiro(tabuleirojogo);
						goto INICIO2;
					}
				}
				else {
					printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
					Sleep(500);
					system("cls");
					informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
					gotoxy(1, 1);
					imprime_tabuleiro(tabuleirojogo);
					goto INICIO2;
				}
			}else {
				printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
				Sleep(500);
				system("cls");
				informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
				gotoxy(1, 1);
				imprime_tabuleiro(tabuleirojogo);
				goto INICIO2;
			}
		}
	}
	
	// VERIFICAR UM JEITO DE FAZER AS PECAS SE MOVEREM, E CONTAR A QUANTIDADE DE PECAS...
	// SERIA IDEAL UTILIZAR COMO SE FOSSE UM JOGO DE MINA PARA MOVER AS PEÇAS
	// E CONTAR A QUANTIDADES DE C QUANDO FOR MONTAR UMA COPIA DA MATRIZ
	// E CADA VEZ QUE REMOVER UMA PEÇA REMOVER DA QUANTIDADE TOTAL DE PEÇAS DO CONTADOR DE PÇAS
	// PARA UTILIZAR UM FIM DE JOGO....
	// CONTINUACAO DO JOGO DEPOIS DA PRIMEIRA JOGADA
	bool rei, fazendeiro;
	rei = true;
	fazendeiro = true;
	char decisaoacabajogo1,decisaoacabajogo2;
	char aux_caracter;
	do {
		
		if (vezdejogada % 2 != 0) { // se for impar o jogador 1 joga
		INICIO3:
			putchar('\n');
			aux1 = 0;
			aux2 = 0;
			printf("Jogador 1 %s escolha uma peca para mover e sua direcao: \n", jogador1);
			printf("linha 1 a 13: ");
			scanf("%u", &linha);
			printf("coluna 1 a 6: ");
			scanf("%u", &coluna);
			printf("Deseja mover a peca para qual direcao? \n");
			printf("linha 1 a 13: ");
			scanf("%u", &direcao1);
			printf("coluna 1 a 6: ");
			scanf("%u", &direcao2);
			
			char aux;
			
			if (tabuleirojogo[linha][coluna] == 'C' || tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') { // para escolher as pecas validas
				//CONDIÇÕES DE PRIMEIRA JOGADA, PARA APENAS MOVER UMA CASA POR VEZ E SE FOR VALIDO
				if (direcao1 >= linha && direcao2 >= coluna) {
					aux1 = direcao1 - linha;
					aux2 = direcao2 - coluna;
				}
				if (direcao1 >= linha && direcao2 <= coluna) {
					aux1 = direcao1 - linha;
					aux2 = coluna - direcao2;
				}
				if (direcao1 <= linha && direcao2 >= coluna) {
					aux1 = linha - direcao1;
					aux2 = direcao2 - coluna;
				}
				if (direcao1 <= linha && direcao2 <= coluna) {
					aux1 = linha - direcao1;
					aux2 = coluna - direcao2;
				}
				if (aux1 <= 1 && aux2 <= 1) {
					if (tabuleirojogo[direcao1][direcao2] == ' ') {
						aux = tabuleirojogo[linha][coluna]; // escolhe a peça que é para remover
						tabuleirojogo[direcao1][direcao2] = aux; // move a peca que escolheu para a posicao que deseja
						tabuleirojogo[linha][coluna] = ' '; // remove a peça
						gotoxy(1, 1);
						imprime_tabuleiro(tabuleirojogo);
						informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
					}
					else {
						printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
						Sleep(500);
						system("cls");
						informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
						gotoxy(1, 1);
						imprime_tabuleiro(tabuleirojogo);
						goto INICIO3;
					}
				}
				else {
						// CONDIÇÕES DE VALIDAÇÃO DE MOVIMENTAÇÃO DE PEÇAS
						// DECISAO 1
						if (aux1 == 2 && aux2 == 2 && direcao1 > linha && direcao2 < coluna) {
							if (tabuleirojogo[linha + 1][coluna - 1] == 'S') {
								if (tabuleirojogo[direcao1][direcao2] == ' ') {
									aux = tabuleirojogo[linha][coluna];
									tabuleirojogo[direcao1][direcao2] = aux;
									tabuleirojogo[linha + 1][coluna - 1] = ' '; // captura a peca do adversario
									tabuleirojogo[linha][coluna] = ' ';
									--pecas_jogador2; // remove a peca do segundo jogador
									informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
									gotoxy(1, 1);
									imprime_tabuleiro(tabuleirojogo);
								}
							}
							else {
								if (tabuleirojogo[linha + 1][coluna - 1] == '^') {
									if (tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') {
										if (tabuleirojogo[direcao1][direcao2] == ' ') {
											aux = tabuleirojogo[linha][coluna];
											tabuleirojogo[direcao1][direcao2] = aux;
											tabuleirojogo[linha + 1][coluna - 1] = ' '; // captura a peca do adversario
											tabuleirojogo[linha][coluna] = ' ';
											--pecas_jogador2; // remove a peca do segundo jogador
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO3;
									}
								}
								else {
									if (tabuleirojogo[linha + 1][coluna - 1] == 'R') {
										if (tabuleirojogo[linha][coluna] == 'F') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha + 1][coluna - 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador2;
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
												rei = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
												system("cls");
												textcolor(YELLOW);
											
												putchar('\n');
												printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador2);
												scanf(" %c", &aux_caracter);
												decisaoacabajogo1 = toupper(aux_caracter);
												if (decisaoacabajogo1 == 'S') {
													printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador1);
													break;
												}
												else {
													if (decisaoacabajogo1 == 'N') {
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto INICIO4;
													}
													else {
														printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto DECISAOGANHA1;
													}
												}
											}
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO3;
									}
								}
							}
						}
						else {
							// DECISAO 2
							if (aux1 == 2 && aux2 == 0 && direcao1 > linha && direcao2 == coluna) {
								if (tabuleirojogo[linha + 1][coluna] == 'S') {
									if (tabuleirojogo[direcao1][direcao2] == ' ') {
										aux = tabuleirojogo[linha][coluna];
										tabuleirojogo[direcao1][direcao2] = aux;
										tabuleirojogo[linha + 1][coluna] = ' '; // captura a peca do adversario
										tabuleirojogo[linha][coluna] = ' ';
										--pecas_jogador2; // remove a peca do segundo jogador
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
									}
								}
								else {
									if (tabuleirojogo[linha + 1][coluna] == '^') {
										if (tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha + 1][coluna] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador2; // remove a peca do segundo jogador
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO3;
										}
									}
									else {
										if (tabuleirojogo[linha + 1][coluna] == 'R') {
											if (tabuleirojogo[linha][coluna] == 'F') {
												if (tabuleirojogo[direcao1][direcao2] == ' ') {
													aux = tabuleirojogo[linha][coluna];
													tabuleirojogo[direcao1][direcao2] = aux;
													tabuleirojogo[linha + 1][coluna] = ' '; // captura a peca do adversario
													tabuleirojogo[linha][coluna] = ' ';
													--pecas_jogador2;
													informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
													gotoxy(1, 1);
													imprime_tabuleiro(tabuleirojogo);
													rei = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
													system("cls");
													textcolor(YELLOW);
												
													putchar('\n');
													printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador2);
													scanf(" %c", &aux_caracter);
													decisaoacabajogo1 = toupper(aux_caracter);
													if (decisaoacabajogo1 == 'S') {
														printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador1);
														break;
													}
													else {
														if (decisaoacabajogo1 == 'N') {
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto INICIO4;
														}
														else {
															printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto DECISAOGANHA1;
														}
													}
												}
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO3;
										}
									}
								}
							}// DECISAO 3
						}if (aux1 == 2 && aux2 == 2 && direcao1 > linha && direcao2 > coluna) {
							if (tabuleirojogo[linha + 1][coluna + 1] == 'S') {
								if (tabuleirojogo[direcao1][direcao2] == ' ') {
									aux = tabuleirojogo[linha][coluna];
									tabuleirojogo[direcao1][direcao2] = aux;
									tabuleirojogo[linha + 1][coluna + 1] = ' '; // captura a peca do adversario
									tabuleirojogo[linha][coluna] = ' ';
									--pecas_jogador2; // remove a peca do segundo jogador
									informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
									gotoxy(1, 1);
									imprime_tabuleiro(tabuleirojogo);
								}
							}
							else {
								if (tabuleirojogo[linha + 1][coluna + 1] == '^') {
									if (tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') {
										if (tabuleirojogo[direcao1][direcao2] == ' ') {
											aux = tabuleirojogo[linha][coluna];
											tabuleirojogo[direcao1][direcao2] = aux;
											tabuleirojogo[linha + 1][coluna + 1] = ' '; // captura a peca do adversario
											tabuleirojogo[linha][coluna] = ' ';
											--pecas_jogador2; // remove a peca do segundo jogador
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO3;
									}
								}
								else {
									if (tabuleirojogo[linha + 1][coluna + 1] == 'R') {
										if (tabuleirojogo[linha][coluna] == 'F') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha + 1][coluna + 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador2;
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
												rei = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
												system("cls");
												textcolor(YELLOW);
											
												putchar('\n');
												printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador2);
												scanf(" %c", &aux_caracter);
												decisaoacabajogo1 = toupper(aux_caracter);
												if (decisaoacabajogo1 == 'S') {
													printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador1);
													break;
												}
												else {
													if (decisaoacabajogo1 == 'N') {
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto INICIO4;
													}
													else {
														printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto DECISAOGANHA1;
													}
												}
											}
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO3;
									}
								}
							}
						}
						else {
							// DECISAO 4
							if (aux1 == 0 && aux2 == 2 && direcao1 == linha && direcao2 < coluna) {
								if (tabuleirojogo[linha][coluna - 1] == 'S') {
									if (tabuleirojogo[direcao1][direcao2] == ' ') {
										aux = tabuleirojogo[linha][coluna];
										tabuleirojogo[direcao1][direcao2] = aux;
										tabuleirojogo[linha][coluna - 1] = ' '; // captura a peca do adversario
										tabuleirojogo[linha][coluna] = ' ';
										--pecas_jogador2; // remove a peca do segundo jogador
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
									}
								}
								else {
									if (tabuleirojogo[linha][coluna - 1] == '^') {
										if (tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha][coluna - 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador2; // remove a peca do segundo jogador
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO3;
										}
									}
									else {
										if (tabuleirojogo[linha][coluna - 1] == 'R') {
											if (tabuleirojogo[linha][coluna] == 'F') {
												if (tabuleirojogo[direcao1][direcao2] == ' ') {
													aux = tabuleirojogo[linha][coluna];
													tabuleirojogo[direcao1][direcao2] = aux;
													tabuleirojogo[linha][coluna - 1] = ' '; // captura a peca do adversario
													tabuleirojogo[linha][coluna] = ' ';
													--pecas_jogador2;
													informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
													gotoxy(1, 1);
													imprime_tabuleiro(tabuleirojogo);
													rei = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
													system("cls");
													textcolor(YELLOW);
													
													putchar('\n');
													printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador2);
													scanf(" %c", &aux_caracter);
													decisaoacabajogo1 = toupper(aux_caracter);
													if (decisaoacabajogo1 == 'S') {
														printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador1);
														break;
													}
													else {
														if (decisaoacabajogo1 == 'N') {
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto INICIO4;
														}
														else {
															printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto DECISAOGANHA1;
														}
													}
												}
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO3;
										}
									}
								}
							}// decisao 5
						}if (aux1 == 0 && aux2 == 2 && direcao1 == linha && direcao2 > coluna) {
							if (tabuleirojogo[linha][coluna + 1] == 'S') {
								if (tabuleirojogo[direcao1][direcao2] == ' ') {
									aux = tabuleirojogo[linha][coluna];
									tabuleirojogo[direcao1][direcao2] = aux;
									tabuleirojogo[linha][coluna + 1] = ' '; // captura a peca do adversario
									tabuleirojogo[linha][coluna] = ' ';
									--pecas_jogador2; // remove a peca do segundo jogador
									informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
									gotoxy(1, 1);
									imprime_tabuleiro(tabuleirojogo);
								}
							}else {
								if (tabuleirojogo[linha][coluna + 1] == '^') {
									if (tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') {
										if (tabuleirojogo[direcao1][direcao2] == ' ') {
											aux = tabuleirojogo[linha][coluna];
											tabuleirojogo[direcao1][direcao2] = aux;
											tabuleirojogo[linha][coluna + 1] = ' '; // captura a peca do adversario
											tabuleirojogo[linha][coluna] = ' ';
											--pecas_jogador2; // remove a peca do segundo jogador
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO3;
									}
								}
								else {
									if (tabuleirojogo[linha][coluna + 1] == 'R') {
										if (tabuleirojogo[linha][coluna] == 'F') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha][coluna + 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador2;
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
												rei = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
												system("cls");
												textcolor(YELLOW);
												
												putchar('\n');
												printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador2);
												scanf(" %c", &aux_caracter);
												decisaoacabajogo1 = toupper(aux_caracter);
												if (decisaoacabajogo1 == 'S') {
													printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador1);
													break;
												}
												else {
													if (decisaoacabajogo1 == 'N') {
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto INICIO4;
													}
													else {
														printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto DECISAOGANHA1;
													}
												}
											}
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO3;
									}
								}
							}
						}
						else {
							//decisao 6
							if (aux1 == 2 && aux2 == 2 && direcao1 < linha && direcao2 < coluna) {
								if (tabuleirojogo[linha - 1][coluna - 1] == 'S') {
									if (tabuleirojogo[direcao1][direcao2] == ' ') {
										aux = tabuleirojogo[linha][coluna];
										tabuleirojogo[direcao1][direcao2] = aux;
										tabuleirojogo[linha - 1][coluna - 1] = ' '; // captura a peca do adversario
										tabuleirojogo[linha][coluna] = ' ';
										--pecas_jogador2; // remove a peca do segundo jogador
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
									}
								}
								else {
									if (tabuleirojogo[linha - 1][coluna - 1] == '^') {
										if (tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha - 1][coluna - 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador2; // remove a peca do segundo jogador
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO3;
										}
									}
									else {
										if (tabuleirojogo[linha - 1][coluna - 1] == 'R') {
											if (tabuleirojogo[linha][coluna] == 'F') {
												if (tabuleirojogo[direcao1][direcao2] == ' ') {
													aux = tabuleirojogo[linha][coluna];
													tabuleirojogo[direcao1][direcao2] = aux;
													tabuleirojogo[linha - 1][coluna - 1] = ' '; // captura a peca do adversario
													tabuleirojogo[linha][coluna] = ' ';
													--pecas_jogador2;
													informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
													gotoxy(1, 1);
													imprime_tabuleiro(tabuleirojogo);
													rei = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
													system("cls");
													textcolor(YELLOW);
													
													putchar('\n');
													printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador2);
													scanf(" %c", &aux_caracter);
													decisaoacabajogo1 = toupper(aux_caracter);
													if (decisaoacabajogo1 == 'S') {
														printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador1);
														break;
													}
													else {
														if (decisaoacabajogo1 == 'N') {
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto INICIO4;
														}
														else {
															printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto DECISAOGANHA1;
														}
													}
												}
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO3;
										}
									}
								}
							}// decisao 7
						}if (aux1 == 2 && aux2 == 0 && direcao1 < linha && direcao2 == coluna) {
							if (tabuleirojogo[linha - 1][coluna] == 'S') {
								if (tabuleirojogo[direcao1][direcao2] == ' ') {
									aux = tabuleirojogo[linha][coluna];
									tabuleirojogo[direcao1][direcao2] = aux;
									tabuleirojogo[linha - 1][coluna] = ' '; // captura a peca do adversario
									tabuleirojogo[linha][coluna] = ' ';
									--pecas_jogador2; // remove a peca do segundo jogador
									informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
									gotoxy(1, 1);
									imprime_tabuleiro(tabuleirojogo);
								}
							}
							else {
								if (tabuleirojogo[linha - 1][coluna] == '^') {
									if (tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') {
										if (tabuleirojogo[direcao1][direcao2] == ' ') {
											aux = tabuleirojogo[linha][coluna];
											tabuleirojogo[direcao1][direcao2] = aux;
											tabuleirojogo[linha - 1][coluna] = ' '; // captura a peca do adversario
											tabuleirojogo[linha][coluna] = ' ';
											--pecas_jogador2; // remove a peca do segundo jogador
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO3;
									}
								}
								else {
									if (tabuleirojogo[linha - 1][coluna] == 'R') {
										if (tabuleirojogo[linha][coluna] == 'F') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha - 1][coluna] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador2;
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
												rei = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
												system("cls");
												textcolor(YELLOW);
												
												putchar('\n');
												printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador2);
												scanf(" %c", &aux_caracter);
												decisaoacabajogo1 = toupper(aux_caracter);
												if (decisaoacabajogo1 == 'S') {
													printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador1);
													break;
												}
												else {
													if (decisaoacabajogo1 == 'N') {
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto INICIO4;
													}
													else {
														printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto DECISAOGANHA1;
													}
												}
											}
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO3;
									}
								}
							}
						}
						else {// decisao 8
							if (aux1 == 2 && aux2 == 2 && direcao1 < linha && direcao2 > coluna) {
								if (tabuleirojogo[linha - 1][coluna + 1] == 'S') {
									if (tabuleirojogo[direcao1][direcao2] == ' ') {
										aux = tabuleirojogo[linha][coluna];
										tabuleirojogo[direcao1][direcao2] = aux;
										tabuleirojogo[linha - 1][coluna + 1] = ' '; // captura a peca do adversario
										tabuleirojogo[linha][coluna] = ' ';
										--pecas_jogador2; // remove a peca do segundo jogador
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
									}
								}
								else {
									if (tabuleirojogo[linha - 1][coluna + 1] == '^') {
										if (tabuleirojogo[linha][coluna] == '*' || tabuleirojogo[linha][coluna] == 'F') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha - 1][coluna + 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador2; // remove a peca do segundo jogador
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO3;
										}
									}
									else {
										if (tabuleirojogo[linha - 1][coluna + 1] == 'R') {
											if (tabuleirojogo[linha][coluna] == 'F') {
												if (tabuleirojogo[direcao1][direcao2] == ' ') {
													aux = tabuleirojogo[linha][coluna];
													tabuleirojogo[direcao1][direcao2] = aux;
													tabuleirojogo[linha - 1][coluna + 1] = ' '; // captura a peca do adversario
													tabuleirojogo[linha][coluna] = ' ';
													--pecas_jogador2;
													informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
													gotoxy(1, 1);
													imprime_tabuleiro(tabuleirojogo);
													system("cls");
													textcolor(YELLOW);
													rei = false;
													DECISAOGANHA1:
													putchar('\n');
													printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador2);
													scanf(" %c", &aux_caracter);
													decisaoacabajogo1 = toupper(aux_caracter);
													if (decisaoacabajogo1 == 'S') {
														printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador1);
														break;
													}
													else {
														if (decisaoacabajogo1 == 'N') {
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto INICIO4;
														}
														else {
															printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto DECISAOGANHA1;
															
														}
													}
												}
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO3;
										}
									}
								}
							}
						}						
						// chaves dos ifs e elses de fora do laço
					

				}
			}else {
				printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
				Sleep(500);
				system("cls");
				informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
				gotoxy(1, 1);
				imprime_tabuleiro(tabuleirojogo);
				goto INICIO3;
			}
			
			
		}else {
			
			if (vezdejogada % 2 == 0) { // jogador dois joga
			INICIO4:
			
				aux1 = 0;
				aux2 = 0;
				printf("Jogador 2 %s escolha uma peca para mover e sua direcao: \n", jogador2);
				printf("linha 1 a 13: ");
				scanf("%u", &linha);
				printf("coluna 1 a 6: ");
				scanf("%u", &coluna);
				printf("Deseja mover a peca para qual direcao? \n");
				printf("linha 1 a 13: ");
				scanf("%u", &direcao1);
				printf("coluna 1 a 6: ");
				scanf("%u", &direcao2);
				char aux;
				
				if (tabuleirojogo[linha][coluna] == 'S' || tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
					if (direcao1 >= linha && direcao2 >= coluna) {
						aux1 = direcao1 - linha;
						aux2 = direcao2 - coluna;
					}
					if (direcao1 >= linha && direcao2 <= coluna) {
						aux1 = direcao1 - linha;
						aux2 = coluna - direcao2;
					}
					if (direcao1 <= linha && direcao2 >= coluna) {
						aux1 = linha - direcao1;
						aux2 = direcao2 - coluna;
					}
					if (direcao1 <= linha && direcao2 <= coluna) {
						aux1 = linha - direcao1;
						aux2 = coluna - direcao2;
					}
					if (aux1 <= 1 && aux2 <= 1) {
						if (tabuleirojogo[direcao1][direcao2] == ' ') {
							aux = tabuleirojogo[linha][coluna]; // escolhe a peça que é para remover
							tabuleirojogo[direcao1][direcao2] = aux; // move a peca que escolheu para a posicao que deseja
							tabuleirojogo[linha][coluna] = ' '; // remove a peça
							imprime_tabuleiro(tabuleirojogo);
							informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
						}
						else {
							printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
							Sleep(500);
							system("cls");
							informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
							gotoxy(1, 1);
							imprime_tabuleiro(tabuleirojogo);
							
							
							goto INICIO4;
						}
					}
					else {
						// DECISAO 1 - SEGUNDO JOGADOR
						if (aux1 == 2 && aux2 == 2 && direcao1 > linha && direcao2 < coluna) {
							if (tabuleirojogo[linha + 1][coluna - 1] == 'C') {
								if (tabuleirojogo[direcao1][direcao2] == ' ') {
									aux = tabuleirojogo[linha][coluna];
									tabuleirojogo[direcao1][direcao2] = aux;
									tabuleirojogo[linha + 1][coluna - 1] = ' '; // captura a peca do adversario
									tabuleirojogo[linha][coluna] = ' ';
									--pecas_jogador1; // remove a peca do segundo jogador
									informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
									gotoxy(1, 1);
									imprime_tabuleiro(tabuleirojogo);
									textcolor(WHITE);
								}
							}
							else {
								if (tabuleirojogo[linha + 1][coluna - 1] == '*') {
									if (tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
										if (tabuleirojogo[direcao1][direcao2] == ' ') {
											aux = tabuleirojogo[linha][coluna];
											tabuleirojogo[direcao1][direcao2] = aux;
											tabuleirojogo[linha + 1][coluna - 1] = ' '; // captura a peca do adversario
											tabuleirojogo[linha][coluna] = ' ';
											--pecas_jogador1; // remove a peca do segundo jogador
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO4;
									}
								}
								else {
									if (tabuleirojogo[linha + 1][coluna - 1] == 'F') {
										if (tabuleirojogo[linha][coluna] == 'R') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha + 1][coluna - 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador1;
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
												fazendeiro = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
												system("cls");
												textcolor(YELLOW);
												DECISAOGANHA2:
												putchar('\n');
												printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador1);
												scanf(" %c", &aux_caracter);
												decisaoacabajogo2 = toupper(aux_caracter);
												if (decisaoacabajogo2 == 'S') {
													printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n");
													break;
												}
												else {
													if (decisaoacabajogo1 == 'N') {
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto INICIO3;
													}
													else {
														printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto DECISAOGANHA2;
													}
												}
											}
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO4;
									}
								}
							}
						}else {
							//DECISAO 2 - SEGUNDO JOGADOR
							if (aux1 == 2 && aux2 == 0 && direcao1 > linha && direcao2 == coluna) {
								if (tabuleirojogo[linha + 1][coluna] == 'C') {
									if (tabuleirojogo[direcao1][direcao2] == ' ') {
										aux = tabuleirojogo[linha][coluna];
										tabuleirojogo[direcao1][direcao2] = aux;
										tabuleirojogo[linha + 1][coluna] = ' '; // captura a peca do adversario
										tabuleirojogo[linha][coluna] = ' ';
										--pecas_jogador1; // remove a peca do segundo jogador
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
									}
								}
								else {
									if (tabuleirojogo[linha + 1][coluna] == '*') {
										if (tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha + 1][coluna] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador1; // remove a peca do segundo jogador
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO4;
										}
									}
									else {
										if (tabuleirojogo[linha + 1][coluna] == 'F') {
											if (tabuleirojogo[linha][coluna] == 'R') {
												if (tabuleirojogo[direcao1][direcao2] == ' ') {
													aux = tabuleirojogo[linha][coluna];
													tabuleirojogo[direcao1][direcao2] = aux;
													tabuleirojogo[linha + 1][coluna] = ' '; // captura a peca do adversario
													tabuleirojogo[linha][coluna] = ' ';
													--pecas_jogador1;
													informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
													gotoxy(1, 1);
													imprime_tabuleiro(tabuleirojogo);
													fazendeiro = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
													system("cls");
													textcolor(YELLOW);
												
													putchar('\n');
													printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador1);
													scanf(" %c", &aux_caracter);
													decisaoacabajogo2 = toupper(aux_caracter);
													if (decisaoacabajogo2 == 'S') {
														printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n",jogador2);
														break;
													}
													else {
														if (decisaoacabajogo1 == 'N') {
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto INICIO3;
														}
														else {
															printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto DECISAOGANHA2;
														}
													}
												}
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO4;
										}
									}
								}
							}// DECISAO3 - SEGUNDO JOGADOR
						}if (aux1 == 2 && aux2 == 2 && direcao1 > linha && direcao2 > coluna) {
							if (tabuleirojogo[linha + 1][coluna + 1] == 'C') {
								if (tabuleirojogo[direcao1][direcao2] == ' ') {
									aux = tabuleirojogo[linha][coluna];
									tabuleirojogo[direcao1][direcao2] = aux;
									tabuleirojogo[linha + 1][coluna + 1] = ' '; // captura a peca do adversario
									tabuleirojogo[linha][coluna] = ' ';
									--pecas_jogador1; // remove a peca do segundo jogador
									informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
									gotoxy(1, 1);
									imprime_tabuleiro(tabuleirojogo);
								}
							}
							else {
								if (tabuleirojogo[linha + 1][coluna + 1] == '*') {
									if (tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
										if (tabuleirojogo[direcao1][direcao2] == ' ') {
											aux = tabuleirojogo[linha][coluna];
											tabuleirojogo[direcao1][direcao2] = aux;
											tabuleirojogo[linha + 1][coluna + 1] = ' '; // captura a peca do adversario
											tabuleirojogo[linha][coluna] = ' ';
											--pecas_jogador1; // remove a peca do segundo jogador
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO4;
									}
								}
								else {
									if (tabuleirojogo[linha + 1][coluna + 1] == 'F') {
										if (tabuleirojogo[linha][coluna] == 'R') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha + 1][coluna + 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador1;
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
												fazendeiro = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
												system("cls");
												textcolor(YELLOW);
											
												putchar('\n');
												printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador1);
												scanf(" %c", &aux_caracter);
												decisaoacabajogo2 = toupper(aux_caracter);
												if (decisaoacabajogo2 == 'S') {
													printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador2);
													break;
												}
												else {
													if (decisaoacabajogo1 == 'N') {
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto INICIO3;
													}
													else {
														printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto DECISAOGANHA2;
													}
												}
											}
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO4;
									}
								}
							}
						}
						else {
							//DECISAO 4 - SEGUNDO JOGADOR
							if (aux1 == 0 && aux2 == 2 && direcao1 == linha && direcao2 < coluna) {
								if (tabuleirojogo[linha][coluna - 1] == 'C') {
									if (tabuleirojogo[direcao1][direcao2] == ' ') {
										aux = tabuleirojogo[linha][coluna];
										tabuleirojogo[direcao1][direcao2] = aux;
										tabuleirojogo[linha][coluna - 1] = ' '; // captura a peca do adversario
										tabuleirojogo[linha][coluna] = ' ';
										--pecas_jogador1; // remove a peca do segundo jogador
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
									}
								}
								else {
									if (tabuleirojogo[linha][coluna-1] == '*') {
										if (tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha][coluna - 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador1; // remove a peca do segundo jogador
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO4;
										}
									}
									else {
										if (tabuleirojogo[linha][coluna - 1] == 'F') {
											if (tabuleirojogo[linha][coluna] == 'R') {
												if (tabuleirojogo[direcao1][direcao2] == ' ') {
													aux = tabuleirojogo[linha][coluna];
													tabuleirojogo[direcao1][direcao2] = aux;
													tabuleirojogo[linha][coluna - 1] = ' '; // captura a peca do adversario
													tabuleirojogo[linha][coluna] = ' ';
													--pecas_jogador1;
													informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
													gotoxy(1, 1);
													imprime_tabuleiro(tabuleirojogo);
													fazendeiro = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
													system("cls");
													textcolor(YELLOW);
												
													putchar('\n');
													printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador1);
													scanf(" %c", &aux_caracter);
													decisaoacabajogo2 = toupper(aux_caracter);
													if (decisaoacabajogo2 == 'S') {
														printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador2);
														break;
													}
													else {
														if (decisaoacabajogo1 == 'N') {
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto INICIO3;
														}
														else {
															printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto DECISAOGANHA2;
														}
													}
												}
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO4;
										}
									}
								}
							}// DECISAO 5 - SEGUNDO JOGADOR
						}if (aux1 == 0 && aux2 == 2 && direcao1 == linha && direcao2 > coluna) {
							if (tabuleirojogo[linha][coluna + 1] == 'C') {
								if (tabuleirojogo[direcao1][direcao2] == ' ') {
									aux = tabuleirojogo[linha][coluna];
									tabuleirojogo[direcao1][direcao2] = aux;
									tabuleirojogo[linha][coluna + 1] = ' '; // captura a peca do adversario
									tabuleirojogo[linha][coluna] = ' ';
									--pecas_jogador1; // remove a peca do segundo jogador
									informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
									gotoxy(1, 1);
									imprime_tabuleiro(tabuleirojogo);
								}
							}
							else {
								if (tabuleirojogo[linha][coluna + 1] == '*') {
									if (tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
										if (tabuleirojogo[direcao1][direcao2] == ' ') {
											aux = tabuleirojogo[linha][coluna];
											tabuleirojogo[direcao1][direcao2] = aux;
											tabuleirojogo[linha][coluna + 1] = ' '; // captura a peca do adversario
											tabuleirojogo[linha][coluna] = ' ';
											--pecas_jogador1; // remove a peca do segundo jogador
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO4;
									}
								}
								else {
									if (tabuleirojogo[linha][coluna + 1] == 'F') {
										if (tabuleirojogo[linha][coluna] == 'R') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha][coluna + 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador1;
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
												fazendeiro = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
												system("cls");
												textcolor(YELLOW);
											
												putchar('\n');
												printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador1);
												scanf(" %c", &aux_caracter);
												decisaoacabajogo2 = toupper(aux_caracter);
												if (decisaoacabajogo2 == 'S') {
													printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador2);
													break;
												}
												else {
													if (decisaoacabajogo1 == 'N') {
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto INICIO3;
													}
													else {
														printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto DECISAOGANHA2;
													}
												}
											}
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO4;
									}
								}
							}
						}
						else {
							// DECISAO 6 - SEGUNDO JOGADOR
							if (aux1 == 2 && aux2 == 2 && direcao1 < linha && direcao2 < coluna) {
								if (tabuleirojogo[linha - 1][coluna - 1] == 'C') {
									if (tabuleirojogo[direcao1][direcao2] == ' ') {
										aux = tabuleirojogo[linha][coluna];
										tabuleirojogo[direcao1][direcao2] = aux;
										tabuleirojogo[linha - 1][coluna - 1] = ' '; // captura a peca do adversario
										tabuleirojogo[linha][coluna] = ' ';
										--pecas_jogador1; // remove a peca do segundo jogador
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
									}
								}
								else {
									if (tabuleirojogo[linha - 1][coluna - 1] == '*') {
										if (tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha - 1][coluna - 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador1; // remove a peca do segundo jogador
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO4;
										}
									}
									else {
										if (tabuleirojogo[linha - 1][coluna - 1] == 'F') {
											if (tabuleirojogo[linha][coluna] == 'R') {
												if (tabuleirojogo[direcao1][direcao2] == ' ') {
													aux = tabuleirojogo[linha][coluna];
													tabuleirojogo[direcao1][direcao2] = aux;
													tabuleirojogo[linha - 1][coluna - 1] = ' '; // captura a peca do adversario
													tabuleirojogo[linha][coluna] = ' ';
													--pecas_jogador1;
													informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
													gotoxy(1, 1);
													imprime_tabuleiro(tabuleirojogo);
													fazendeiro = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
													system("cls");
													textcolor(YELLOW);
												
													putchar('\n');
													printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador1);
													scanf(" %c", &aux_caracter);
													decisaoacabajogo2 = toupper(aux_caracter);
													if (decisaoacabajogo2 == 'S') {
														printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador2);
														break;
													}
													else {
														if (decisaoacabajogo1 == 'N') {
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto INICIO3;
														}
														else {
															printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto DECISAOGANHA2;
														}
													}
												}
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO4;
										}
									}
								}
							}// DECISAO 7 - SEGUNDO JOGADOR
						}if (aux1 == 2 && aux2 == 0 && direcao1 < linha && direcao2 == coluna) {
							if (tabuleirojogo[linha - 1][coluna] == 'C') {
								if (tabuleirojogo[direcao1][direcao2] == ' ') {
									aux = tabuleirojogo[linha][coluna];
									tabuleirojogo[direcao1][direcao2] = aux;
									tabuleirojogo[linha - 1][coluna] = ' '; // captura a peca do adversario
									tabuleirojogo[linha][coluna] = ' ';
									--pecas_jogador1; // remove a peca do segundo jogador
									informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
									gotoxy(1, 1);
									imprime_tabuleiro(tabuleirojogo);
								}
							}
							else {
								if (tabuleirojogo[linha - 1][coluna] == '*') {
									if (tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
										if (tabuleirojogo[direcao1][direcao2] == ' ') {
											aux = tabuleirojogo[linha][coluna];
											tabuleirojogo[direcao1][direcao2] = aux;
											tabuleirojogo[linha - 1][coluna] = ' '; // captura a peca do adversario
											tabuleirojogo[linha][coluna] = ' ';
											--pecas_jogador1; // remove a peca do segundo jogador
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO4;
									}
								}
								else {
									if (tabuleirojogo[linha - 1][coluna] == 'F') {
										if (tabuleirojogo[linha][coluna] == 'R') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha - 1][coluna] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador1;
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
												fazendeiro = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
												system("cls");
												textcolor(YELLOW);
											
												putchar('\n');
												printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador1);
												scanf(" %c", &aux_caracter);
												decisaoacabajogo2 = toupper(aux_caracter);
												if (decisaoacabajogo2 == 'S') {
													printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador2);
													break;
												}
												else {
													if (decisaoacabajogo1 == 'N') {
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto INICIO3;
													}
													else {
														printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
														textcolor(WHITE);
														system("cls");
														informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
														gotoxy(1, 1);
														imprime_tabuleiro(tabuleirojogo);
														goto DECISAOGANHA2;
													}
												}
											}
										}
									}
									else {
										printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
										Sleep(500);
										system("cls");
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
										goto INICIO4;
									}
								}
							}
						}
						else {// DECISAO 8 - SEGUNDO JOGADOR
							if (aux1 == 2 && aux2 == 2 && direcao1 < linha && direcao2 > coluna) {
								if (tabuleirojogo[linha - 1][coluna + 1] == 'C') {
									if (tabuleirojogo[direcao1][direcao2] == ' ') {
										aux = tabuleirojogo[linha][coluna];
										tabuleirojogo[direcao1][direcao2] = aux;
										tabuleirojogo[linha - 1][coluna + 1] = ' '; // captura a peca do adversario
										tabuleirojogo[linha][coluna] = ' ';
										--pecas_jogador1; // remove a peca do segundo jogador
										informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
										gotoxy(1, 1);
										imprime_tabuleiro(tabuleirojogo);
									}
								}
								else {
									if (tabuleirojogo[linha - 1][coluna + 1] == '*') {
										if (tabuleirojogo[linha][coluna] == '^' || tabuleirojogo[linha][coluna] == 'R') {
											if (tabuleirojogo[direcao1][direcao2] == ' ') {
												aux = tabuleirojogo[linha][coluna];
												tabuleirojogo[direcao1][direcao2] = aux;
												tabuleirojogo[linha - 1][coluna + 1] = ' '; // captura a peca do adversario
												tabuleirojogo[linha][coluna] = ' ';
												--pecas_jogador1; // remove a peca do segundo jogador
												informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
												gotoxy(1, 1);
												imprime_tabuleiro(tabuleirojogo);
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO4;
										}
									}
									else {
										if (tabuleirojogo[linha - 1][coluna + 1] == 'F') {
											if (tabuleirojogo[linha][coluna] == 'R') {
												if (tabuleirojogo[direcao1][direcao2] == ' ') {
													aux = tabuleirojogo[linha][coluna];
													tabuleirojogo[direcao1][direcao2] = aux;
													tabuleirojogo[linha - 1][coluna + 1] = ' '; // captura a peca do adversario
													tabuleirojogo[linha][coluna] = ' ';
													--pecas_jogador1;
													informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
													gotoxy(1, 1);
													imprime_tabuleiro(tabuleirojogo);
													fazendeiro = false; // indica que o rei do segundo jogador foi comido, então o jogador opita por desistir ou não do jogo
													system("cls");
													textcolor(YELLOW);
												
													putchar('\n');
													printf("Jogador %s voce perdeu seu rei, deseja continuar ou desistir do jogo agora(S) ou (N)?\n", jogador1);
													scanf(" %c", &aux_caracter);
													decisaoacabajogo2 = toupper(aux_caracter);
													if (decisaoacabajogo2 == 'S') {
														printf("PARABENS JOGADOR %s VOCE GANHOU O JOGO!!!!!!!!!!\n", jogador2);
														break;
													}
													else {
														if (decisaoacabajogo1 == 'N') {
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto INICIO3;
														}
														else {
															printf("RESPOSTA INVALIDA, DIGITE NOVAMENTE UMA RESPOSTA!\n");
															textcolor(WHITE);
															system("cls");
															informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
															gotoxy(1, 1);
															imprime_tabuleiro(tabuleirojogo);
															goto DECISAOGANHA2;
														}
													}
												}
											}
										}
										else {
											printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
											Sleep(500);
											system("cls");
											informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
											gotoxy(1, 1);
											imprime_tabuleiro(tabuleirojogo);
											goto INICIO4;
										}
									}
								}
							}
						}
					}
				}else {
					printf("JOGADA INVALIDA, REPITA A OPERACAO!\n");
					system("cls");
					gotoxy(1, 1);
					imprime_tabuleiro(tabuleirojogo);
					informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
					goto INICIO4;
				}
			}
		}
		system("cls");
		informacoes(&pecas_jogador1, &pecas_jogador2, &jogador1, &jogador2);
		gotoxy(1, 1);
		imprime_tabuleiro(tabuleirojogo);

		++vezdejogada;
	} while (pecas_jogador1 !=0 || pecas_jogador2 != 0); // DECISAO DE PARADA CASO NÃO HAJA MAIS PEÇAS DISPONIVEIS
	textcolor(WHITE);	
}

// DESCRIÇÃO DA FUNCAO INFORMAÇOES

void informacoes(int* pecas1, int* pecas2, char* jogador1, char* jogador2) {
	//informaçoes jogador 1
	textcolor(GREEN);
	gotoxy(40, 2);
	printf("Jogador 1 %s :", jogador1);
	gotoxy(40, 3);
	printf("QTD PECAS = %d", *pecas1);
	gotoxy(40, 4);
	printf("C = Camponeses");
	gotoxy(40, 5);
	printf("* = Filho do Fazendeiro");
	gotoxy(40, 6);
	printf("F = Fazendeiro");
	textcolor(WHITE);
	//informaçoes jogador 2
	textcolor(RED);
	gotoxy(40, 8);
	printf("Jogador 2 %s :", jogador2);
	gotoxy(40, 9);
	printf("QTD PECAS = %d", *pecas2);
	gotoxy(40, 10);
	printf("S = Soldados");
	gotoxy(40, 11);
	printf("^ = Principe");
	gotoxy(40, 12);
	printf("R = Rei");
	textcolor(WHITE);
}
