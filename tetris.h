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
#define TECLA_a 97
#define TECLA_A 65
#define TECLA_d 100   
#define TECLA_D 68
#define TECLA_ESPACO 32

//tipo de orientação
#define ORIENTACAO_UP 1
#define ORIENTACAO_LEFT 2
#define ORIENTACAO_DOWN 3
#define ORIENTACAO_RIGHT 4

//tipo de peça
#define TIPO_L 1
#define TIPO_L_R 2          //L reverso
#define TIPO_T 3
#define TIPO_Z 4 
#define TIPO_Z_R 5          //Z reverso
#define TIPO_O 6            //Quadrado
#define TIPO_I 7

//Config Layout 
#define PIXEL 219
#define EMPTY 32

//Estrutura padrão de componentes
typedef struct{
    int i, j;
    int tipo, orientacao;
    int width, height; //Largura // Altura
}Bloco;

//Inicializa a matriz principal com os espaços vazios
void init(char matrix[ROWS][COLUMNS]);

//Mostra o conteúdo principal da matriz na tela
void printMatrix(char matrix[ROWS][COLUMNS]);


void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo);