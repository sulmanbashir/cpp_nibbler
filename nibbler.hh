#ifndef NIBBLER_HH__
# define NIBBLER_HH__

class	Nibbler
{
	public:
  virtual void talk(int x, int y) = 0;
};

int     argument_check(int ac, char **av);

#endif
