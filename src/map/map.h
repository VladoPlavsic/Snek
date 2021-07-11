#pragma once
#include <iostream>
#include "../food/food.h"
#include "../python/python.h"

class Map{

    const int Width;
    const int Height;

    public:
        Map(int,int);

        bool DrawMap(Food*, Snake*);

};