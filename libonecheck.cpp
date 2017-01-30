#include "libone.hh"

void    Libone::check_size(int x, int y, int maxX, int maxY)
{
  refresh();
  endwin();
  if (x > maxX || x < 50)
    {
      std::cout << "Please maximise your windows." << std::endl;
      std::cout << "And Play again with appropriate size" << std::endl;
      std::cout << "Notice: the height size will be under 50 and 190!" << std::endl;
      exit (0);
    }
  else if (y > maxY)
    {
      std::cout << "Please maximise your windows." << std::endl;
      std::cout << "And Play again with appropriate size" << std::endl;
      std::cout << "Notice: the width size will be under 20 and 50!" << std::endl;
      exit (0);
    }
}
