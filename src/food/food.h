#pragma once

#include <iostream>

#include "../preprocessor/defines.h"

struct Food{

    int x;
    int y;
    const int maxX;
    const int maxY;

    Food(int, int);

    void next();
};