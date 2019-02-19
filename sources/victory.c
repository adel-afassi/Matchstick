/*
** victory.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Feb 23 00:05:57 2017 John Doe
** Last update Thu Feb 23 00:24:58 2017 John Doe
*/

#include "my.h"

int	all_stick(char **map)
{
  int	i;
  int	nb_stick;
  int	z;

  z = 0;
  i = 0;
  nb_stick = 0;
  while (map[z] != NULL)
    {
      while (map[z][i] != '\0')
	{
	  if (map[z][i++] == '|')
	    nb_stick++;
	}
      i = 0;
      z++;
    }
  return (nb_stick);
}

int	victory(char **map, int winner)
{
  int	sticks;

  sticks = all_stick(map);
  if (winner == 1)
    {
      if (sticks == 0)
	{
	  my_putstr("I lost...  snif...  but I'll get you next time!!\n");
	  return (1);
	}
    }
  if (winner == 2)
    {
      if (sticks == 0)
	{
	  my_putstr("You lost, too bad...\n");
	  return (2);
	}
    }
  return (0);
}
