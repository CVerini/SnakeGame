#ifndef FOOD_H
#define FOOD_H

#include <Windows.h>
#include <cstdlib>

#define WIDTH 50
#define HEIGHT 25

class Food
{
    private:
        COORD position;

    public:
        Food();
        void gen_food();
        COORD get_pos();
};

#endif // FOOD_H
