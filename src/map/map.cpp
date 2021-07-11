#include "map.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

Map::Map(int width, int height) : Width(width), Height(height){}


bool checkAny(Snake* snake, int x, int y){


    
    Node* head = snake->Head();

    while(1){
        if(head->x == x && head->y == y){
            head = nullptr;
            delete head;
            return true;
        }
        head = head->next;
        if(head == nullptr)
            break;
    }

    delete head;
    return false;

}

bool Map::DrawMap(Food* food, Snake* snake){

    std::system(CLEAR);

    if(snake->ended())
        std::cout << std::endl << "GG YOU LOST! YOU SCORED: " << snake->score() << std::endl; 

    for (int i = 0; i < Width; i++){
        std::cout << "-";
    }

    if(!snake->ended())
        std::cout << "       SCORE: " << snake->score();

    std::cout << std::endl;

    for(int i = 0; i < Height; i++){
        for(int j = 0; j < Width; j++){
            if(snake->X() == food->x && snake->Y() == food->y){
                snake->eat();
                food->next();
            }
            if(checkAny(snake,j,i)){
                std::cout << SNAKE_SYMBOL;
            }
            else if(i == food->y && j == food->x){
                std::cout << FOOD_SYMBOL;
            }
            else if(j == 0 || j == (Width - 1)){
                std::cout << "|";

                //Coordinate pringing
                /*
                if(j == Width - 1){
                    if(i == 2){
                        std::cout << "      SNAKE: (" << snake->X() << "," << snake->Y() << ")";
                    }
                    if(i == 4){
                        std::cout << "       FOOD: (" << food->x << "," << food->y << ")"; 
                    }
                }
                */
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < Width; i++){
        std::cout << "-";
    }

    std::cout << std::endl;

    if(snake->ended())
        return false;
    return true;
}
