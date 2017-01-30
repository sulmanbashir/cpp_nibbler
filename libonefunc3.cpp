#include "libone.hh"

void    Libone::create_snake()
{
  int   i = 0;

  while (i != 4)
    {
      my_snake.push_back(snakebody((user_x / 2) + i, (user_y / 2)));
      i++;
    }
}
