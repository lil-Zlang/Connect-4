#ifndef Board_h
#define Board_h

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include "Point2d.h"
enum BoardStates{ //To keep the columns within capacity
    Empty = 0,
    Full = 1,
};
class Board{
public:
    int boardptr[8][7];
    int game_over;
    int moveCount;
    int status;
    Board();
    int winCheck();
    Point2d getMove(int move);
    void placePiece(int move,char symbol);
    int getStatus();
    int moveup();
};

#endif /* Board_h */
