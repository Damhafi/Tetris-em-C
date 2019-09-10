#include "tetris.h"
#include "display.h"

 /*Parte principal do progrma, responsavel por iniciar e
 chamar as funções auxiliares*/

int main(){
    char matrix[ROWS][COLUMNS];
    int posI, posJ;
    

    posI= 1; //linha
    posJ= COLUMNS/2;

    //inicializando a atriz
    init (matrix); 

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system ("cls");


    while (1) {
        gotoxy(0,0);
        
        matrix[posI][posJ]= '@';
        printMatrix(matrix);
        matrix[posI][posJ]= ' ';
        
        

    } 

    system("pause");
    return 0;
}


