/*
** matchstick.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Feb 21 18:19:26 2017 John Doe
** Last update Mon Feb 27 14:22:27 2017 John Doe
*/

#include "my.h"

int	matchstick(char **av)
{
  char	**map;
  int	line;
  int	nb_stick;
  int	win;

  line = my_getnbr(av[1]);
  nb_stick =  my_getnbr(av[2]);
  if ((map = put_stick_map(line)) == NULL)
    return (84);
  while (1)
    {
      if ((map = human_player(map, line, nb_stick)) == NULL)
	return (0);
      print_map(map);
      if ((win = victory(map, 2)) != 0)
	return (win);
      map = ia_player(map, nb_stick);
      print_map(map);
      if ((win = victory(map, 1)) != 0)
	return (win);
    }
  free(map);
  return (0);
}
