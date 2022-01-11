#include <stdio.h>

void printBoard();
char board[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '}; //create board
int playerTurn = 1, gameOver = 0; //default player 1 turn, gameOver 0=in progress, 1 = cat's game, 2 = normal win
char mark; // 'X' or 'O'

int main()
{
   
   printf("Welcome to Tic-Tac-Toe\n");
   printf("======================\n");

    while (gameOver==0)
    {
        printBoard(playerTurn);  //player 1 turn
        
        
        if(gameOver>0) //if X player finished game, no need for O player's turn
        {
            printBoard(playerTurn);
            break;
        }
        
        playerTurn++;
        printBoard(playerTurn);  //player 2 turn
        playerTurn--;
        
    }
    return 0;
}

void checkWin(char playerMark)
{
    if (board[0][0]==playerMark && board[0][1]==playerMark && board[0][2]==playerMark)  //win top 3 straight horizontal
    {
        printf("'%c' Player Wins!\n", playerMark);
        gameOver=2;
    }
    if (board[0][0]==playerMark && board[1][0]==playerMark && board[2][0]==playerMark)  //win left 3 straight vertical
    {
        printf("'%c' Player Wins!\n", playerMark);
        gameOver=2;
    }
    if (board[0][0]==playerMark && board[1][1]==playerMark && board[2][2]==playerMark)  //win diagnol left down to right
    {
        printf("'%c' Player Wins!\n", playerMark);
        gameOver=2;
    }
    
    if (board[0][1]==playerMark && board[1][1]==playerMark && board[2][1]==playerMark)  //win middle 3 straight vertical 
    {
        printf("'%c' Player Wins!\n", playerMark);
        gameOver=2;
    }
    
    if (board[2][0]==playerMark && board[2][1]==playerMark && board[2][2]==playerMark)  //win bottom 3 straight horizontal
    {
        printf("'%c' Player Wins!\n", playerMark);
        gameOver=2;
    }
    
    if (board[0][2]==playerMark && board[1][2]==playerMark && board[2][2]==playerMark)  //win right 3 straight vertical
    {
        printf("'%c' Player Wins!\n", playerMark);
        gameOver=2;
    }
    
    if (board[0][2]==playerMark && board[1][1]==playerMark && board[2][0]==playerMark)  //win diagnol right down to left
    {
        printf("'%c' Player Wins!\n", playerMark);
        gameOver=2;
    }
    
    if (board[1][0]==playerMark && board[1][1]==playerMark && board[1][2]==playerMark)  //win middle 3 straight horizontal
    {
        printf("'%c' Player Wins!\n", playerMark);
        gameOver=2;
    }
    
    
 }

void checkCatsGame(char playerMark) //checks board positions for all possibilities of a cat's game
{
    if (board[0][0]!=' ' && board[0][1]!=' ' && board[0][2]!=' ' && board[1][0]!=' '&& board[1][1]!=' '&&board[1][2]!=' '&&board[2][0]!=' '&&board[2][1]!=' '&&board[2][2]!=' ') 
    {
        printf("\nCat's Game!\n");
        gameOver=1;
    }
    
     
    
    
}



void printBoard(int playerNum)
{
    int row, column;
    
    if (playerNum==1)
    mark = 'X';
        
    
    else if (playerNum==2)
    mark = 'O';
    
    
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    
    if (gameOver==0) // if game is still running, ask for next move
    {
    printf("\nPlayer %i turn '%c' \n", playerNum, mark);    
    printf("Which Row would you like?\n");
    scanf("%i", &row);
    printf("Which Column would you like?\n");
    scanf("%i", &column);
    
    if (row==0&&column==0)
    board[0][0]=mark;
    if (row==0&&column==1)
    board[0][1]=mark;
    if (row==0&&column==2)
    board[0][2]=mark;
    if (row==1&&column==0)
    board[1][0]=mark;
    if (row==1&&column==1)
    board[1][1]=mark;
    if (row==1&&column==2)
    board[1][2]=mark;
    if (row==2&&column==0)
    board[2][0]=mark;
    if (row==2&&column==1)
    board[2][1]=mark;
    if (row==2&&column==2)
    board[2][2]=mark;
    
    
    checkWin(mark);
    checkCatsGame(mark);
    }
     
}

