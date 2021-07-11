#include "timer.h"

void Timer::setInterval(bool (*function)(), int interval){
    this->clear = false;
    
    m_Interval = interval;

    while(true){
        if(this->clear) return;

        std::this_thread::sleep_for(std::chrono::milliseconds(m_Interval));
        if(this->clear) return;

        if(!(*function)())
            return;
    }
}

void Timer::stop(){
    this->clear = true;
}
