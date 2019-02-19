/*
** print_screen.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 20 10:44:07 2017 John Doe
** Last update Sat Feb 25 20:43:28 2017 John Doe
*/

#include "my.h"

int	main(int ac, char **av)
{
  int	line;
  int	match;
  int	z;

  if (ac != 3)
    {
      my_putstr("ARGUMENT ERROR\n");
      return (84);
    }
  line = my_getnbr(av[1]);
  match = my_getnbr(av[2]);
  if (line < 1 || line > 100 || match <= 0)
    {
      my_putstr("INVALID ARGUMENT\n");
      return (84);
    }
  z = matchstick(av);
  return (z);
}
