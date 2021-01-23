#pragma once

#include <thread>

class Timer{
    bool clear = false;

    int m_Interval;

    public:
        void setInterval(bool (*function)(), int interval);
        void stop();

        //Increes speed = decrese sleep time
        inline void operator ++ (){ m_Interval -= 20; }

};