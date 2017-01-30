#ifndef __KOALA_HH__
# define __KOALA_HH__

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <vector>
#include "nibbler.hh"

struct	snakebody
{
  int	pos_x;
  int	pos_y;
  snakebody(int x, int y);
};

struct	my_food
{
  int	x;
  int	y;
};

class	Libone : public Nibbler
{
  int	user_x;
  int	user_y;
  int	gety;
  int	getx;
  int	results;
  int	directions;
  void	food(WINDOW *my_win);
  void	my_move(WINDOW *my_win);
  void	view_snake(WINDOW *my_win);
  void	eat(WINDOW *my_win);
  void	heavygo(WINDOW *my_win);
  void	check_size(int x, int y, int maxX, int maxY);
  void	getdirection(WINDOW *my_win);
  void	limit(WINDOW *my_win);
  void  game_over(WINDOW *my_win);
  void	create_snake();
  void	start();
  my_food	foods;
  std::vector<snakebody> my_snake;
	
	public:
		Libone(const int &x, const int &y);
		~Libone();
		virtual void talk(int x, int y);
};

WINDOW *window_create(int height, int width);

#endif
