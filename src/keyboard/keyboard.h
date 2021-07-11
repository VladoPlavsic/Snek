#pragma once

#include <iostream>
#include "../python/python.h"
#include <stdio.h>

struct Keyboard{

    private:
        inline static Direction dir = Direction::Left;
        bool listen = false;

    public:
        void startListening();
        void stop();
        inline Direction direction(){return dir;}
};