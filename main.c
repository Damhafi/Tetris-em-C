#include "tetris.h"
#include "display.h"


//Função principal

int main(){
    char matrix[ROWS][COLUMNS];
    int posI, posJ;
    int keypressed=0;

    //posicao inicial do personagem
    posI = 1;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    while(keypressed != ESC){
        gotoxy(0,0);

        matrix[posI][posJ] = '@';

        printMatrix(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posI < ROWS-1) posI++;        

        //lendo tecla
        keypressed=0;
        if(kbhit()) keypressed = getch();
        if(keypressed==ARROWS) keypressed = getch();


        switch(keypressed){
            case TECLA_A:
            case LEFT: 
                if(posJ > 0) posJ--;//seta da esquerda A
                break;
            case TECLA_D:
            case RIGHT: 
                if(posJ < (COLUMNS - 1)) posJ++;//seta da direita D
            break;
        }

    }

    system("pause");

    return 0;
}
// . . .