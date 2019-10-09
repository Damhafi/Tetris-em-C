#include "tetris.h"
#include "display.h"
#define DEBUG 1


//Função principal

int main(){
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed=0;

    //posicao inicial do personagem
    tijolo.i = 0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.orientacao = ORIENTACAO_LEFT;
    tijolo.width = 1;
    tijolo.height = 4;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    while(keypressed != ESC){
        gotoxy(0,0);

        #if DEBUG == 1
            printf("@ = (%d, %d)\n",tijolo.i,tijolo.j);
        #endif

        //posiciona @ no meio da tela
        switch(tijolo.orientacao){
            case ORIENTACAO_UP:
                if(tijolo.i-3 >= 0) matrix[tijolo.i-3][tijolo.j] = PIXEL;
                if(tijolo.i-2 >= 0) matrix[tijolo.i-2][tijolo.j] = PIXEL;
                if(tijolo.i-1 >= 0) matrix[tijolo.i-1][tijolo.j] = PIXEL;
                matrix[tijolo.i][tijolo.j] = PIXEL;
            break;
                if(tijolo.i >= 0) matrix[tijolo.i-3][tijolo.j+3] = PIXEL;
                if(tijolo.i >= 0) matrix[tijolo.i-2][tijolo.j+2] = PIXEL;
                if(tijolo.i >= 0) matrix[tijolo.i-1][tijolo.j+1] = PIXEL;
                matrix[tijolo.i][tijolo.j] = PIXEL;

            case ORIENTACAO_LEFT:
            break;
        }
        //mostra a matriz na tela
        printMatrix(matrix);

        //faz a posicao anterior do @se apagada
        switch(tijolo.orientacao){
            case ORIENTACAO_UP:
                if(tijolo.i-3 >= 0) matrix[tijolo.i-3][tijolo.j] = EMPTY;
                if(tijolo.i-2 >= 0) matrix[tijolo.i-2][tijolo.j] = EMPTY;
                if(tijolo.i-1 >= 0) matrix[tijolo.i-1][tijolo.j] = EMPTY;
                matrix[tijolo.i][tijolo.j] = EMPTY;
            break;

            case ORIENTACAO_LEFT:
            break;

        }if(tijolo.i < ROWS-1) tijolo.i++;        

        //lendo tecla
        keypressed=0;
        if(kbhit()) keypressed = getch();
        if(keypressed==ARROWS) keypressed = getch();


        switch(keypressed){
            case TECLA_A:
            case LEFT: 
                if(tijolo.j > 0) tijolo.j--;//seta da esquerda A
                break;
            case TECLA_D:
            case RIGHT: 
                if(tijolo.j < (COLUMNS - 1)) tijolo.j++;//seta da direita D
            break;
        }

    }

    system("pause");

    return 0;
}