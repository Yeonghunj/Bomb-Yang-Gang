#include <iostream>

#include "game.h"

using std::endl;
using std::cin;
using std::cout;

///// MAIN FUNCTIONS /////
int main(){
    cout << "Welcome to BOMB-YANG-GANG Game" << endl; 
    cout << "Please insert the game mode that you want to play" << endl;

    int game_mode;
    cout << "Choose the game mode: " << endl;
    cout << "1. Easy Mode (9 X 9 Board)" << endl;
    cout << "2. Normal Mode (15 X 15 Board)" << endl;
    cout << "3. Hard Mode (21 X 21 Board)" << endl;
    cout << "4. Extreme Mode (27 X 27 Board)" << endl ;

    cin >> game_mode;

    switch(game_mode){
        case 1:
            cout << "Easy mode selected!!!" <<endl;
            break;
        case 2:
            cout << "Normal mode selected!!!" <<endl;
            break;
        case 3:
            cout << "Hard mode selected!!!" << endl;
            break;
        case 4:
            cout << "Extreme mode selected!!!" << endl;
            break;
        default:
            cout << "None of the mode selected" <<endl;
            cout << "Default, Easy mode selected!!!" << endl;
            game_mode = 1;
            break;
    }

    // Main game should be initialize with dependent for game_mode
    Game mainGame = Game(game_mode);
    mainGame.printBoard();
    cout << endl;
    cout << endl;

    // Main Game Loop started
    while(!mainGame.checkEndCondition()){
        int rowYang = mainGame.getYang().getRow();
        int colYang = mainGame.getYang().getCol();
        int rowGang = mainGame.getGang().getRow();
        int colGang = mainGame.getGang().getCol();

        cout << "Current Turn : " << mainGame.getTurn() << endl;
        cout << "Player Yang location : " << rowYang << " " << colYang <<endl;
        cout << "Player Gang location : " << rowGang << " " << colGang <<endl;
        cout << "Player Yang height : " << mainGame.getBoard().getBlockArray()[rowYang][colYang].getHeight() << endl;
        cout << "Player Gang height : " << mainGame.getBoard().getBlockArray()[rowGang][colGang].getHeight() << endl;
        cout << "Yang : " << mainGame.getYang().getScore() << "pts  Gang: " << mainGame.getGang().getScore() <<"pts" << endl;

        if (mainGame.getTurn() %2 == 0) cout << "Yang Turn!" <<endl;
        else cout << "Gang Turn!" << endl;

        int moveRow, moveCol;
        cout << "<<< Current Board Status >>>" << endl;
        mainGame.printBoard();
        cout << endl << endl;

        cout << "<<< Moving Phase >>>" << endl;

        cin >> moveRow;
        cin >> moveCol;

        int rep = 0;
        while(!mainGame.move(moveRow, moveCol)){
            rep += 1 ;
            cout << "Moving is unavailable You need to check it one more time" << endl << endl;
            cin >> moveRow;
            cin >> moveCol;
            if (rep >= 10) return 0;
        }
        
        cout << "<<< After Moving... >>>" << endl << endl;
        mainGame.printBoard();
        cout << endl << endl;

        int bombType, bombDepth;
        cout << "<<< BOMB Phase >>>" << endl;
        cout << "Set bomb type : ";
        cin >> bombType;
        cout << "Set bomb depth (Current limit : "<< (mainGame.getTurn()) <<"): ";
        cin >> bombDepth;
        rep = 0;
        while(bombDepth > (mainGame.getTurn())){
            cout << "Check depth one more time" << endl;
            cout << "Set bomb depth (Current limit : "<< (mainGame.getTurn()) <<"): ";
            cin >> bombDepth;
            if (rep >= 10) return 0;
        }

        mainGame.bomb(bombType, bombDepth);
        cout << "BOMB MAP!!!" << endl << endl;
        mainGame.printBombMap();
        cout << endl << endl;
        mainGame.turnPass();
        
    }

    cout << "Game Ended due to end condition. Great Job!!!" << endl;
    cout << "Yang : " << mainGame.getYang().getScore() << "pts  Gang: " << mainGame.getGang().getScore() <<"pts" << endl;
    cout << "Player Yang location : " << mainGame.getYang().getRow() << " " << mainGame.getYang().getCol() <<endl;
    cout << "Player Gang location : " << mainGame.getGang().getRow() << " " << mainGame.getGang().getCol() <<endl;
    cout << "Yang Height : " << mainGame.getBoard().getBlockArray()[mainGame.getYang().getRow()][mainGame.getYang().getCol()].getHeight() << endl;
    cout << "Gang Height : " << mainGame.getBoard().getBlockArray()[mainGame.getGang().getRow()][mainGame.getGang().getCol()].getHeight() << endl;

    if(mainGame.getWinner() == -1) cout << "Draw!!!" << endl;
    else if(mainGame.getWinner() == 0) cout << "Winner Yang!!!" <<endl;
    else if(mainGame.getWinner() == 1) cout << "Winner Gang!!!" << endl;
    return 0;
}