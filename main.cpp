//Snake Game by Cameron Verini
#include <iostream>
#include <conio.h>
#include <ctime>

#include "Snake.h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);

Food food;

void board()
{
    COORD snake_pos=snake.get_pos();
    COORD food_pos = food.get_pos();

    vector<COORD> snake_body = snake.getBody();

    for(int i=0; i<HEIGHT; i++)
    {
        cout << "\t#";
        for(int j=0; j<WIDTH-2; j++)
        {
            //creates graphical borders of the board
            if(i==0 || i==HEIGHT-1) cout << '#';

            //creates graphic for the snake at its coordinate position
            else if(i==snake_pos.Y && j+1 ==snake_pos.X) cout << 'O';

            //creates graphic for food at its position
            else if(i==food_pos.Y && j+1 ==food_pos.X) cout << '*';

            else
            {
                bool isBodyPart = false;
                /*if the snake has a body (excluding its head), then each body part
                will be shown in its coordinate*/
                for(int k = 0; k<snake_body.size()-1; k++)
                {
                    if(i == snake_body[k].Y && j+1 == snake_body[k].X)
                    {
                        cout << 'O';
                        isBodyPart = true;
                        break;
                    }
                }
                //if the coordinate contains no border, snake part, or food, it will be a space
                if(!isBodyPart) cout << ' ';
            }
        }
        cout << "#\n";
    }
}

int main()
{
    srand(time(NULL));
    char cont='y';
    while(cont=='y' || cont=='Y')
    {
        bool game_over = false;
        while(!game_over)
        {
            board();

            if(kbhit())
            {
                switch(getch())
                {
                    //w key changes direction to up, a to left, s to down, d to right
                    case 'w':snake.change_dir('u'); break;
                    case 'a':snake.change_dir('l'); break;
                    case 's':snake.change_dir('d'); break;
                    case 'd':snake.change_dir('r'); break;
                }
            }

            if(snake.eaten(food.get_pos()))
            {
                /*if the snake is in the same coordinate as food, it will increase in length
                and another food will spawn*/
                food.gen_food();
                snake.grow();
            }

            snake.move_snake();

            //if the snake touches the border, the game will end and the final score will display
            if(snake.collided(WIDTH, HEIGHT)) game_over = true;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        }
        cout<< "\n\n\n\n\n\n\n\n\n\n\n\t#\t\t    GAME OVER\n\t#\t\t    SCORE: "
            << snake.getLength()*10-10 << "\n\n\t#\t\t    Retry? Y/N\n\t#\t\t\t";
        cin >> cont;
        while(cont != 'y' && cont != 'Y' && cont !='n' && cont !='N')
        {
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t    Invalid input: Retry? Y/N\n\t\t\t\t";
            cin >> cont;
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        snake = Snake({WIDTH/2, HEIGHT/2}, 1);
        food = Food();
    }
}
