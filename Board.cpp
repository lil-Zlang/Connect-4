#include "Board.h"

using namespace std;

Board::Board(){
    moveCount=0;
    status= Full;
    game_over = 0;
    for (int r = 0; r < 8; r++){
        for (int c = 0; c <= 7; c++){
            this->boardptr[r][c] = 0;
        }
    }
}

int Board::winCheck(){
    if (this->moveCount == 42){ //if the board is full, automatic tie
        return game_over = 3;
    }
    for (int r = 0; r < 8; r++){ //column win
        for (int c = 0; c <= 7; c++){
            if (this->boardptr[r][c] == 1 && this->boardptr[r][c+1] == 1 && this->boardptr[r][c+2] == 1 && this->boardptr[r][c+3] == 1){
                this->game_over = 1;
            }
            if (this->boardptr[r][c] == 2 && this->boardptr[r][c+1] == 2 && this->boardptr[r][c+2] == 2 && this->boardptr[r][c+3] == 2){
                this->game_over = 2;
            }
        }
    }
    
    for (int r = 0; r < 4; r++){ //row win
        for (int c = 0; c <= 7; c++){
            if (this->boardptr[r][c] == 1 && this->boardptr[r+1][c] == 1 && this->boardptr[r+2][c] == 1 && this->boardptr[r+3][c] == 1){
                this->game_over = 1;
            }
            if (this->boardptr[r][c] == 2 && this->boardptr[r+1][c] == 2 && this->boardptr[r+2][c] == 2 && this->boardptr[r+3][c] == 2){
                this->game_over = 2;
            }
        }
    }
    
    for (int r=4; r < 11; r++){ //left to right diagonal win
        for (int c=0; c <= 4; c++){
            if (this->boardptr[r][c] == 1 && this->boardptr[r-1][c+1] == 1 && this->boardptr[r-2][c+2] == 1 && this->boardptr[r-3][c+3] == 1){
                this->game_over = 1;
            }
            if (this->boardptr[r][c] == 2 && this->boardptr[r-1][c+1] == 2 && this->boardptr[r-2][c+2] == 2 && this->boardptr[r-3][c+3] == 2){
                this->game_over = 2;
            }
        }
    }
    
    for (int r=0; r < 5; r++){ //right to left diagonal win
        for (int c=0; c <= 4; c++){
            if (this->boardptr[r][c] == 1 && this->boardptr[r+1][c+1] == 1 && this->boardptr[r+2][c+2] == 1 && this->boardptr[r+3][c+3] == 1){
                this->game_over = 1;
            }
            if (this->boardptr[r][c] == 2 && this->boardptr[r+1][c+1] == 2 && this->boardptr[r+2][c+2] == 2 && this->boardptr[r+3][c+3] == 2){
                this->game_over = 2;
            }
        }
    }
    status = Full;
    return game_over;
}

Point2d Board::getMove(int move){
    for(int r = 0; r <= 7; r++){
        if(this->boardptr[move][r] == 0) {
            return Point2d(move, r-6);
        }
    }
    return Point2d(10,10);
}

void Board::placePiece(int move,char symbol){
    if (boardptr[move][5]==1||boardptr[move][5]==2){ //if column full, asks for input again
        cout<< "Column full. Please select another column."<<endl;
        status = Full;
        return;
    }
    else{
    status = Empty;
    if (symbol == 'X'){
        for(int r = 0; r <= 7 ; r++){
            if(this->boardptr[move][r] == 0){
                this->boardptr[move][r] = 1;
                return;
            }
        }
    }
    else {
        for(int r = 0; r <= 7 ; r++){
            if(this->boardptr[move][r] == 0){
                this->boardptr[move][r] = 2;
                return;
            }
        }
    }
    return;
        
    }
}
int Board::getStatus(){
    return status;
}

int Board::moveup(){
    return moveCount++;
}





