#ifndef Player_h
#define Player_h
#include <iostream>
#include <random>
#include <stdio.h>
#include "Board.h"
using namespace std;
class Player {
private:
    string name;
    int playernum;
    int score;
    char symbol;
    int movecount;
    int currentmove;
public:
    Player();
    ~Player();
    void Nameask(int); /*name*/
    void Charask(int); /* o or x otherwise error*/
    void GiveName();
    void GivePiece(char);
    char GetChar();
    string GetName();
    int GamesWon(int);
    int move;
    int MakeMove(); /*1-7*/
    int getMoveConut();
    int AIMove(Board* b);
};
#endif /* Player_hpp */
