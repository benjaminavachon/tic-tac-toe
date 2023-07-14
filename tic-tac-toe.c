#include <stdio.h>
#include <stdlib.h>

//function declarations
void printBoard(int board[][3]);
bool isValidMove(int board[][3], int row, int col);
void makeMove(int board[][3],int row, int col, int player);
bool hasWon(int board[][3]);
void resetBoard(int board[][3]);
bool isTie(int board[][3]);


int main(){
    int board[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int player = 1;
    int row;
    int col;
    int playAgain = 1;

    while(playAgain != 0){
        if(hasWon(board)){
            printBoard(board);
            if(player == 2){
                player = 1;
            }else{
                player = 2;
            }
            printf("Player %d has won!\nPlay again?(0 for no, 1 for yes)\n",player);
            scanf("%d",&playAgain);
            if(playAgain != 0){
                resetBoard(board);
                player = 1;
            }
        }else if(isTie(board)){
            printBoard(board);
            printf("Tie game!\nPlay again?(0 for no, 1 for yes)\n");
            scanf("%d",&playAgain);
            if(playAgain != 0){
                resetBoard(board);
                player = 1;
            }
        }else{
            printBoard(board);
            printf("Player %d's turn.\nEnter Row:",player);
            scanf("%d",&row);
            printf("Enter Col:");
            scanf("%d",&col);
            if(isValidMove(board,row,col)){
                makeMove(board,row,col,player);
                if(player == 1){
                    player = 2;
                }else{
                    player = 1;
                }
            }
        }

        system("clear");
    }

    return 0;
}

void printBoard(int board[][3]){
    int i,j;
    for(i = 0;i<3;i++){
        printf(" ");
        for(j = 0; j<3; j++){
            if(j == 2){
                printf("%d",board[i][j]);
            }else{
                printf("%d | ",board[i][j]);
            }
        }
        printf("\n");
        if(i != 2){
            printf("-----------\n");
        }
        
    }
}

bool isValidMove(int board[][3], int row, int col){
    return board[row][col] == 0;
}

void makeMove(int board[][3], int row, int col, int player){
    board[row][col] = player;
}

bool hasWon(int board[][3]){
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != 0){
        return true;
    }
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != 0){
        return true;
    }
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != 0){
        return true;
    }

    if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != 0){
        return true;
    }
    if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != 0){
        return true;
    }
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != 0){
        return true;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0){
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0){
        return true;
    }

    return false;
}

void resetBoard(int board[][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3;j++){
            board[i][j] = 0;
        }
    }
}

bool isTie(int board[][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(board[i][j] == 0){
                return false;
            }
        }
    }

    return true;
}