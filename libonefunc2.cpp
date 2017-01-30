#include "libone.hh"

void    Libone::my_move(WINDOW *my_win)
{
  getdirection(my_win);
  nodelay(my_win, true);
  keypad(my_win, true);
  wmove(my_win, my_snake[my_snake.size()-1].pos_y, my_snake[my_snake.size()-1].pos_x);
  waddch(my_win, ' ');
  wrefresh(my_win);
  my_snake.pop_back();
  if (directions == 'l')
    my_snake.insert(my_snake.begin(),snakebody(my_snake[0].pos_x-1,my_snake[0].pos_y));
  else if(directions  == 'r')
    my_snake.insert(my_snake.begin(),snakebody(my_snake[0].pos_x+1,my_snake[0].pos_y));
  else if(directions == 'u')
    my_snake.insert(my_snake.begin(),snakebody(my_snake[0].pos_x,my_snake[0].pos_y-1));
  else if(directions == 'd')
    my_snake.insert(my_snake.begin(),snakebody(my_snake[0].pos_x,my_snake[0].pos_y+1));
  wmove(my_win, my_snake[0].pos_y,my_snake[0].pos_x);
  waddch(my_win, 'x');
  wrefresh(my_win);
}

void	Libone::getdirection(WINDOW *my_win)
{
  int   ch = wgetch(my_win);

  if (ch == KEY_LEFT)
    directions = 'l';
  else if (ch == KEY_RIGHT)
    directions = 'r';
  else if (ch == KEY_UP)
    directions = 'u';
  else if (ch == KEY_DOWN)
    directions = 'd';
  else if (ch == 27)
    {
      delwin(my_win);
      refresh();
      endwin();
      exit (0);
    }
}

void	Libone::heavygo(WINDOW *my_win)
{
  while (42)
    {
      my_move(my_win);
      eat(my_win);
      usleep(110000);
    }
}

void    Libone::game_over(WINDOW *my_win)
{
  wmove(my_win, user_x / 2, user_y / 2);
  wprintw(my_win, "Game over");
  wrefresh(my_win);
  sleep(4);
  delwin(my_win);
  refresh();
  endwin();
  exit (0);
}

void    Libone::limit(WINDOW *my_win)
{
  int   i = 1;

  while (i != my_snake.size())
    {
      if (my_snake[0].pos_x == my_snake[i].pos_x &&
          my_snake[0].pos_y == my_snake[i].pos_y)
        game_over(my_win);
      i++;
    }
  if(my_snake[0].pos_x== 0 || my_snake[0].pos_x== user_x-1
     || my_snake[0].pos_y == 0 || my_snake[0].pos_y == user_y - 2)
    game_over(my_win);
}
