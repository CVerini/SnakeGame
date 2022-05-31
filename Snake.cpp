#include "Snake.h"

#define WIDTH 50
#define HEIGHT 25

Snake::Snake(COORD pos, int vel)
{
    position = pos;
    velocity=vel;
    length=1;
    direction='n';

    body.push_back(pos);
}

int Snake::getLength()
{
    return length;
}

void Snake::change_dir(char dir) {direction=dir;}

void Snake::move_snake()
{
    switch(direction)
    {
        //different cases cause the snake to change the velocity's direction
        case 'u': position.Y -= velocity; break;
        case 'd': position.Y += velocity; break;
        case 'l': position.X -= velocity; break;
        case 'r': position.X += velocity; break;
    }
    //creates a body part at the end of the snake
    body.push_back(position);
    //deletes body parts that would result in the snake being too long as it moves
    if(body.size() > length) body.erase(body.begin());
}

COORD Snake::get_pos() {return position;}

vector<COORD> Snake::getBody() {return body;}

bool Snake::eaten(COORD food_pos)
{
    //if the positions of the snake and the food are the same, the snake has eaten the food
    if(food_pos.X == position.X && food_pos.Y == position.Y) return true;
        else return false;
}

void Snake::grow(){length++;}

bool Snake::collided(int w, int h)
{
    //if the snake has touched the border, then it has collided
    if(position.X < 1 || position.X > w-2 || position.Y < 1 || position.Y > h-2) return true;
    //if the snake has touched one of its body parts, then it has collided
    for(int i=0; i<length-1; i++)
    {
        if(position.X == body[i].X && position.Y == body[i].Y) return true;
    }
    return false;
}
