#include "libone.hh"

snakebody::snakebody(int x, int y)
{
  pos_x = x;
  pos_y = y;
}

Libone::Libone(const int &x, const int &y)
{
  WINDOW *my_win;

  user_x = x;
  user_y = y;
  initscr();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  curs_set(0);
  getmaxyx(stdscr, gety, getx);
  check_size(user_x, user_y, getx, gety);
  refresh();
  start();
  my_win = window_create(user_y, user_x);
  wrefresh(my_win);
  create_snake();
  view_snake(my_win);
  directions = 'l';
  wrefresh(my_win);
  nodelay(my_win, true);
  food(my_win);
  heavygo(my_win);
}

Libone::~Libone()
{
  endwin();
}

void	Libone::talk(int x, int y)
{

}

extern "C"
{
  Nibbler*	create_lib(const int x, const int y)
  {
    return new Libone(x, y);
  }
}
