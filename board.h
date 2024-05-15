#include <fstream>
#include "block.h"

class Board {
public:
    Board() { };
    Board(int boardSize);

    // Accessors
    int getBoardSize();
    Block** getBlockArray();
    int** getBombMap();
    // Mutators
    void setBombMap(int curRow, int curCol, int value);
    void setBlockArray(int curRow, int curCol, int value); 

private:
    int** bombMap;
    Block** blockArray;
    int boardSize;
};

Board::Board(int boardSize) : boardSize(boardSize) {
    blockArray = new Block* [boardSize];
    bombMap = new int* [boardSize];
    /* Your code needs to start here*/
    /* You need to make blockArray, bombMap initialize*/
    for (int i = 0; i < boardSize; i++) {
        blockArray[i] = new Block[boardSize];
        bombMap[i] = new int[boardSize];
        for (int j = 0; j < boardSize; j++) {
            bombMap[i][j] = 0;  // 초기 폭탄 맵을 0으로 초기화
        }
    }
};

int Board::getBoardSize() {
    /* Your code needs to start here*/
    // return the board size
    return boardSize;
}

Block** Board::getBlockArray() {
    /* Your code needs to start here*/
    // return the Block array 
    return blockArray;
}

int** Board::getBombMap() {
    /* Your code needs to start here*/
    // return the bomb map (how bomb damaged on the turn)
    return bombMap;
}

void Board::setBombMap(int curRow, int curCol, int value) {
    /* Your code needs to start here*/
    // change the bombmap values bombMap[curRow][curCol] to value
    if (curRow >= 0 && curRow < boardSize && curCol >= 0 && curCol < boardSize) {
        bombMap[curRow][curCol] = value;
    }
}

void Board::setBlockArray(int curRow, int curCol, int value) {
    /* Your code needs to start here*/
    // change the blockarray values blockArray[curRow][curCol] to value
    if (curRow >= 0 && curRow < boardSize && curCol >= 0 && curCol < boardSize) {
        blockArray[curRow][curCol].setHeight(value);
    }
}