/*
References to look at and create a to do list
https://github.com/kevingregor/Checkers
http://www.cs.columbia.edu/~devans/TIC/AB.html
https://towardsdatascience.com/genetic-programming-for-ai-heuristic-optimization-9d7fdb115ee1
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

/*A structure to represent each position on the board*/
typedef struct Cell{
  char cellValue;
  bool isKing;
}Cell;

typedef struct Coord{
  int sourceRow;
  int sourceCol;
  int destRow;
  int destCol;
}Coord;

//Function prototypes
Cell** createCheckersBoard();
void printBoard(Cell** board);
int evaluationFunction(Cell** board, char player);


Coord** getCapturingMoves(Cell** board, char player)
{
  //
}

Coord** getValidMoves(Cell** board, char player)
{
  /*
    first get all capturing moves
    if capturing moves exist, then return them
    else
    get all valid moves and return them
  */
}



/*Function to evaluate the board score in perspective of
the maximizing player. We provide weight to each piece and then take difference
of weighted pieces as a basic evaluation score*/
int evaluationFunction(Cell** board, char player){
    return 0;
}

/*Function to create checkers board. Here we represent men as 'b' or
'w' w.r.t the player. A king is represented in upper case form*/

Cell** createCheckersBoard(){
  Cell** board = (Cell**)malloc(8*sizeof(Cell*));
  for(int i = 0; i < 8 ; i++){
    board[i] = (Cell*)malloc(8*sizeof(Cell));
  }
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(i < 3 && (i+j) % 2 == 1){
        board[i][j].cellValue = 'w';
        board[i][j].isKing = false;
      }
      else if(i > 4 && (i+j) % 2 == 1){
        board[i][j].cellValue = 'b';
        board[i][j].isKing = false;
      }
      else{
        board[i][j].cellValue = ' ';
        board[i][j].isKing = false;
      }
    }
  }
  return board;
}

/* Function to print board state. We pad symbols appropriately to make it
easier to play and visualize moves*/
void printBoard(Cell** board){
  printf("  ");
  for(int i = 0; i < 8; i++){
    printf("%d ",i+1);
  }
  printf("\n");
  printf("  ");
  for(int i = 0; i < 8; i++){
    printf("- ");
  }
  printf("\n");
  for(int i = 0; i < 8; i++){
    printf("%d|",i+1);
    for(int j = 0; j < 8; j++){
      printf("%c ", board[i][j].cellValue);
      if(j == 7){
        printf("|");
      }
    }
    printf("\n");
  }
  printf("  ");
  for(int i = 0; i < 8; i++){
    printf("- ");
  }
  printf("\n");
  printf("  ");
  for(int i = 0; i < 8; i++){
    printf("%d ",i+1);
  }
  printf("\n");
}

void main(){
  Cell** board = createCheckersBoard();
  printBoard(board);
}


/*

algorithm for minimax with alpha beta pruning

coord keeps info about the move made to print it
 alphabeta(board,depth,alpha,beta,maxplayer,move)
{

  //base case
  if reached the depth or winning move reached:
    score = evaluate()
    return score

  if maxplayer:
    value = INT_MIN
    for each move:
      create a new board and apply that move
       value = max(value, alphabeta(newboard,depth - 1,alpha,beta,false))
      if value > alpha :
        alpha = value
      free newboard
    return value
  else :
    value = INT_MAX
    for each move:
      create a new board and apply that move
       value = max(value, alphabeta(newboard,depth - 1,alpha,beta,true))
      if value < beta :
        beta = value
      free newboard
    return value
}

main(){
if player = computer
  call alphabeta with the current board state
else
  wait for player to make a move and update
}

*/
