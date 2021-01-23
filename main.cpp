#include "map/map.h"
#include "timer/timer.h"
#include "python/python.h"
#include "keyboard/keyboard.h"
#include <thread>



struct Args{
    inline static Map* map;
    inline static Snake* snake;
    inline static Food* food;
    inline static Keyboard* listener;
    inline static Timer* timer;
};

bool update(){

    if(!Args::map->DrawMap(Args::food, Args::snake))
        return false;


    if(Args::snake->direction() == Direction::Left || Args::snake->direction() == Direction::Right)
    { 
        if(Args::listener->direction() == Direction::Up || Args::listener->direction() == Direction::Down){
            Direction direction = Args::listener->direction();
            Args::snake->changeDirection(Args::listener->direction());
        }
    }
    else{
        if(Args::listener->direction() == Direction::Left || Args::listener->direction() == Direction::Right){
            Direction direction = Args::listener->direction();
            Args::snake->changeDirection(Args::listener->direction());
        }
    }

    if(Args::snake->update())
        Args::timer++;

    return true;
}


int main(){

    Map* map = new Map(SIZE_X, SIZE_Y);
    Snake* snake = new Snake(1, 1, SIZE_X, SIZE_Y);
    Food* food = new Food(SIZE_X, SIZE_Y);
    Keyboard* listener = new Keyboard();
    Timer* timer = new Timer();


    Args::map = map;
    Args::snake = snake;
    Args::food = food;
    Args::listener = listener;
    Args::timer = timer;



    std::thread keyListener([=]{
        listener->startListening();
    });

    std::thread gameLoop([=]{
        timer->setInterval(update, SPEED);
    });

    gameLoop.join();
    keyListener.join();

    return 1;

}


//BUGS
/*
3. Find optimal refresh rate for pretty rendering (< 200 but > 100)
*/
