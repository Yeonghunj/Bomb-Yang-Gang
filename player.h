class Player {
public:
    Player(){};
    Player(int initRow, int initCol);

    // Accessors
    int getRow();
    int getCol();
    int getScore();
    // Mutators
    void setRow(int newRow);
    void setCol(int newCol);
    void setScore(int newScore);

private:
    int curRow;
    int curCol;
    int score;
};

// Player Constructor
Player::Player(int initRow, int initCol) : curRow(initRow), curCol(initCol), score(0) {
}

int Player::getRow() {
    /* Your code needs to start here*/

}

int Player::getCol() {
    /* Your code needs to start here*/

}

int Player::getScore() {
    /* Your code needs to start here*/

}

void Player::setRow(int newRow) {
    /* Your code needs to start here*/

}

void Player::setCol(int newCol) {
    /* Your code needs to start here*/

}

void Player::setScore(int newScore) {
    /* Your code needs to start here*/

}
