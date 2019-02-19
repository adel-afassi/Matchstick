/*
** remove_stick_bis.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Feb 21 17:06:44 2017 John Doe
** Last update Fri Feb 24 15:19:13 2017 John Doe
*/

#include "my.h"

int	number_of_stick(char *line)
{
  int	i;
  int	nb_stick;

  i = 0;
  nb_stick = 0;
  while (line[i] != '\0')
    {
      if (line[i] == '|')
	nb_stick++;
      i++;
    }
  return (nb_stick);
}

int	number_of_all_stick(char **map)
{
  int	line;
  int	col;
  int	nb_stick;

  line = 0;
  col = 0;
  nb_stick = 0;
  while (map[line] != NULL)
    {
      while (map[line][col] != '\0')
	{
	  if (map[line][col] == '|')
	    nb_stick++;
	  col++;
	}
      col = 0;
      line++;
    }
  return (nb_stick);
}
