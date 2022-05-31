#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

using namespace std;

class Snake
{
    private:
        COORD position;
        int length;
        int velocity;
        char direction;
        vector<COORD> body;

    public:
        Snake(COORD pos, int vel);
        void change_dir(char dir);
        void move_snake();
        COORD get_pos();

        bool eaten(COORD food_pos);

        void grow();

        bool collided(int w, int h);

        int getLength();

        vector<COORD> getBody();
};
#endif



