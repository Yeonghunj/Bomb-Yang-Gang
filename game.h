#include <cstdio>
#include <iostream>

#include "player.h"
#include "board.h"

using namespace std;

class Game {
public:
    Game(int gameMode); 
    void turnPass();
    void printBoard();
    void printBombMap();
    bool move(int newRow, int newCol);
    void bomb(int bombType, int depth);
    bool checkEndCondition();

    // Mutators (setters)
    void setTurn(int nextTurn);
    void setBoard(int gameMode);

    // Accessors (getters)
    int getTurn();
    int getWinner();
    Board getBoard();
    Player getYang();
    Player getGang();

private:
    const int MAX_TURN = 20;
    int gameMode;
    int turn;
    Board mainGameBoard;
    Player Yang;
    Player Gang;
    int winner;
};

Game::Game(int gameMode) : gameMode(gameMode) {
    Game::setTurn(0);
    Game::setBoard(gameMode);
    // Set the player initialization
    Yang = Player(0,0);
    Gang = Player(mainGameBoard.getBoardSize()-1, mainGameBoard.getBoardSize()-1);
    return;
}

int Game::getTurn() { 
    return turn;
}

Player Game::getGang() {
    return Gang;
}

Player Game::getYang() {
    return Yang;
}

Board Game::getBoard() {
    return mainGameBoard;
}

int Game::getWinner() {
    return winner;
}

void Game::turnPass() {
    setTurn(turn + 1);
    return; 
}

void Game::printBoard() {
    /* Change this code as you need */
    /* Do not break empty blocks for foramt or endl */

    for(int i=0;i<mainGameBoard.getBoardSize();i++){
        for(int j=0;j<mainGameBoard.getBoardSize();j++){
            if (Yang.getRow() == i && Yang.getCol() == j){
                cout << 'Y' << " ";
            }
            else if (Gang.getRow() == i && Gang.getCol() == j){
                cout << 'G' << " ";
            }
            else {
                cout << mainGameBoard.getBlockArray()[i][j].getHeight() << " ";
            }
        }
        cout << endl;
    }
}

void Game::setTurn(int nextTurn){
    // Set the turn functions
    turn = nextTurn;
    return; 
}

void Game::setBoard(int gameMode){
    // Game mode dependent
    if (gameMode == 1){
        mainGameBoard = Board(9);

    }
    else if(gameMode == 2){
        mainGameBoard = Board(15);
    }

    else if(gameMode == 3){
        mainGameBoard = Board(21);
    }

    else if(gameMode == 4){
        mainGameBoard = Board(27);
    }

    else {
        cout << "Game mode not expected number input";
    }    
    return; 
}

bool Game::move(int newRow, int newCol){
    /* Your code needs to start here*/
    /*
    Movement
    Yang: Chess knight
    Gang: Directly Around (8-direction)

    Please refer to the slide for each movement

    if newRow, newCol that user gives are not available, return false
    else, move the Player and set to the newRow, newCol. Then return true
    
    */
    Player &activePlayer = turn % 2 == 0 ? Yang : Gang;

    if (newRow < 0 || newRow >= mainGameBoard.getBoardSize() || newCol < 0 || newCol >= mainGameBoard.getBoardSize() || mainGameBoard.getBlockArray()[newRow][newCol].getHeight() == 0) {
        return false;
    }
    if ((newRow == Yang.getRow() && newCol == Yang.getCol()) || (newRow == Gang.getRow() && newCol == Gang.getCol())) {
        return false;
    }

    int currentRow = activePlayer.getRow();
    int currentCol = activePlayer.getCol();

    bool validMove = false;
    if (turn % 2 == 0) { // Yang's turn
        int rowDiff = abs(newRow - currentRow);
        int colDiff = abs(newCol - currentCol);
        validMove = (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
    } else { // Gang's turn
        int rowDiff = abs(newRow - currentRow);
        int colDiff = abs(newCol - currentCol);
        validMove = rowDiff <= 1 && colDiff <= 1 && !(rowDiff == 0 && colDiff == 0);
    }

    if (!validMove) {
        return false;
    }

    activePlayer.setRow(newRow);
    activePlayer.setCol(newCol);
    return true;
}

bool Game::checkEndCondition(){
    /* Your code needs to start here*/
    /* 
    You need to check conditions to decide whether the game ended or not

    1) A player reached the ground(0)
    2) A player cannot move anymore
    3) The turn reached MAX_TURN(20)

    If the both of the player reach to the end condition
    We need to compare the score

    If the game ended we need to set winner at here
    -1: Draw
    0: Yang win
    1: Gang win
    */
    bool yangCanMove = false;
    bool gangCanMove = false;

    // Yang의 나이트 이동 가능성 검사
    int yangRow = Yang.getRow();
    int yangCol = Yang.getCol();
    int knightMoves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    for (int i = 0; i < 8; i++) {
        int newRow = yangRow + knightMoves[i][0];
        int newCol = yangCol + knightMoves[i][1];
        if (newRow >= 0 && newRow < mainGameBoard.getBoardSize() && newCol >= 0 && newCol < mainGameBoard.getBoardSize() &&
            mainGameBoard.getBlockArray()[newRow][newCol].getHeight() != 0 &&
            !(newRow == Gang.getRow() && newCol == Gang.getCol())) {
            yangCanMove = true;
            break;
        }
    }

    // Gang의 8방향 이동 가능성 검사
    int gangRow = Gang.getRow();
    int gangCol = Gang.getCol();
    int surroundingMoves[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int i = 0; i < 8; i++) {
        int newRow = gangRow + surroundingMoves[i][0];
        int newCol = gangCol + surroundingMoves[i][1];
        if (newRow >= 0 && newRow < mainGameBoard.getBoardSize() && newCol >= 0 && newCol < mainGameBoard.getBoardSize() &&
            mainGameBoard.getBlockArray()[newRow][newCol].getHeight() != 0 &&
            !(newRow == Yang.getRow() && newCol == Yang.getCol())) {
            gangCanMove = true;
            break;
        }
    }
}

void Game::bomb(int bombType, int depth){
    /* Your code needs to start here*/
    /* Implement each bomb type and modify the board accordingly*/
    /*
    bomb type 0: square 
    bomb type 1: Recursively calling left, top, right, down
    bomb type 2: Recurisvely calling but diagonal
    bomb type 3: Recursively calling left, top, right, down but, damage 1

    Please refer to the slide for each bomb type

    After bomb function, mainBoard should be modified accordingly
    Also, the score should be updated after bomb damage
    
    If depth <= 0 just return 
    (Do nothing. It will be regarded as passing the turn)
    */

}

void Game::printBombMap(){
    /* Change this code as you need */
    /* Do not break empty blocks for foramt or endl */
    int curBoardSize = mainGameBoard.getBoardSize();
    for(int i=0;i<curBoardSize; i++){
        for(int j=0;j<curBoardSize; j++){
            if (mainGameBoard.getBombMap()[i][j] > 0){
                cout << mainGameBoard.getBombMap()[i][j] << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << "          " ;

        for(int j=0;j<curBoardSize; j++){
            if (Yang.getRow() == i && Yang.getCol() == j){
                cout << 'Y' << " ";
            }
            else if (Gang.getRow() == i && Gang.getCol() == j){
                cout << 'G' << " ";
            }
            else {
                cout << mainGameBoard.getBlockArray()[i][j].getHeight() << " ";
            }
        }
        cout << endl;
    }
    return;
}


