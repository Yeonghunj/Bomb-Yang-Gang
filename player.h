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
    return curRow;
}

int Player::getCol() {
    /* Your code needs to start here*/
    return curCol;
}

int Player::getScore() {
    /* Your code needs to start here*/
    return score;
}

void Player::setRow(int newRow) {
    /* Your code needs to start here*/
    curRow=newRow;
}

void Player::setCol(int newCol) {
    /* Your code needs to start here*/
    curCol=newCol;
}

void Player::setScore(int newScore) {
    /* Your code needs to start here*/
    score=newScore;
}
