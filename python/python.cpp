#include "python.h"

Snake::Snake(int x, int y,int maxX, int maxY): m_MaxX(maxX), m_MaxY(maxY)
{
    m_Head = new Node(x, y, nullptr, nullptr, Direction::Down);
    m_Tail = m_Head;
}

Node::Node(int x, int y, Node* next, Node* previous, Direction direction): x(x), y(y), next(next), previous(previous), direction(direction){}

bool Snake::update(){

    Node* temp = m_Head;

    bool flag = false;

    while(temp != nullptr){


        if(temp != m_Head){
            if(m_Head->x == temp->x && m_Head->y == temp->y){
                m_GG = true;
            }
        }

        if(temp != m_Head && !flag){
            if(temp->previous->direction == Direction::Down || temp->previous->direction == Direction::Up){
                if(temp->previous->x == temp->x){
                    temp->direction = temp->previous->direction;
                }
            }
            else{
                if(temp->previous->y == temp->y){
                    temp->direction = temp->previous->direction;
                }
            }
        }

        switch (temp->direction)
        {
        case Direction::Right:
            if(temp->x + HORIZONTAL_INC_DEC > m_MaxX)
                temp->x = 0;
            temp->x += HORIZONTAL_INC_DEC;
            break;
        case Direction::Left:
            if(temp->x - HORIZONTAL_INC_DEC < 0)
                temp->x = m_MaxX;
            temp->x -= HORIZONTAL_INC_DEC;
            break;
        case Direction::Up:
            if(temp->y - VERTICAL_INC_DEC < 0)
                temp->y = m_MaxY;
            temp->y -= VERTICAL_INC_DEC;
            break;
        case Direction::Down:
            if(temp->y + VERTICAL_INC_DEC > m_MaxY)
                temp->y = 0;
            temp->y += VERTICAL_INC_DEC;
            break;
        default:
            break;
        }

        temp = temp->next;
    }

    delete temp;

    if(m_Changed){
        m_Changed = false;
        return true;
    }
    return false;
}

void Snake::changeDirection(Direction direction){

    Direction old = m_Head->direction;

    m_Head->direction = direction;
}

void Snake::eat(){

    Node* node = nullptr;

    switch (m_Tail->direction)
    {
    case Direction::Up:
        node = new Node(m_Tail->x, m_Tail->y + 1, nullptr, m_Tail, m_Tail->direction);
        m_Tail->next = node;
        m_Tail = node;
        break;
    
    case Direction::Down:
        node = new Node(m_Tail->x, m_Tail->y - 1, nullptr, m_Tail, m_Tail->direction);
        m_Tail->next = node;
        m_Tail = node;
        break;


    case Direction::Left:
        node = new Node(m_Tail->x + 2, m_Tail->y, nullptr, m_Tail, m_Tail->direction);
        m_Tail->next = node;
        m_Tail = node;
        break;


    case Direction::Right:
        node = new Node(m_Tail->x - 2, m_Tail->y, nullptr, m_Tail, m_Tail->direction);
        m_Tail->next = node;
        m_Tail = node;
        break;
    default:
        break;
    }

    m_Size++;
    m_Changed = true;
}

int Snake::score(){
    return m_Size;
}