#include "food.h"

//Generates random number between left and right limits (excluding) [optional mod - what mod should it be]
int randomInt(int left, int right, int mod = 1){

    int random = rand() %  right + left;

    while(random % mod != 0)
        random = rand() % right + left;

    return random;
}

Food::Food(int maxX, int maxY) : maxX(maxX), maxY(maxY){ 
    x = randomInt(0, maxX, HORIZONTAL_INC_DEC); 
    y = randomInt(0, maxY, VERTICAL_INC_DEC);
}

void Food::next(){

    x = randomInt(0, maxX, HORIZONTAL_INC_DEC);
    y = randomInt(0, maxY, VERTICAL_INC_DEC);
}
