#include <stdlib.h>  
#include <stdio.h>   
#include <stdbool.h> 

#include <assert.h>  

#define CELL_MAX (4 * 4 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[4][4]){
    int cell = 0;

    print_sep(4);
    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(4);
    }
}

char get_winner(char board[4][4]){
    char winner = '-';
    int i,j,n=3,r;

//Función de las filas
for (r=0;r<4;r++){
 for(i=0;i<4;i++){
    if (board[r][i]==board[r][i+1] && board[r][i]==board[i][r+2]&& board[r][i]==board[i][r+3]){
           winner = board[r][i] ;}
        }
    }

//Función de las columnas
for (r=0;r<4;r++){
 for(j=0;j<4;j++){
    if (board[j][r]==board[j+1][r] && board[j][r]==board[j+2][r]&& board[j][r]==board[j+3][r]){
           winner = board[j][r] ;}
        }
}
//Diagonal principal
for (i=0;i<4;i++){
  if (board[i][i]==board[i+1][i+1] && board[i][i]==board[i+2][i+2] && board[i+2][i+2]==board[i+3][i+3]) {
        winner = board[i][i];
  }
}
//La otra diagonal
for(i=0;i<4;i++){
  if (board[i][n]==board[i+1][n-1] && board[i+1][n-1]==board[i+2][n-2] && board[i+2][n-2]==board[i+3][n-3]) {
        winner = board[i][n];
  }
}

    return winner;
}

bool has_free_cell(char board[4][4]){
    bool free_cell=false;
    int i,j;
    for (i=0;i<4;i++){
        for(j=0;j<4;j++){
                free_cell= free_cell || board[i][j]=='-';
        }
    }

    return free_cell;
}


int main(void){
    printf("TicTacToe Completo de 4x4 \n");

    char board[4][4] = {
        { '-', '-', '-', '-', },
        { '-', '-', '-', '-', },
        { '-', '-', '-', '-', },
        { '-', '-', '-', '-', }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 4;
            int colum = cell % 4;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}