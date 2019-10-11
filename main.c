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
        
        drawBar(matrix, tijolo, PIXEL); 
        
        //mostra a matriz na tela
        printMatrix(matrix);

        //faz a posicao anterior do @se apagada
        drawBar(matrix, tijolo, EMPTY);
           

            /*case ORIENTACAO_LEFT:
               if(tijolo.i+3 >= 0) matrix[tijolo.i][tijolo.j+3] = EMPTY;
               if(tijolo.i+2 >= 0) matrix[tijolo.i][tijolo.j+2] = EMPTY;
               if(tijolo.i+1 >= 0) matrix[tijolo.i][tijolo.j+1] = EMPTY;
               matrix[tijolo.i][tijolo.j] = EMPTY;
            break;*/

        if(tijolo.i < ROWS-1) tijolo.i++;        

        //lendo tecla
        keypressed=0;
        if(kbhit()) keypressed = getch();
        if(keypressed==ARROWS) keypressed = getch();


        switch(keypressed){
            case TECLA_A:
            case TECLA_a:
            case LEFT: 
                if(tijolo.j-3 > 0) tijolo.j++;//seta da esquerda A
                break;
            case TECLA_d:
            case TECLA_D:
            case RIGHT: 
                if(tijolo.j < (COLUMNS - 1)) tijolo.j++;//seta da direita D
            break;
            case TECLA_ESPACO:
                if(tijolo.orientacao==ORIENTACAO_LEFT)
                    tijolo.orientacao = ORIENTACAO_UP;
                else 
                    tijolo.orientacao++;
        }       
    
    }
    system("pause");
    return 0;
}