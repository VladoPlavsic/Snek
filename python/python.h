#pragma once

#include <iostream>

#include "../preprocessor/defines.h"
    
enum class Direction{Left, Right, Up, Down, Unchanged};

struct Node{

    int x;
    int y;
    Node* next;
    Node* previous;
    Direction direction;

    Node(int x, int y, Node* next, Node* previous, Direction direction);
    
    inline void update(int x, int y){this->x = x; this->y = y;}
};

class Snake{

    public:

    private:
        int m_Size = 0;
        int m_MaxX;
        int m_MaxY;
        
        bool m_GG = false;

        bool m_Changed = false;

        Node* m_Head;
        Node* m_Tail;

    public:
        
        Snake(int,int,int,int);
        bool update();
        void changeDirection(Direction direction);
        void eat();
        int score();
        inline int X(){return m_Head->x;}
        inline int Y(){return m_Head->y;}
        inline Node* Head(){return m_Head;}
        inline Direction direction(){return m_Head->direction;}
        inline bool ended(){return m_GG;}

};