#include <fstream>
#include <iostream>

class Block {
public:
    Block();
    // Accessors
    int getHeight();
    // Mutator
    void setHeight(int afterOperation);

private:
    int height;
};

Block::Block() {
    height = 9;
}

int Block::getHeight() {
    /* Your code needs to start here*/

}

void Block::setHeight(int afterOperation) {
    height = afterOperation;
    if (height < 0) {
        height = 0;
    }
    return; 
}
