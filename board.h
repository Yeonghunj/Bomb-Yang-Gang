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

};

int Board::getBoardSize() {
    /* Your code needs to start here*/
    // return the board size

}

Block** Board::getBlockArray() {
    /* Your code needs to start here*/
    // return the Block array 

}

int** Board::getBombMap() {
    /* Your code needs to start here*/
    // return the bomb map (how bomb damaged on the turn)

}

void Board::setBombMap(int curRow, int curCol, int value) {
    /* Your code needs to start here*/
    // change the bombmap values bombMap[curRow][curCol] to value

}

void Board::setBlockArray(int curRow, int curCol, int value) {
    /* Your code needs to start here*/
    // change the blockarray values blockArray[curRow][curCol] to value

}
