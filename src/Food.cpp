#include "Food.h"

Food::Food()
{
    gen_food();
}

//spawns food in random position within the board
void Food::gen_food()
{
    position.X=rand()%(WIDTH-3)+1;
    position.Y=rand()%(HEIGHT-3)+1;
}

COORD Food::get_pos(){return position;}
