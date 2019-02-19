/*
** ia_player.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 24 15:15:41 2017 John Doe
** Last update Sat Feb 25 21:13:47 2017 John Doe
*/

#include "my.h"

int	algorithm(int stick_on_all_map, int match_max)
{
  int	p;
  int	match_to_left;
  int	nb_match_to_remove;

  match_to_left = 100000;
  p = 200;
  if (stick_on_all_map == 1)
    return (1);
  while (match_to_left >= stick_on_all_map)
    {
      match_to_left = (match_max + 1) * p + 1;
      p--;
    }
  nb_match_to_remove = stick_on_all_map - match_to_left;
  return (nb_match_to_remove);
}

int	find_the_line(char **map, int  stick_remove, int version)
{
  int	i;
  int	z;
  int	save;

  i = 0;
  z = 0;
  if (version == 2)
    {
      while (map[i] != NULL)
	{
	  if (z < number_of_stick(map[i]))
	    {
	      z = number_of_stick(map[i]);
	      save = i;
	    }
	  i++;
	}
      return (save);
    }
  while (map[i] != NULL && (number_of_stick(map[i]) < stick_remove))
    i++;
  if (map[i] == NULL)
    return (150);
  else
    return (i);
}

char	**ia_player(char **map, int match)
{
  int	match_remove;
  int	l;

  my_putstr("\nAI's turn...\n");
  match_remove = algorithm(number_of_all_stick(map), match);
  if ((l = find_the_line(map, match_remove, 1)) == 150 || match_remove > match)
    {
      match_remove = 1;
      l = find_the_line(map, match_remove, 2);
    }
  shorcut3_ia(l, match_remove, map);
  return (map);
}
