#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* Configuração das dimensões da
 matriz pricipal do jogo */
#define COLUMNS 60
#define ROWS 25
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_A 97
#define TECLA_D 100


//Assinaturas

//Inicializa a matriz principal com os espaços vazios
void init(char matrix[ROWS][COLUMNS]);
//Mostra o conteúdo principal da matriz na tela
void printMatrix(char matrix[ROWS][COLUMNS]);