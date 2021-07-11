#include "keyboard.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <conio.h>
char getInput(){
    return getch()
}
#else
#include <termios.h>
#include <unistd.h>
char getInput(){
    struct termios oldSettings, newSettings;

    tcgetattr( fileno( stdin ), &oldSettings );
    newSettings = oldSettings;
    newSettings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr( fileno( stdin ), TCSANOW, &newSettings );    

    fd_set set;
    struct timeval tv;

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    FD_ZERO( &set );
    FD_SET( fileno( stdin ), &set );

    int res = select( fileno( stdin )+1, &set, NULL, NULL, &tv );

    if( res > 0 )
    {
        char c;
        read( fileno( stdin ), &c, 1 );
        return c;
    }
    else if( res < 0 )
    {
        perror( "select error" );
        return 0;
    }
    else
    {
    }   
    tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
    return 0;
}
#endif

void Keyboard::startListening(){

    listen = true;
    
    char key = ' ';
    
    while(listen){
            key = getInput();
            switch (tolower(key))
            {
            case 'a':
                dir = Direction::Left;
                break;
            case 's':
                dir = Direction::Down;
                break;
            case 'd':
                dir = Direction::Right;
                break;
            case 'w':
                dir = Direction::Up;
                break;
            default:
                break;
            }
        }
}

void Keyboard::stop(){
    listen = false;
}