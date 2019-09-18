#include "tetris.h"

//Funções

void init(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] = ' ';
        }
    }
}


void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;
    
    //parte de cima
    printf("\t\t\t");
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");


    for(i=0; i<ROWS; i++){
        printf("\t\t\t*");
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }
        printf("*\n");
    }
    //parte de baixo
    printf("\t\t\t");
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");
}