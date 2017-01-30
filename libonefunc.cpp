#include "libone.hh"

WINDOW *window_create(int height, int width)
{
  WINDOW *my_win;

  my_win = newwin(height, width, 0,0);
  box(my_win, 0 , 0);
  wrefresh(my_win);
  return (my_win);
}

void    Libone::food(WINDOW *my_win)
{
  int   randx;
  int   randy;
  int   i;

  randx = rand()%user_x - 5;
  randy = rand()%user_y - 5;
  foods.x = randx;
  foods.y = randy;
  wmove(my_win, foods.y, foods.x);
  waddch(my_win,'*');
  eat(my_win);
  wrefresh(my_win);
}

void    Libone::eat(WINDOW *my_win)
{ 
  limit(my_win);
  if (my_snake[0].pos_x == foods.x && my_snake[0].pos_y == foods.y)
    {
      food(my_win);
      results += 10;
      my_snake.insert(my_snake.end(), snakebody(my_snake[0].pos_x+1, my_snake[0].pos_y+1));
      move(user_x / 2, user_y + 1);
      printw("Votre score : %d", results);
      refresh();
    }
}

void    Libone::view_snake(WINDOW *my_win)
{
  int   i = 0;

  while (i < my_snake.size())
    {
      wmove(my_win, my_snake[i].pos_y,my_snake[i].pos_x);
      waddch(my_win, 'x');
      i++;
    }
  wrefresh(my_win);
}

void    Libone::start()
{
  WINDOW *my_win;
  int   i = 0;
  const char    *str = "Loading ...";

  my_win = window_create(gety, getx);
  wmove(my_win, gety / 2, getx / 2);
  wprintw(my_win, "%s", str);
  wrefresh(my_win);
  sleep(2);
  wmove(my_win, gety / 2, getx / 2);
  while (str[i] != '\0')
    {
      waddch(my_win, ' ');
      wrefresh(my_win);
      i++;
    }
  wborder(my_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wrefresh(my_win);
  delwin(my_win);
}
