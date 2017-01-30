#include <iostream>
#include <dlfcn.h>
#include <cstdlib>
#include "nibbler.hh"

int     argument_check(int ac, char **av)
{
  if (ac != 4)
    {
      std::cerr << "Usage : ./exemple 10 10 <libXXX.so>" << std::endl;
      exit (0);
    }
  else if (av[3][0] == '.' && av[3][1] == '/')
    {
      std::cerr << "Please don't use './' to compile library" << std::endl;
      exit (0);
    }
  return (0);
}

int	create_library(char **av)
{
  int	x = atoi(av[1]);
  int	y = atoi(av[2]);
  std::string library;

  Nibbler*      (*external_creator)(int, int);
  void  *dlhandle;

  library = "./";
  library += av[3];
  dlhandle = dlopen(library.c_str(), RTLD_LAZY);
  if (dlhandle == NULL)
    return (1);
  external_creator = reinterpret_cast<Nibbler* (*)(int, int)>(dlsym(dlhandle, "create_lib"));
  if (external_creator == NULL)
    return (1);
  Nibbler*      bob = external_creator(x, y);

  bob->talk(x, y);
  dlclose (dlhandle);
  return (0);
}

int	main(int ac, char **av)
{
  argument_check(ac, av);
  create_library(av);
  return (0);
}
